#pragma once
#include "Entity.h"
#include "GameObject.h"
#include "Layer.h"

namespace Luna
{
	class Scene : public Entity
	{
	public:
		Scene();
		~Scene();

		virtual void Initialize();
		virtual void Update();
		virtual void LateUpdate();
		virtual void Render(HDC hdc);

		virtual void OnEnter();
		virtual void OnExit();

		void AddGameObject(GameObject* gameObj, const enums::eLayerTpye type);
		Layer* GetLayer(const enums::eLayerTpye type) { return mLayers[(UINT)type]; }

	private:
		void CreateLayers();

	private:
		std::vector<Layer*> mLayers;
	};
}
