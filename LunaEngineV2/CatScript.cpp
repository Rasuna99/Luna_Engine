#include "CatScript.h"
#include "../LunaEngine_source/Transform.h"
#include "../LunaEngine_source/Input.h"
#include "../LunaEngine_source/GameObject.h"
#include "../LunaEngine_source/LuTime.h"
#include "../LunaEngine_source/Animator.h"
#include "../LunaEngine_source/Object.h"
#include <assert.h>

namespace Luna
{
	CatScript::CatScript()
		: mState(CatScript::eState::SitDown)
		, mAnimator(nullptr)
		, mTime(0.0f)
		, mDeathTime(0.0f)
	{
	}
	CatScript::~CatScript()
	{
	}
	void CatScript::Initialize()
	{

	}
	void CatScript::Update()
	{
		mDeathTime += Time::GetDeltaTime();
		if (mDeathTime > 6.0f)
		{
			//object::Destroy(GetOwner());
		}

		if (mAnimator == nullptr)
		{
			mAnimator = GetOwner()->GetComponent<Animator>();
		}

		switch (mState)
		{
		case Luna::CatScript::eState::SitDown:
			sitDown();
			break;
		case Luna::CatScript::eState::Walk:
			move();
			break;
		case Luna::CatScript::eState::Sleep:
			break;
		case Luna::CatScript::eState::LayDown:
			layDown();
			break;
		case Luna::CatScript::eState::Attack:
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
	void CatScript::LateUpdate()
	{
	}
	void CatScript::Render(HDC hdc)
	{
	}
	void CatScript::sitDown()
	{
		mTime += Time::GetDeltaTime();

		Transform* tr = GetOwner()->GetComponent<Transform>();
		Vector2 pos = tr->GetPosition();
		pos += Vector2(-1.0f, 1.0f) * (100.0f * Time::GetDeltaTime());
		tr->SetPosition(pos);


		Vector2 mousPos = Vector2::zero;
		if (Input::GetKeyDown(eKeyCode::LButton))
		{
			mousPos = Input::GetMousePosition();
		}
		Vector2 dest = mousPos - pos;
		pos += mousPos.normalize() * (100.0f * Time::GetDeltaTime());

		//if (mTime > 5.0f)
		//{
		//	mState = CatScript::eState::Walk;
		//	int direction = rand() % 4;
		//	mDirection = (eDirection)direction;
		//	playWalkAnimationByDirection(mDirection);
		//	mTime = 0.0f;
		//}
	}

	void CatScript::layDown()
	{
		mTime += Time::GetDeltaTime();
		if (mTime > 5.0f)
		{
			mState = CatScript::eState::Walk;
			int direction = rand() % 4;
			mDirection = (eDirection)direction;
			playWalkAnimationByDirection(mDirection);
			mTime = 0.0f;
		}
	}

	void CatScript::move()
	{
		mTime += Time::GetDeltaTime();
		if (mTime > 2.0f)
		{
			int isLayDown = rand() % 2;
			if (isLayDown)
			{
				mState = CatScript::eState::LayDown;
				mAnimator->PlayAnimation(L"LayDown", false);
			}
			else
			{
				mState = CatScript::eState::SitDown;
				mAnimator->PlayAnimation(L"SitDown", false);
			}
		}
		Transform* tr = GetOwner()->GetComponent<Transform>();
		translate(tr);
		
	}
	void CatScript::translate(Transform* tr)
	{
		Vector2 pos = tr->GetPosition();
		switch (mDirection)
		{
		case Luna::CatScript::eDirection::Left:
			pos.x -= 100.0f * Time::GetDeltaTime();
			break;
		case Luna::CatScript::eDirection::Right:
			pos.x += 100.0f * Time::GetDeltaTime();
			break;
		case Luna::CatScript::eDirection::Down:
			pos.y += 100.0f * Time::GetDeltaTime();
			break;
		case Luna::CatScript::eDirection::Up:
			pos.y -= 100.0f * Time::GetDeltaTime();
			break;
		default:
			assert(false);
			break;
		}
		tr->SetPosition(pos);
	}
	void CatScript::playWalkAnimationByDirection(eDirection dir)
	{
		switch (dir)
		{
		case Luna::CatScript::eDirection::Left:
			mAnimator->PlayAnimation(L"LeftWalk", true);
			break;
		case Luna::CatScript::eDirection::Right:
			mAnimator->PlayAnimation(L"RightWalk", true);
			break;
		case Luna::CatScript::eDirection::Down:
			mAnimator->PlayAnimation(L"DownWalk", true);
			break;
		case Luna::CatScript::eDirection::Up:
			mAnimator->PlayAnimation(L"UpWalk", true);
			break;
		default:
			assert(false);
			break;
		}
	}
}