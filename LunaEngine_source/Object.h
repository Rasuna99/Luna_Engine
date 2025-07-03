#pragma once
#include "Layer.h"
#include "GameObject.h"
#include "SceneManager.h"
#include "Scene.h"
#include "Component.h"
#include "Transform.h"

namespace Luna::object
{
	template <typename T>
	static T* Instantiate(Luna::enums::eLayerTpye type)
	{
		T* gameObject = new T();
		Scene* activeScene = SceneManager::GetActiveScene();
		Layer* layer = activeScene->GetLayer(type);
		layer->AddGameObject(gameObject);

		return gameObject;
	}

	template <typename T>
	static T* Instantiate(Luna::enums::eLayerTpye type, math::Vector2 position)
	{
		T* gameObject = new T();
		Scene* activeScene = SceneManager::GetActiveScene();
		Layer* layer = activeScene->GetLayer(type);
		layer->AddGameObject(gameObject);

		Transform* tr = gameObject->GetComponent<Transform>();
		tr->SetPosition(position);

		return gameObject;
	}
}