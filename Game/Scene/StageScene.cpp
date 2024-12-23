#include "StageScene.h"
#include <Novice.h>
#include <list>

StageScene::StageScene() {

	backHandle_ = Novice::LoadTexture("./Sprite/sea2.png");
	player_ = std::make_unique<Player>();
	enemys_.resize(3);
	for (int i = 0; i < 3; i++) {
		enemys_[i] = std::make_unique<Enemy>();
	}

}

StageScene::~StageScene() {
}

void StageScene::Init() {
	isChangeScene_ = false;
	beginTime_ = 20;

	player_->Init();
	for (int i = 0; i < 3; i++) {
		enemys_[i]->Init();
		enemys_[i]->SetPosition({ 1000.0f,(250.0f) + 150 * i });
	}

}

void StageScene::Update() {


	player_->Update();

	for (int i = 0; i < 3; i++) {
		if (enemys_[i]->GetIsDead()) {
			continue;
		}
		enemys_[i]->Update();
	}


	std::list<Bullet> bullets;
	bullets = player_->GetBullets();

	for (int i = 0; i < 3; i++) {
		if (enemys_[i]->GetIsDead()) {
			continue;
		}

		for (auto it = bullets.begin(); it != bullets.end();it++ ) {
			if (enemys_[i]->GetIsDead()) {
				break;
			}
			float length = (enemys_[i]->GetPosition() - it->pos).Length();

			float bulletRad = 5.0f;
			float enemyRad = 25.0f;
			if (length < bulletRad + enemyRad) {
				enemys_[i]->SetIsDead(true);
			}
		}
	}


	if (beginTime_ > 0) {
		beginTime_--;
	}
	else {
		for (int i = 0; i < 3; i++) {
			if (enemys_[i]->GetIsDead()) {
				isChangeScene_ = true;
			}
			else {
				isChangeScene_ = false;
				break;
			}
		}
	}

	if (isChangeScene_) {
		IScene::sceneNo = CLEAR;
	}

}

void StageScene::Draw() {

	Novice::DrawSprite(0, 0, backHandle_, 1.0f, 1.0f, 0.0f, WHITE);

	player_->Draw();
	for (int i = 0; i < 3; i++) {
		enemys_[i]->Draw();
	}

}
