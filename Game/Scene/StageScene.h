#pragma once
#include <memory>
#include <vector>
#include "IScene.h"
#include "Math/Vector2My.h"
#include "Game/Player/Player.h"
#include "Game/Enemy/Enemy.h"

class StageScene : public IScene {
public:
	StageScene();
	~StageScene()override;

public:

	void Init()override;
	void Update()override;
	void Draw()override;

private:

	int backHandle_ = 0;

	std::unique_ptr<Player> player_;
	std::vector<std::unique_ptr<Enemy>> enemys_;

};
