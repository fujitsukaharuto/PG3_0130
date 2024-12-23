#pragma once

#include <memory>
#include "Scene/IScene.h"
#include "Scene/TitleScene.h"
#include "Scene/StageScene.h"
#include "Scene/ClearScene.h"


class GameManager {
public:
	GameManager();
	~GameManager();

public:

	int Run();


private:

	std::unique_ptr<IScene> sceneArr_[3];

	int currentSceneNo_;
	int prevSceneNo_;

};
