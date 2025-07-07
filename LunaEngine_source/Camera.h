#pragma once
#include "Component.h"
#include "GameObject.h"

namespace Luna
{
	using namespace Luna::math;
	class Camera : public Component
	{
	public:
		Camera();
		~Camera();

		Vector2 CalculatePosition(Vector2 pos) { return pos - mDistance; }

		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;

	private:
		//std::vector<GameObject*> mGameObjects;
		class GameObject* mTarget;
		Vector2 mDistance;
		Vector2 mResolution;
		Vector2 mLookPosition;	
	};
}
