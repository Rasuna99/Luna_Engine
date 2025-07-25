#pragma once
#include "Entity.h"
#include "Component.h"


namespace Luna
{
	using namespace math;
	class Transform : public Component
	{
	public:
		Transform();
		~Transform();

		void LateUpdate() override;
		void Render(HDC hdc) override;

		void SetPosition(Vector2 pos) { mPosition.x = pos.x, mPosition.y = pos.y; }
		Vector2 GetPosition() { return mPosition; }
		float GetRotation() { return mRotation; }
		Vector2 GetScale() { return mScale; }
		void SetRotation(float rotate) { mRotation = rotate; }
		void SetScale(Vector2 scale) { mScale = scale; }

	private:
		Vector2 mPosition;
		Vector2 mScale;
		float mRotation;
	};
}
