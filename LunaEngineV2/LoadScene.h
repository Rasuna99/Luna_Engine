#pragma once
#include "../LunaEngine_source/SceneManager.h"
#include "PlayScene.h"

namespace Luna
{
	void LoadScenes()
	{
		SceneManager::CreateScene<PlayScene>(L"PlayScene");

		SceneManager::LoadScene(L"PlayScene");
	}
}