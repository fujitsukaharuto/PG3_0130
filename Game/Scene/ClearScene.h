#pragma once
#include "IScene.h"


class ClearScene : public IScene {
public:
	ClearScene();
	~ClearScene()override;

public:

	void Init()override;
	void Update()override;
	void Draw()override;

private:

	int backHandle_ = 0;
	int clearHandle_ = 0;

};
