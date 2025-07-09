#pragma once
#include "../LunaEngine_source/Resources.h"
#include "../LunaEngine_source/Texture.h"


namespace Luna
{
	void LoadResources()
	{
		Resources::Load<graphics::Texture>(L"Cat", L"../Resources/ChickenAlpha.bmp");
		Resources::Load<graphics::Texture>(L"Player", L"../Resources/Player.bmp");
	}
}