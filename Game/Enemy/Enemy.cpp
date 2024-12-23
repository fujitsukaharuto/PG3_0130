#include "Enemy.h"
#include <Novice.h>

Enemy::Enemy() {
	enemyHandle_ = Novice::LoadTexture("./Sprite/seaenemy3.png");
}

Enemy::~Enemy() {
}

void Enemy::Init() {
	isDead_ = false;
	moveTime_ = 75;
	moveChange_ = false;
}

void Enemy::Update() {

	float enemySpeed = 1.0f;
	if (moveChange_) {
		moveTime_--;

		pos_.y += enemySpeed;

		if (moveTime_ <= 0) {
			moveChange_ = false;
		}
	}
	else {
		moveTime_++;

		pos_.y -= enemySpeed;

		if (moveTime_ >= 150) {
			moveChange_ = true;
		}
	}

}

void Enemy::Draw() {
	if (!isDead_) {
		Novice::DrawSprite(static_cast<int>(pos_.x - 28.0f), static_cast<int>(pos_.y - 21.0f), enemyHandle_, 1.0f, 1.0f, 0.0f, WHITE);
	}
}
