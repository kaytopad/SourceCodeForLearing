#include"DxLib.h"
#include "Player.h"
#include"map.h"
#include "collison.h"

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
	//マップの初期化
	mapInit();
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

		//プレイヤーの当たり判定矩形
		sHitRect playerRect;
		playerRect = GetPlayerHitRect();

		//マップに当たっているかをhitに格納
		bool hit;
		hit = mapHitCalc(playerRect);
		//画面の更新処理
		ClearDrawScreen();

		//マップ描画
		mapDraw();
		//プレイヤー描画
		playerDraw();

		if (hit)
		{
			DrawString(100, 800, "当たった", GetColor(255, 255, 255));
		}

		ScreenFlip();

		//1フレームの処理が終わったら、現在の時刻は1フレーム前の時刻なる
		prevCount = nowCount;
	}

	//プレイヤー後始末
	playerFinalize();
	//マップ後始末
	//終了
	DxLib_End();
	return 0;
}