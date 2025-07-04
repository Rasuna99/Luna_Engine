#pragma once
#include "../LunaEngine_source/Resources.h"
#include "../LunaEngine_source/Texture.h"


namespace Luna
{
	void LoadResources()
	{
		Resources::Load<graphics::Texture>(L"BG", L"D:/LunaEngine/Resources/CloudOcean.png");
		Resources::Load<graphics::Texture>(L"Title", L"D:/LunaEngine/Resources/Title.png");
	}
}