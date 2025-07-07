#include "Player.h"
#include "Input.h"
#include "Transform.h"
#include "LuTime.h"

namespace Luna
{
	void Player::Initialize()
	{
		GameObject::Initialize();
	}
	void Player::Update()
	{
		GameObject::Update();
	}
	void Player::LateUpdate()
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
	void Player::Render(HDC hdc)
	{
		GameObject::Render(hdc);
	}
}