#pragma once
#include "Math/Vector2My.h"
#include <list>


struct Bullet {
	Vector2My pos;
	bool isDead = false;
};

class Player {
public:
	Player();
	~Player();

public:

	void Init();
	void Update();
	void Draw();

	std::list<Bullet> GetBullets() { return bullets_; }

private:

	int playerHandle_ = 0;

	Vector2My pos_ = { 150.0f,360.0f };

	std::list<Bullet> bullets_;
	int coolTime_ = 10;

};
