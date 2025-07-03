#include "GameObject.h"
#include "Input.h"
#include "LuTime.h"
#include "Transform.h"

namespace Luna
{
	GameObject::GameObject()
	{
		initializeTransform();
	}

	GameObject::~GameObject()
	{
	}

	void GameObject::Initialize()
	{
		for (auto* comp : mComponents)
		{
			comp->Initialize();
		}
	}

	void GameObject::Update()
	{
		for (auto* comp : mComponents)
		{
			comp->Update();
		}
	}

	void GameObject::LateUpdate()
	{
		for (auto* comp : mComponents)
		{
			comp->LateUpdate();
		}
	}

	void GameObject::Render(HDC hdc)
	{
		for (auto* comp : mComponents)
		{
			comp->Render(hdc);
		}
	}
	void GameObject::initializeTransform()
	{
		AddComponent<Transform>();
	}
}