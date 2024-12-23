#pragma once

enum Scene {
	TITLE,
	STAGE,
	CLEAR,
};


class IScene {
public:
	IScene() = default;
	virtual ~IScene();

public:

	virtual void Init() = 0;
	virtual void Update() = 0;
	virtual void Draw() = 0;

	int GetSceneNo();

protected:
	static int sceneNo;

	bool isChangeScene_ = false;
	int beginTime_ = 10;

};
