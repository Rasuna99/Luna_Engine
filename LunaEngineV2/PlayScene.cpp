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
		//camera->AddComponent<PlayerScript>();

		// 플레이어
		mPlayer = object::Instantiate<Player>(enums::eLayerTpye::Particle, Vector2(14.0f, 70.0f)); // 테스트 팩맨 포지션 추후에 주석처리 할 것
		//SpriteRenderer* sr = mPlayer->AddComponent<SpriteRenderer>();
		//sr->SetScale(Vector2(3.0f, 3.0f));
		mPlayer->AddComponent<PlayerScript>();

		graphics::Texture* pacManTexture = Resources::Find<graphics::Texture>(L"Cat");
		Animator* animator = mPlayer->AddComponent<Animator>();
		animator->CreateAnimation(L"DownWalk", pacManTexture, Vector2(0.0f, 0.0f), Vector2(32.0f, 32.0f), Vector2::zero, 4, 0.3f);
		animator->CreateAnimation(L"RightWalk", pacManTexture, Vector2(0.0f, 32.0f), Vector2(32.0f, 32.0f), Vector2::zero, 4, 0.3f);
		animator->CreateAnimation(L"UpWalk", pacManTexture, Vector2(0.0f, 64.0f), Vector2(32.0f, 32.0f), Vector2::zero, 4, 0.3f);
		animator->CreateAnimation(L"LeftWalk", pacManTexture, Vector2(0.0f, 96.0f), Vector2(32.0f, 32.0f), Vector2::zero, 4, 0.3f);
		animator->CreateAnimation(L"SitDown", pacManTexture, Vector2(0.0f, 128.0f), Vector2(32.0f, 32.0f), Vector2::zero, 4, 0.1f);
		animator->CreateAnimation(L"Grooming", pacManTexture, Vector2(0.0f, 160.0f), Vector2(32.0f, 32.0f), Vector2::zero, 4, 0.3f);

		animator->PlayAnimation(L"SitDown", false);

		//graphics::Texture* pacManTexture = Resources::Find<graphics::Texture>(L"MappleEffect");
		//Animator* animator = mPlayer->AddComponent<Animator>();
		//animator->CreateAnimation(L"CatFrontMove", pacManTexture, Vector2(0.0f, 0.0f), Vector2(386.0f, 246.0f), Vector2::zero, 8, 0.1f);
		//animator->PlayAnimation(L"CatFrontMove", true);

		mPlayer->GetComponent<Transform>()->SetPosition(Vector2(100.0f, 100.0f));
		mPlayer->GetComponent<Transform>()->SetScale(Vector2(2.0f, 2.0f));
		//mPlayer->GetComponent<Transform>()->SetRotation(30.0f);
		//sr->SetTexture(pacManTexture);

		//GameObject* bg = object::Instantiate<GameObject>(enums::eLayerTpye::Player/*, Vector2(100.0f, 100.0f)*/);
		//SpriteRenderer* bgsr = bg->AddComponent<SpriteRenderer>();
		////bgsr->SetScale(Vector2(3.0f, 3.0f));
		//
		//graphics::Texture* bgTexture = Resources::Find<graphics::Texture>(L"Bubble");
		//bgsr->SetTexture(bgTexture);

		// Cat
		Cat* cat = object::Instantiate<Cat>(enums::eLayerTpye::Animal); // 테스트 팩맨 포지션 추후에 주석처리 할 것
		cat->AddComponent<CatScript>();

		graphics::Texture* catTex = Resources::Find<graphics::Texture>(L"Cat");
		Animator* catAnimator = cat->AddComponent<Animator>();
		catAnimator->CreateAnimation(L"DownWalk", catTex, Vector2(0.0f, 0.0f), Vector2(32.0f, 32.0f), Vector2::zero, 4, 0.3f);
		catAnimator->CreateAnimation(L"RightWalk", catTex, Vector2(0.0f, 32.0f), Vector2(32.0f, 32.0f), Vector2::zero, 4, 0.3f);
		catAnimator->CreateAnimation(L"UpWalk", catTex, Vector2(0.0f, 64.0f), Vector2(32.0f, 32.0f), Vector2::zero, 4, 0.3f);
		catAnimator->CreateAnimation(L"LeftWalk", catTex, Vector2(0.0f, 96.0f), Vector2(32.0f, 32.0f), Vector2::zero, 4, 0.3f);
		catAnimator->CreateAnimation(L"SitDown", catTex, Vector2(0.0f, 128.0f), Vector2(32.0f, 32.0f), Vector2::zero, 4, 0.1f);
		catAnimator->CreateAnimation(L"Grooming", catTex, Vector2(0.0f, 160.0f), Vector2(32.0f, 32.0f), Vector2::zero, 4, 0.3f);
		catAnimator->CreateAnimation(L"LayDown", catTex, Vector2(0.0f, 192.0f), Vector2(32.0f, 32.0f), Vector2::zero, 4, 0.3f);

		catAnimator->PlayAnimation(L"SitDown", false);
		cat->GetComponent<Transform>()->SetPosition(Vector2(200.0f, 200.0f));
		cat->GetComponent<Transform>()->SetScale(Vector2(2.0f, 2.0f));

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
