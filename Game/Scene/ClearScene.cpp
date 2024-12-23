#include "ClearScene.h"
#include <Novice.h>

ClearScene::ClearScene() {
	backHandle_ = Novice::LoadTexture("./Sprite/sea2.png");
	clearHandle_ = Novice::LoadTexture("./Sprite/game_gameclear.png");
}

ClearScene::~ClearScene() {
}

void ClearScene::Init() {
	isChangeScene_ = false;
	beginTime_ = 20;
}

void ClearScene::Update() {

	if (isChangeScene_) {
		IScene::sceneNo = TITLE;
	}

	if (beginTime_ > 0) {
		beginTime_--;
	}
	else {
		if (Novice::CheckHitKey(DIK_RETURN)) {
			isChangeScene_ = true;
		}
	}

}

void ClearScene::Draw() {

	Novice::DrawSprite(0, 0, backHandle_, 1.0f, 1.0f, 0.0f, WHITE);
	Novice::DrawSprite(320, 0, clearHandle_, 1.0f, 1.0f, 0.0f, WHITE);

}
