#include "LoadScenes.h"
#include "../LunaEngine_source/SceneManager.h"
#include "PlayScene.h"

namespace Luna {
    // ⛳️ 명시적 인스턴스화 선언은 반드시 .cpp에!
    template Scene* SceneManager::CreateScene<PlayScene>(const std::wstring&);

    void LoadScenes() {
        SceneManager::CreateScene<PlayScene>(L"PlayScene");
        SceneManager::LoadScene(L"PlayScene");
    }
}