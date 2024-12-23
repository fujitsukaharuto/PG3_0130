#pragma once
#include "Math/Vector2My.h"


class Enemy {
public:
	Enemy();
	~Enemy();

public:

	void Init();
	void Update();
	void Draw();

	Vector2My GetPosition() { return pos_; }
	void SetPosition(const Vector2My& pos) { pos_ = pos; }

	bool GetIsDead() const { return isDead_; }
	void SetIsDead(bool is) { isDead_ = is; }

private:

	int enemyHandle_ = 0;

	Vector2My pos_;
	int moveTime_ = 0;
	bool moveChange_ = false;
	bool isDead_ = false;

};
