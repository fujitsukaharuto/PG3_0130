#include "TitleScene.h"
#include <Novice.h>
#include "Game/InputMy.h"

TitleScene::TitleScene() {

	titleHandle_ = Novice::LoadTexture("./Sprite/sea_start.png");
	backHandle_ = Novice::LoadTexture("./Sprite/sea2.png");

}

TitleScene::~TitleScene() {
}

void TitleScene::Init() {
	isChangeScene_ = false;
	beginTime_ = 20;
}

void TitleScene::Update() {

	if (isChangeScene_) {
		sceneNo = STAGE;
	}

	if (beginTime_ > 0) {
		beginTime_--;
	}
	else {
		if (InputMy::PressKey(DIK_SPACE)) {
			isChangeScene_ = true;
		}
	}

}

void TitleScene::Draw() {

	Novice::DrawSprite(0, 0, backHandle_, 1.0f, 1.0f, 0.0f, WHITE);
	Novice::DrawSprite(340, 400, titleHandle_, 1.0f, 1.0f, 0.0f, WHITE);

}
