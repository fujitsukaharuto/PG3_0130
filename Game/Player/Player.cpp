#include "Player.h"
#include <Novice.h>

Player::Player() {
	playerHandle_ = Novice::LoadTexture("./Sprite/playersea.png");
}

Player::~Player() {
}

void Player::Init() {
	pos_ = { 150.0f,360.0f };
	bullets_.clear();
	coolTime_ = 10;
}

void Player::Update() {

	for (auto it = bullets_.begin(); it != bullets_.end(); ) {
		if (it->isDead) {
			it = bullets_.erase(it);
		}
		else {
			++it;
		}
	}


	float playerSpeed = 4.0f;
	if (Novice::CheckHitKey(DIK_S)) {
		pos_.y += playerSpeed;
	}
	if (Novice::CheckHitKey(DIK_W)) {
		pos_.y -= playerSpeed;
	}


	float bulletSpeed = 5.0f;
	for (auto& bullet : bullets_) {
		bullet.pos.x += bulletSpeed;
		if (bullet.pos.x> 1300) {
			bullet.isDead = true;
		}
	}


	if (coolTime_ <= 0 ) {
		if (Novice::CheckHitKey(DIK_SPACE)) {
			Bullet b = { pos_,false };
			bullets_.push_back(b);
			coolTime_ = 10;
		}
	}
	else {
		coolTime_--;
	}


}

void Player::Draw() {

	for (auto& bullet : bullets_) {
		Novice::DrawEllipse(static_cast<int>(bullet.pos.x), static_cast<int>(bullet.pos.y), 5, 5, 0.0f, GREEN, FillMode::kFillModeSolid);
	}

	Novice::DrawSprite(static_cast<int>(pos_.x - 40.0f), static_cast<int>(pos_.y - 33.0f) , playerHandle_, 1.0f, 1.0f, 0.0f, WHITE);

}
