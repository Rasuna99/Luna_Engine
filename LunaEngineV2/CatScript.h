#pragma once
#include "../LunaEngine_source/Script.h"
#include "../LunaEngine_source/Transform.h"

namespace Luna
{
	class CatScript : public Script
	{
	public:
		enum class eState
		{
			SitDown,
			Walk,
			Sleep,
			LayDown,
			Attack,
		};

		enum class eDirection
		{
			Left,
			Right,
			Down,
			Up,
			End,
		};

		CatScript();
		~CatScript();

		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;
		void SetPlayer(GameObject* player) { mPlayer = player; }

	private:
		void sitDown();
		void move();
		void layDown();
		void playWalkAnimationByDirection(eDirection dir);
		void translate(Transform* tr);
		

	private:
		eState mState;
		class Animator* mAnimator;
		eDirection mDirection;
		float mTime;
		float mDeathTime;

		GameObject* mPlayer;
	};
}
