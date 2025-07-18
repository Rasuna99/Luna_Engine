#include "Layer.h"

namespace Luna
{
	Layer::Layer()
		: mGameObjects{}
	{
	}
	Layer::~Layer()
	{
		for (auto& gameObj : mGameObjects)
		{
			if (gameObj == nullptr)
				continue;
			
			delete gameObj;
			gameObj = nullptr;
		}
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

			GameObject::eState state = gameObj->GetActive();
			if (state == GameObject::eState::Paused || state == GameObject::eState::Dead)
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

			GameObject::eState state = gameObj->GetActive();
			if (state == GameObject::eState::Paused || state == GameObject::eState::Dead)
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

			GameObject::eState state = gameObj->GetActive();
			if (state == GameObject::eState::Paused || state == GameObject::eState::Dead)
				continue;

			gameObj->Render(hdc);
		}
	}
	void Layer::Destroy()
	{
		for (GameObjIter iter = mGameObjects.begin(); iter != mGameObjects.end();)
		{
			GameObject::eState active = (*iter)->GetActive();
			if (active == GameObject::eState::Dead)
			{
				GameObject* deathObj = (*iter);
				iter = mGameObjects.erase(iter);

				delete deathObj;
				deathObj = nullptr;
				continue;
			}
			iter++;
		}
	}
	void Layer::AddGameObject(GameObject* gameObject)
	{
		if (gameObject == nullptr)
			return;

		mGameObjects.push_back(gameObject);
	}
}