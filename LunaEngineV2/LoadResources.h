#pragma once
#include "../LunaEngine_source/Resources.h"
#include "../LunaEngine_source/Texture.h"


namespace Luna
{
	void LoadResources()
	{
		Resources::Load<graphics::Texture>(L"Map", L"../Resources/img/map/map_pure.png");
		Resources::Load<graphics::Texture>(L"PacMan", L"../Resources/img/pacman/0.png");
	}
}