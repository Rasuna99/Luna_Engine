#pragma once
#include "../LunaEngine_source/Script.h"

namespace Luna
{
	class PlayerScript : public Script
	{
	public:
		enum class eState
		{
			Idle,
			Walk,
			Sleep,
			Water,
			Attack,
		};

		PlayerScript();
		~PlayerScript();

		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;

	private:
		void idle();
		void move();
		void water();
	

	private:
		eState mState;
		class Animator* mAnimator;
	};
}
