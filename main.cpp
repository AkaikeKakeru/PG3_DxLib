#include "DxLib.h"
#include "SceneManager.h"

// タイトル
const char TITLE[] = "LE2B_01_Akaike_Kakeru_PG3";

// ウィンドウ横幅
const int WIN_WIDTH = 600;

// ウィンドウ縦幅
const int WIN_HEIGHT = 400;

int WINAPI WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPSTR lpCmdLine,
	_In_ int nCmdShow) {


	ChangeWindowMode(TRUE);

	//ウィンドウサイズの変化を無効に(固定化)
	SetWindowSizeChangeEnableFlag(FALSE, FALSE);

	// タイトルセット
	SetMainWindowText(TITLE);

	//グラフィックスモードセット
	SetGraphMode(WIN_WIDTH, WIN_HEIGHT, 32);

	// 拡張率セット
	SetWindowSizeExtendRate(1.0);

	// 背景色セット
	SetBackgroundColor(0x00, 0x00, 0x00);

	// DXlib初期化
	if (DxLib_Init() == -1) { return -1; }

	// スクリーンを描画
	SetDrawScreen(DX_SCREEN_BACK);

	// ここまで初期設定


	// ここからプログラム

	//変数宣言
	SceneManager* sceneManager_ = SceneManager::GetInstance();

	//キーの全種類数
	const int kKeyCount = 256;

	// 現キー入力
	char keys[kKeyCount] = { 0 };

	// 1F前のキー入力
	char oldkeys[kKeyCount] = { 0 };


	// ゲームループ
	while (true) {

		for (size_t i = 0; i < kKeyCount; i++) {
			oldkeys[i] = keys[i];
		}

		//キー入力を取得
		GetHitKeyStateAll(keys);

		// スクリーンを一旦真っ新に
		ClearDrawScreen();
		//---------  ここからが本命処理  ----------//

		// 更新
		if (keys[KEY_INPUT_SPACE] == 0 &&
			oldkeys[KEY_INPUT_SPACE] == 1) {
			sceneManager_->Update();
		}

		// 描画

		sceneManager_->Draw();

		//--------- ここまでが本命処理 ---------//
		// 画面フリップ
		ScreenFlip();

		// 20Fほど待機
		WaitTimer(20);

		// 中断依頼があったら終了
		if (ProcessMessage() == -1) {
			break;
		}

		// ESCキー入力されても終了
		if (CheckHitKey(KEY_INPUT_ESCAPE) == 1) {
			break;
		}
	}

	// DxLib後始末
	DxLib_End();

	// 正常終了
	return 0;
}
