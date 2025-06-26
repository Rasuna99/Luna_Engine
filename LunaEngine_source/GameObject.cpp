#include "GameObject.h"
#include "Input.h"
#include "LuTime.h"

namespace Luna
{
	Luna::GameObject::GameObject()
		: mX(0.0f)
		, mY(0.0f)
	{
	}

	Luna::GameObject::~GameObject()
	{
	}

	void GameObject::Update()
	{
		if (Input::GetKey(eKeyCode::Left))
		{
			mX -= speed * Time::GetDeltaTime();
		}

		if (Input::GetKey(eKeyCode::Right))
		{
			mX += speed * Time::GetDeltaTime();
		}

		if (Input::GetKey(eKeyCode::Up))
		{
			mY -= speed * Time::GetDeltaTime();
		}

		if (Input::GetKey(eKeyCode::Down))
		{
			mY += speed * Time::GetDeltaTime();
		}
	}

	void GameObject::LateUpdate()
	{
	}

	void GameObject::Render(HDC hdc)
	{
		// 파랑 브러쉬 생성
		HBRUSH blueBrush = CreateSolidBrush(RGB(0, 0, 255));

		// 파랑 브러쉬 DC에 선택, 흰색 브러쉬 반환
		HBRUSH oldBrush = (HBRUSH)SelectObject(hdc, blueBrush);

		HPEN redPen = CreatePen(PS_SOLID, 2, RGB(255, 0, 0));
		HPEN oldPen = (HPEN)SelectObject(hdc, redPen);
		SelectObject(hdc, oldPen);

		Rectangle(hdc, 100 + mX, 100 + mY, 200 + mX, 200 + mY);

		SelectObject(hdc, oldBrush);
		DeleteObject(blueBrush);
		DeleteObject(redPen);
	}

	void GameObject::Update2()
	{
		if (Input::GetKey(eKeyCode::A))
		{
			mX -= speed * Time::GetDeltaTime();
		}

		if (Input::GetKey(eKeyCode::D))
		{
			mX += speed * Time::GetDeltaTime();
		}

		if (Input::GetKey(eKeyCode::W))
		{
			mY -= speed * Time::GetDeltaTime();
		}

		if (Input::GetKey(eKeyCode::S))
		{
			mY += speed * Time::GetDeltaTime();
		}
	}

	void GameObject::LateUpdate2()
	{
	}

	void GameObject::Render2(HDC hdc)
	{
		HBRUSH redBrush = CreateSolidBrush(RGB(255, 0, 0));
		HBRUSH oldBrush = (HBRUSH)SelectObject(hdc, redBrush);

		Ellipse(hdc, 1200 + mX, 400 + mY, 1300 + mX, 500 + mY);

		SelectObject(hdc, oldBrush);
		DeleteObject(redBrush);
	}

	void GameObject::SetPosition(float x, float y)
	{
		mX = x;
		mY = y;
	}
}