#include "SceneManager.h"

namespace Luna
{
	void Luna::SceneManager::Initialize()
	{
	}

	void Luna::SceneManager::Update()
	{
		mActiveScene->Update();
	}

	void Luna::SceneManager::LateUpdate()
	{
		mActiveScene->LateUpdate();
	}

	void Luna::SceneManager::Render(HDC hdc)
	{
		mActiveScene->Render(hdc);
	}
}