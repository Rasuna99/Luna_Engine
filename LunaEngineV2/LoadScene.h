#pragma once
#include "SceneManager.h"
#include "PlayScene.h"

namespace Luna
{
	void LoadScene()
	{
		SceneManager::CreateScene<PlayScene>(L"PlayScene");
	}
}