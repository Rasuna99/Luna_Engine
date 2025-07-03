#include "PlayScene.h"
#include "GameObject.h"
#include "Player.h"
#include "Transform.h"
#include "SpriteRenderer.h"
#include "Input.h"
#include "TitleScene.h"
#include "SceneManager.h"
#include "Layer.h"
#include "Object.h"

namespace Luna
{
	PlayScene::PlayScene()
	{
	}

	PlayScene::~PlayScene()
	{
	}

	void PlayScene::Initialize()
	{
		//bg = new Player();
		//Transform* tr = bg->AddComponent<Transform>();
		//tr->SetPos(Vector2(0, 0));
		//
		//tr->SetName(L"TR");
		//
		//SpriteRenderer* sr = bg->AddComponent<SpriteRenderer>();
		//sr->SetName(L"SR");
		//sr->ImageLoad(L"D:/LunaEngine/Resources/CloudOcean.png");
		//
		//AddGameObject(bg, eLayerTpye::BackGrond);

		bg = object::Instantiate<Player>(enums::eLayerTpye::BackGrond, Vector2(100.0f, 100.0f));
		SpriteRenderer* sr = bg->AddComponent<SpriteRenderer>();
		sr->ImageLoad(L"D:/LunaEngine/Resources/CloudOcean.png");
	}

	void PlayScene::Update()
	{
		Scene::Update();
	}

	void PlayScene::LateUpdate()
	{
		Scene::LateUpdate();

		if (Input::GetKeyDown(eKeyCode::N))
		{
			SceneManager::LoadScene(L"TitleScene");
		}
	}

	void PlayScene::Render(HDC hdc)
	{
		Scene::Render(hdc);
	}
	void PlayScene::OnEnter()
	{
	}
	void PlayScene::OnExit()
	{
		//Transform* tr = bg->GetComponent<Transform>();
		//tr->SetPosition(Vector2(0, 0));
	}
}
