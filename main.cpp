#include <Novice.h>
#include <memory>
#include "Game/GameManager.h"

const char kWindowTitle[] = "LE2A_17_フジツカ_ハルト";

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

	// ライブラリの初期化
	Novice::Initialize(kWindowTitle, 1280, 720);

	std::unique_ptr<GameManager> game_;
	game_ = std::make_unique<GameManager>();

	// ウィンドウの×ボタンが押されるまでループ
	game_->Run();

	// ライブラリの終了
	Novice::Finalize();
	return 0;
}
