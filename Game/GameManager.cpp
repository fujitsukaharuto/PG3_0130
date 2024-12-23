#include "GameManager.h"
#include <Novice.h>

GameManager::GameManager() {
	sceneArr_[TITLE] = std::make_unique<TitleScene>();
	sceneArr_[STAGE] = std::make_unique<StageScene>();
	sceneArr_[CLEAR] = std::make_unique<ClearScene>();

	currentSceneNo_ = TITLE;
	prevSceneNo_ = TITLE;
}

GameManager::~GameManager() {
}

int GameManager::Run() {

	char keys[256] = { 0 };
	char preKeys[256] = { 0 };

	while (Novice::ProcessMessage() == 0) {
		// StartFrame
		Novice::BeginFrame();

		// KeyUpdate
		memcpy(preKeys, keys, 256);
		Novice::GetHitKeyStateAll(keys);

		prevSceneNo_ = currentSceneNo_;
		currentSceneNo_ = sceneArr_[currentSceneNo_]->GetSceneNo();

		if (prevSceneNo_ != currentSceneNo_) {
			sceneArr_[currentSceneNo_]->Init();
		}

		///
		/// Update
		///

		sceneArr_[currentSceneNo_]->Update();
		
		///
		/// 
		///

		///
		/// Draw
		///
		
		sceneArr_[currentSceneNo_]->Draw();

		///
		/// 
		///

		// EndFrame
		Novice::EndFrame();

		// ESC
		if (preKeys[DIK_ESCAPE] == 0 && keys[DIK_ESCAPE] != 0) {
			break;
		}
	}
	return 0;
}
