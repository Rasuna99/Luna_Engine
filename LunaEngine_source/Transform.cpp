#include "Transform.h"

namespace Luna
{
	Transform::Transform()
		: Component(enums::eComponentType::Transform)
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