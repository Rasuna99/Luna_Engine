#pragma once
#include "../LunaEngine_source/GameObject.h"

namespace Luna
{
	class GeneralStore :  public GameObject
	{
	public:
		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;

	private:
	};
}
