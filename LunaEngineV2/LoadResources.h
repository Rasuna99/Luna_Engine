#pragma once
#include "../LunaEngine_source/Resources.h"
#include "../LunaEngine_source/Texture.h"


namespace Luna
{
	void LoadResources()
	{
		Resources::Load<graphics::Texture>(L"Map", L"../Resources/img/map/map_pure.png");
		Resources::Load<graphics::Texture>(L"PacMan", L"../Resources/img/pacman/0.png");
		Resources::Load<graphics::Texture>(L"Cat", L"../Resources/ChickenAlpha.bmp");
		Resources::Load<graphics::Texture>(L"Bubble", L"../Resources/Bubble.png");
		Resources::Load<graphics::Texture>(L"MappleEffect", L"../Resources/ezgif.com-gif-maker.png");
	}
}