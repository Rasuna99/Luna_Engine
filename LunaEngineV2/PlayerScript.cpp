#include "PlayerScript.h"
#include "../LunaEngine_source/Transform.h"
#include "../LunaEngine_source/Input.h"
#include "../LunaEngine_source/GameObject.h"
#include "../LunaEngine_source/LuTime.h"
#include "../LunaEngine_source/Animator.h"
#include "Cat.h"
#include "CatScript.h"
#include "../LunaEngine_source/Object.h"
#include "../LunaEngine_source/Resources.h"

namespace Luna
{
	PlayerScript::PlayerScript()
		: mState(PlayerScript::eState::Idle)
		, mAnimator(nullptr)
	{
	}
	PlayerScript::~PlayerScript()
	{
	}
	void PlayerScript::Initialize()
	{
		
	}
	void PlayerScript::Update()
	{
		if (mAnimator == nullptr)
		{
			mAnimator = GetOwner()->GetComponent<Animator>();
		}
		
		switch (mState)
		{
		case Luna::PlayerScript::eState::Idle:
			idle();
			break;
		case Luna::PlayerScript::eState::Walk:
			move();
			break;
		case Luna::PlayerScript::eState::Sleep:
			break;
		case Luna::PlayerScript::eState::Water:
			water();
			break;
		case Luna::PlayerScript::eState::Attack:
			break;
		default:
			break;
		}

		//if (Input::GetKey(eKeyCode::Right))
		//{
		//	Transform* tr = GetOwner()->GetComponent<Transform>();
		//	Vector2 pos = tr->GetPosition();
		//	pos.x += 100.0f * Time::GetDeltaTime();
		//	tr->SetPosition(pos);
		//}
		//if (Input::GetKey(eKeyCode::Left))
		//{
		//	Transform* tr = GetOwner()->GetComponent<Transform>();
		//	Vector2 pos = tr->GetPosition();
		//	pos.x -= 100.0f * Time::GetDeltaTime();
		//	tr->SetPosition(pos);
		//}
		//if (Input::GetKey(eKeyCode::Up))
		//{
		//	Transform* tr = GetOwner()->GetComponent<Transform>();
		//	Vector2 pos = tr->GetPosition();
		//	pos.y -= 100.0f * Time::GetDeltaTime();
		//	tr->SetPosition(pos);
		//}
		//if (Input::GetKey(eKeyCode::Down))
		//{
		//	Transform* tr = GetOwner()->GetComponent<Transform>();
		//	Vector2 pos = tr->GetPosition();
		//	pos.y += 100.0f * Time::GetDeltaTime();
		//	tr->SetPosition(pos);
		//}
	}
	void PlayerScript::LateUpdate()
	{
	}
	void PlayerScript::Render(HDC hdc)
	{
	}
	void PlayerScript::idle()
	{
		if (Input::GetKey(eKeyCode::LButton))
		{
			mState = PlayerScript::eState::Water;
			mAnimator->PlayAnimation(L"FrontWater", false);
		
			Vector2 mousePos = Input::GetMousePosition();
		}
		if (Input::GetKey(eKeyCode::Left))
		{
			mState = PlayerScript::eState::Walk;
			mAnimator->PlayAnimation(L"LeftWalk");
		}
		if (Input::GetKey(eKeyCode::Right))
		{
			mState = PlayerScript::eState::Walk;
			mAnimator->PlayAnimation(L"RightWalk");
		}
		if (Input::GetKey(eKeyCode::Up))
		{
			mState = PlayerScript::eState::Walk;
			mAnimator->PlayAnimation(L"UpWalk");
		}
		if (Input::GetKey(eKeyCode::Down))
		{
			mState = PlayerScript::eState::Walk;
			mAnimator->PlayAnimation(L"DownWalk");
		}
	}
	void PlayerScript::move()
	{
		Transform* tr = GetOwner()->GetComponent<Transform>();
		Vector2 pos = tr->GetPosition();

		if (Input::GetKey(eKeyCode::Right))
		{
			pos.x += 100.0f * Time::GetDeltaTime();
		}
		if (Input::GetKey(eKeyCode::Left))
		{
			pos.x -= 100.0f * Time::GetDeltaTime();
		}
		if (Input::GetKey(eKeyCode::Up))
		{
			pos.y -= 100.0f * Time::GetDeltaTime();
		}
		if (Input::GetKey(eKeyCode::Down))
		{
			pos.y += 100.0f * Time::GetDeltaTime();
		}

		tr->SetPosition(pos);

		if (Input::GetKeyUp(eKeyCode::Right) || Input::GetKeyUp(eKeyCode::Left) || Input::GetKeyUp(eKeyCode::Up) || Input::GetKeyUp(eKeyCode::Down))
		{
			mState = PlayerScript::eState::Idle;
			mAnimator->PlayAnimation(L"SitDown", false);
		}
	}

	void PlayerScript::water()
	{
		if (mAnimator->IsCompleteAnimation())
		{
			mState = eState::Idle;
			mAnimator->PlayAnimation(L"Idle", false);
		}
	}

	void PlayerScript::AttackEffect()
	{
		Cat* cat = object::Instantiate<Cat>(enums::eLayerTpye::Animal);
		cat->AddComponent<CatScript>();

		graphics::Texture* catTex = Resources::Find<graphics::Texture>(L"Cat");
		Animator* catAnimator = cat->AddComponent<Animator>();
		catAnimator->CreateAnimation(L"DownWalk", catTex
			, Vector2(0.0f, 0.0f), Vector2(32.0f, 32.0f), Vector2::zero, 4, 0.1f);
		catAnimator->CreateAnimation(L"RightWalk", catTex
			, Vector2(0.0f, 32.0f), Vector2(32.0f, 32.0f), Vector2::zero, 4, 0.1f);
		catAnimator->CreateAnimation(L"UpWalk", catTex
			, Vector2(0.0f, 64.0f), Vector2(32.0f, 32.0f), Vector2::zero, 4, 0.1f);
		catAnimator->CreateAnimation(L"LeftWalk", catTex
			, Vector2(0.0f, 96.0f), Vector2(32.0f, 32.0f), Vector2::zero, 4, 0.1f);
		catAnimator->CreateAnimation(L"SitDown", catTex
			, Vector2(0.0f, 128.0f), Vector2(32.0f, 32.0f), Vector2::zero, 4, 0.1f);
		catAnimator->CreateAnimation(L"Grooming", catTex
			, Vector2(0.0f, 160.0f), Vector2(32.0f, 32.0f), Vector2::zero, 4, 0.1f);
		catAnimator->CreateAnimation(L"LayDown", catTex
			, Vector2(0.0f, 192.0f), Vector2(32.0f, 32.0f), Vector2::zero, 4, 0.1f);

		catAnimator->PlayAnimation(L"SitDown", false);
		cat->GetComponent<Transform>()->SetPosition(Vector2(200.0f, 200.0f));
		cat->GetComponent<Transform>()->SetScale(Vector2(2.0f, 2.0f));
	}
}