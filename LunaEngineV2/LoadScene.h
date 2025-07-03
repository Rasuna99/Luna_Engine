#pragma once
#include "../LunaEngine_source/SceneManager.h"
#include "PlayScene.h"
#include "TitleScene.h"

namespace Luna
{
	void LoadScenes()
	{
		SceneManager::CreateScene<TitleScene>(L"TitleScene");
		SceneManager::CreateScene<PlayScene>(L"PlayScene");

		SceneManager::LoadScene(L"TitleScene");
	}
}