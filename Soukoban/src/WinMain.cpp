
#include "DxLib.h"
#include "Manager/SceneManager.h"
#include "Manager/GameManager.h"
#include "Manager/InputManager.h"

// 定数定義
const int WINDOW_W  = 640;
const int WINDOW_H  = 480;
const int COLOR_BIT = 32;

// プログラムは WinMain から始まります
// 警告C28251を回避するためにWinMainの引数に注釈を追記
// https://dxlib.xsrv.jp/cgi/patiobbs/patio.cgi?mode=view&no=4947
int WINAPI WinMain(_In_     HINSTANCE hInstance,
				   _In_opt_ HINSTANCE hPrevInstance,
				   _In_     LPSTR lpCmdLine,
				   _In_     int nCmdShow )
{
	// ＤＸライブラリ初期化処理
	SetOutApplicationLogValidFlag(FALSE);			// ログ出力
	ChangeWindowMode(TRUE);							// ウィンドウモード
	SetGraphMode(WINDOW_W, WINDOW_H, COLOR_BIT);	// 画面モード変更
	SetBackgroundColor(125, 125, 125);				// 背景色
	SetMainWindowText("My倉庫番");					// メニューバーのタイトル
	if( DxLib_Init() == -1 ){ return -1; }

	// 描画先を裏の画面に設定
	SetDrawScreen(DX_SCREEN_BACK);

	// 管理クラスの作成
	GameManager::CreateInstance();
	InputManager::CreateInstance();
	SceneManager::CreateInstance();

	// ゲームループ
	while( true )
	{
		// Windowsのメッセージ処理に失敗したか、閉じられたら終了
		if( ProcessMessage() != 0 ){ break; }

		// DxLibのお約束：画面クリア
		ClearDrawScreen();
		clsDx();

		// 処理
		InputManager::GetInstance()->Update();
		SceneManager::GetInstance()->Exec();

		// 描画
		SceneManager::GetInstance()->Draw();

		// DxLibのお約束：画面更新
		ScreenFlip();
	}

	// 管理クラスの後始末
	SceneManager::DestroyInstance();
	InputManager::DestroyInstance();
	GameManager::DestroyInstance();

	// ＤＸライブラリ使用の終了処理
	DxLib_End();

	// ソフトの終了
	return 0;
}

