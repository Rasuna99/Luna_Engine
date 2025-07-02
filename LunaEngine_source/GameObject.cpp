#include "GameObject.h"
#include "Input.h"
#include "LuTime.h"

namespace Luna
{
	Luna::GameObject::GameObject()
		: mX(0)
		, mY(0)
	{
	}

	Luna::GameObject::~GameObject()
	{
	}

	void GameObject::Update()
	{
		const int speed = 100.0f;
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

	void GameObject::LateUpdate()
	{
	}

	void GameObject::Render(HDC hdc)
	{
		// 파랑 브러쉬 생성
		HBRUSH blueBrush = CreateSolidBrush(RGB(rand() % 255, rand() % 255, rand() % 255));

		// 파랑 브러쉬 DC에 선택, 흰색 브러쉬 반환
		HBRUSH oldBrush = (HBRUSH)SelectObject(hdc, blueBrush);

		HPEN redPen = CreatePen(PS_SOLID, 2, RGB(rand() % 255, rand() % 255, rand() % 255));
		HPEN oldPen = (HPEN)SelectObject(hdc, redPen);
		SelectObject(hdc, oldPen);

		Ellipse(hdc, mX, mY, 100 + mX, 100 + mY);

		SelectObject(hdc, oldBrush);
		DeleteObject(blueBrush);
		DeleteObject(redPen);
	}
}