#include "Scene.h"

namespace Luna
{
	Luna::Scene::Scene()
		: mLayers{}
	{
		mLayers.resize((UINT)enums::eLayerTpye::Max);
		for (size_t i = 0; i < (UINT)enums::eLayerTpye::Max; i++)
		{
			mLayers[i] = new Layer;
		}
	}

	Scene::~Scene()
	{
		for (auto& layer : mLayers)
		{
			delete layer;
			layer = nullptr;
		}
	}

	void Scene::Initialize()
	{
		for (auto layer : mLayers)
		{
			if (layer == nullptr)
				continue;

			layer->Initialize();
		}
	}

	void Scene::Update()
	{
		for (auto layer : mLayers)
		{
			if (layer == nullptr)
				continue;

			layer->Update();
		}
	}

	void Scene::LateUpdate()
	{
		for (auto layer : mLayers)
		{
			if (layer == nullptr)
				continue;

			layer->LateUpdate();
		}
	}

	void Scene::Render(HDC hdc)
	{
		for (auto layer : mLayers)
		{
			if (layer == nullptr)
				continue;

			layer->Render(hdc);
		}
	}
	void Scene::Destroy()
	{
		for (Layer* layer : mLayers)
		{
			if (layer == nullptr)
				continue;

			layer->Destroy();
		}
	}

	void Scene::OnEnter()
	{
	}
	void Scene::OnExit()
	{
	}
	void Scene::AddGameObject(GameObject* gameObj, const enums::eLayerTpye type)
	{
		mLayers[(UINT)type]->AddGameObject(gameObj);
	}
	void Scene::CreateLayers()
	{
		mLayers.resize((UINT)enums::eLayerTpye::Max);
		for (size_t i = 0; i < (UINT)enums::eLayerTpye::Max; i++)
		{
			mLayers[i] = new Layer();
		}
	}
}