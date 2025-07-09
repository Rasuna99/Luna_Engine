#include "Cat.h"
#include "Input.h"
#include "Transform.h"
#include "LuTime.h"

namespace Luna
{
	void Cat::Initialize()
	{
		GameObject::Initialize();
	}
	void Cat::Update()
	{
		GameObject::Update();
	}
	void Cat::LateUpdate()
	{
		GameObject::LateUpdate();

		//if (Input::GetKey(eKeyCode::Right))
		//{
		//	Transform* tr = GetComponent<Transform>();
		//	Vector2 pos = tr->GetPosition();
		//	pos.x += 100.0f * Time::GetDeltaTime();
		//	tr->SetPosition(pos);
		//}
	}
	void Cat::Render(HDC hdc)
	{
		GameObject::Render(hdc);
	}
}