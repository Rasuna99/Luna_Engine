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
#include "Texture.h"
#include "Resources.h"
#include "PlayerScript.h"
#include "Camera.h"
#include "Renderer.h"
#include "../LunaEngine_source/Animator.h"
#include "Cat.h"
#include "CatScript.h"

namespace Luna
{
	PlayScene::PlayScene()
		: mPlayer(nullptr)
	{
	}

	PlayScene::~PlayScene()
	{
	}

	void PlayScene::Initialize()
	{
		// 카메라
		GameObject* camera = object::Instantiate<GameObject>(enums::eLayerTpye::None, Vector2(344.0f, 442.0f));
		Camera* cameraComp = camera->AddComponent<Camera>();
		renderer::mainCamera = cameraComp;

		// 플레이어
		mPlayer = object::Instantiate<Player>(enums::eLayerTpye::Player, Vector2(14.0f, 70.0f)); // 테스트 팩맨 포지션 추후에 주석처리 할 것
		mPlayer->AddComponent<PlayerScript>();

		graphics::Texture* playerTex = Resources::Find<graphics::Texture>(L"Player");
		Animator* animator = mPlayer->AddComponent<Animator>();
		animator->CreateAnimation(L"Idle", playerTex, Vector2(2000.0f, 250.0f), Vector2(250.0f, 250.0f), Vector2::zero, 1, 0.3f);
		animator->CreateAnimation(L"FrontWater", playerTex, Vector2(0.0f, 2000.0f), Vector2(250.0f, 250.0f), Vector2::zero, 12, 0.1f);
		
		animator->PlayAnimation(L"Idle", false);
		
		mPlayer->GetComponent<Transform>()->SetPosition(Vector2(100.0f, 100.0f));
		mPlayer->GetComponent<Transform>()->SetScale(Vector2(0.5f, 0.5f));

		// Cat
		Cat* cat = object::Instantiate<Cat>(enums::eLayerTpye::Animal);
		cat->AddComponent<CatScript>();
		//cameraComp->SetTarget(cat);

		graphics::Texture* catTex = Resources::Find<graphics::Texture>(L"Cat");
		Animator* catAnimator = cat->AddComponent<Animator>();
		//catAnimator->CreateAnimation(L"DownWalk", catTex, Vector2(0.0f, 0.0f), Vector2(32.0f, 32.0f), Vector2::zero, 4, 0.3f);
		//catAnimator->CreateAnimation(L"RightWalk", catTex, Vector2(0.0f, 32.0f), Vector2(32.0f, 32.0f), Vector2::zero, 4, 0.3f);
		//catAnimator->CreateAnimation(L"UpWalk", catTex, Vector2(0.0f, 64.0f), Vector2(32.0f, 32.0f), Vector2::zero, 4, 0.3f);
		//catAnimator->CreateAnimation(L"LeftWalk", catTex, Vector2(0.0f, 96.0f), Vector2(32.0f, 32.0f), Vector2::zero, 4, 0.3f);
		//catAnimator->CreateAnimation(L"SitDown", catTex, Vector2(0.0f, 128.0f), Vector2(32.0f, 32.0f), Vector2::zero, 4, 0.1f);
		//catAnimator->CreateAnimation(L"Grooming", catTex, Vector2(0.0f, 160.0f), Vector2(32.0f, 32.0f), Vector2::zero, 4, 0.3f);
		//catAnimator->CreateAnimation(L"LayDown", catTex, Vector2(0.0f, 192.0f), Vector2(32.0f, 32.0f), Vector2::zero, 4, 0.3f);
		//
		//catAnimator->PlayAnimation(L"SitDown", false);
		catAnimator->CreateAnimationByFolder(L"MushroomIdle", L"../Resources/Mushroom", Vector2::zero, 0.1f);
		catAnimator->PlayAnimation(L"MushroomIdle", true);

		cat->GetComponent<Transform>()->SetPosition(Vector2(200.0f, 200.0f));
		cat->GetComponent<Transform>()->SetScale(Vector2(2.0f, 2.0f));
		
		// 머쉬룸
		//GameObject* sheet = object::Instantiate<GameObject>(enums::eLayerTpye::Player, Vector2(14.0f, 70.0f)); // 테스트 팩맨 포지션 추후에 주석처리 할 것
		//SpriteRenderer* sheetSR = sheet->AddComponent<SpriteRenderer>();
		//
		//
		//graphics::Texture* mrIdle = Resources::Find<graphics::Texture>(L"Mushroom");
		//sheetSR->SetTexture(mrIdle);

		Scene::Initialize();
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
