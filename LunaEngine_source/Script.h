#pragma once
#include "Component.h"

namespace Luna
{
	class Script : public Component
	{
	public:
		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;

	private:
	};
}
