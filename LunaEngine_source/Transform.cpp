#include "Transform.h"

namespace Luna
{
	Transform::Transform()
		: Component(enums::eComponentType::Transform)
		, mScale(Vector2::one)
		, mRotation(0.0f)
	{
	}
	Transform::~Transform()
	{
	}
	void Transform::LateUpdate()
	{
	}

	void Transform::Render(HDC hdc)
	{
	}
}