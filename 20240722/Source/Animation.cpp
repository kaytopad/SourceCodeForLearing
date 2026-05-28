#include"DxLib.h"
#include "Player.h"
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	//----------------------------------// 
	//基本設定
	//----------------------------------// 
	ChangeWindowMode(TRUE);
	SetGraphMode(1440, 960, 16);
	if (DxLib_Init() == -1)
	{
		return  -1;

	}

	//プレイヤーの初期化
	playerInit();

	int nowCount, prevCount;
	nowCount = prevCount = GetNowCount();

	while (ScreenFlip() == 0 && ProcessMessage() == 0 && ClearDrawScreen() == 0)
	{
		//deltatime
		float deltatime;
		nowCount = GetNowCount();
		deltatime = (nowCount - prevCount) / 1000.0f;
		//更新処理
		playerUpdate(deltatime);
		//画面の更新処理
		ClearDrawScreen();

		//プレイヤー描画
		playerDraw();


		ScreenFlip();

		//1フレームの処理が終わったら、現在の時刻は1フレーム前の時刻なる
		prevCount = nowCount;
	}

	//プレイヤー後始末
	playerFinalize();
	//終了
	DxLib_End();
	return 0;
}