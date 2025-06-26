#pragma once
#include "CommonInclude.h"

namespace Luna
{
	class GameObject
	{
	public:
		GameObject();
		~GameObject();

		void Update();
		void LateUpdate();
		void Render(HDC hdc);

		void Update2();
		void LateUpdate2();
		void Render2(HDC hdc);

		void SetPosition(float x, float y);

		float GetPositionX() { return mX; }
		float GetPositionY() { return mY; }

	private:
		float mX;
		float mY;
		const int speed = 100.0f;
	};
}