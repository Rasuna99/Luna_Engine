#include "TitleScene.h"
#include "Player.h"
#include "Transform.h"
#include "SpriteRenderer.h"
#include "Input.h"
#include "PlayScene.h"
#include "SceneManager.h"
#include "Object.h"

namespace Luna
{
	TitleScene::TitleScene()
	{
	}
	TitleScene::~TitleScene()
	{
	}
	void TitleScene::Initialize()
	{
		//bg = new Player();
		//Transform* tr = bg->AddComponent<Transform>();
		//tr->SetPosition(Vector2(0, 0));
		//
		//tr->SetName(L"TR");
		//
		//SpriteRenderer* sr = bg->AddComponent<SpriteRenderer>();
		//sr->SetName(L"SR");
		//sr->ImageLoad(L"D:/LunaEngine/Resources/Title.png");
		//
		//AddGameObject(bg, enums::eLayerTpye::BackGrond);

		bg = object::Instantiate<Player>(enums::eLayerTpye::BackGrond, Vector2(100.0f, 100.0f));
		SpriteRenderer* sr = bg->AddComponent<SpriteRenderer>();
		sr->ImageLoad(L"D:/LunaEngine/Resources/Title.png");
	}
	void TitleScene::Update()
	{
		Scene::Update();
	}
	void TitleScene::LateUpdate()
	{
		Scene::LateUpdate();

		if (Input::GetKeyDown(eKeyCode::N))
		{
			SceneManager::LoadScene(L"PlayScene");
		}
	}
	void TitleScene::Render(HDC hdc)
	{
		Scene::Render(hdc);
	}
	void TitleScene::OnEnter()
	{
	}
	void TitleScene::OnExit()
	{
		//Transform* tr = bg->GetComponent<Transform>();
		//tr->SetPosition(Vector2(0, 0));
	}
}