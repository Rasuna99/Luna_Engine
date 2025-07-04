#include "Layer.h"

namespace Luna
{
	Layer::Layer()
		: mGameObjects{}
	{
	}
	Layer::~Layer()
	{
	}
	void Layer::Initialize()
	{
		for (auto gameObj : mGameObjects)
		{
			if (gameObj == nullptr)
				continue;

			gameObj->Initialize();
		}
	}
	void Layer::Update()
	{
		for (auto gameObj : mGameObjects)
		{
			if (gameObj == nullptr)
				continue;

			gameObj->Update();
		}
	}
	void Layer::LateUpdate()
	{
		for (auto gameObj : mGameObjects)
		{
			if (gameObj == nullptr)
				continue;

			gameObj->LateUpdate();
		}
	}
	void Layer::Render(HDC hdc)
	{
		for (auto gameObj : mGameObjects)
		{
			if (gameObj == nullptr)
				continue;

			gameObj->Render(hdc);
		}
	}
	void Layer::AddGameObject(GameObject* gameObject)
	{
		if (gameObject == nullptr)
			return;

		mGameObjects.push_back(gameObject);
	}
}