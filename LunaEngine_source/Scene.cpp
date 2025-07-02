#include "Scene.h"

namespace Luna
{
	Luna::Scene::Scene()
		: mGameObjects{}
	{

	}

	Scene::~Scene()
	{
	}

	void Scene::Initialize()
	{
	}

	void Scene::Update()
	{
		for (auto GameObj : mGameObjects)
		{
			GameObj->Update();
		}
	}

	void Scene::LateUpdate()
	{
		for (auto GameObj : mGameObjects)
		{
			GameObj->LateUpdate();
		}
	}

	void Scene::Render(HDC hdc)
	{
		for (auto GameObj : mGameObjects)
		{
			GameObj->Render(hdc);
		}
	}
	void Scene::AddGameObject(GameObject* gameObject)
	{
		mGameObjects.push_back(gameObject);
	}
}