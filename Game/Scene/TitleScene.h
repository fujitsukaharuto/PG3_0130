#pragma once
#include "IScene.h"
#include "Math/Vector2My.h"

class TitleScene : public IScene {
public:
	TitleScene();
	~TitleScene()override;

public:

	void Init()override;
	void Update()override;
	void Draw()override;

private:

	int titleHandle_ = 0;
	int backHandle_ = 0;

};
