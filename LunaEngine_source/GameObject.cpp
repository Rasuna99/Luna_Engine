#include "GameObject.h"
#include "Input.h"

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
			mX -= 0.01f;
		}

		if (Input::GetKey(eKeyCode::Right))
		{
			mX += 0.01f;
		}

		if (Input::GetKey(eKeyCode::Up))
		{
			mY -= 0.01f;
		}

		if (Input::GetKey(eKeyCode::Down))
		{
			mY += 0.01f;
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
			mX -= 0.01f;
		}

		if (Input::GetKey(eKeyCode::D))
		{
			mX += 0.01f;
		}

		if (Input::GetKey(eKeyCode::W))
		{
			mY -= 0.01f;
		}

		if (Input::GetKey(eKeyCode::S))
		{
			mY += 0.01f;
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