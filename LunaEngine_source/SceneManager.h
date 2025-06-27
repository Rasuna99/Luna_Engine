#pragma once
#include "Scene.h"

namespace Luna
{
	class SceneManager
	{
	public:
		template <typename T>
		static void CreateScene(const std::wstring& name)
		{
			T* scene = new T();
			scene->SetNamee(name);
			scene->Initialize();

			mScene.insert(std::make_pair(name, scene));
		}

		static void Initialize();
		static void Update();
		static void LateUpdate();
		static void Render(HDC hdc);

	private:
		static std::map<const std::wstring, Scene*> mScene;
		static Scene* mActiveScene;
	};
}
