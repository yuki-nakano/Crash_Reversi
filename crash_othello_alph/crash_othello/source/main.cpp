﻿#include "common.h"
#include "othello.h"
#include "GameManager.h"

int WINAPI WinMain(
	_In_ HINSTANCE hInstance,
	_In_opt_ HINSTANCE hPrevInstance,
	_In_ LPSTR lpCmdLine,
	_In_ int nCmdShow)
{
	SetOutApplicationLogValidFlag(false);
	ChangeWindowMode(true);
	SetGraphMode(Widht, Height, 16);
	SetBackgroundColor(255, 255, 255);
	SetMainWindowText("クラッシュリバーシ");

	if (DxLib_Init() == -1)		// ＤＸライブラリ初期化処理
	{
		return -1;			// エラーが起きたら直ちに終了
	}

	//描画先を裏の画面に設定
	SetDrawScreen(DX_SCREEN_BACK);

	//管理クラスの作成
	SoundManager::CreateInstance();
	Othello::CreateInstance();
	GameManager::CreateInstance();
	SceneManager* pSceneMng = new SceneManager();

	while (true)
	{
		// メッセージループに代わる処理をする
		if (ProcessMessage() == -1 || 
			(IsKeyHeld(KEY_INPUT_SPACE) && 
			IsKeyPushed(KEY_INPUT_ESCAPE) == 1))
		{
			break;        // エラーが起きたらループを抜ける
		}
		else
		{


			//フレームごとにキーの状態更新
			UpdateKeyStatus();
			
			ClearDrawScreen();
			clsDx();

			//シーン処理
			pSceneMng->Exec();

			//シーン描画
			pSceneMng->Draw();

			ScreenFlip();
		}
	}

	SoundManager::DeleteInstance();
	Othello::DeleteInstance();
	GameManager::DeleteInstance();
	delete pSceneMng;
	pSceneMng = nullptr;

	DxLib_End();	// ＤＸライブラリ使用の終了処理
	return 0;		// ソフトの終了 
}
