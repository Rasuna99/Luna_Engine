#pragma once
#include "Entity.h"
#include "GameObject.h"

namespace Luna
{
	class Scene : public Entity
	{
	public:
		Scene();
		~Scene();

		void Initialize();
		void Update();
		void LateUpdate();
		void Render(HDC hdc);

	private:
		std::vector<GameObject*> mGameObjects;
	};
}
