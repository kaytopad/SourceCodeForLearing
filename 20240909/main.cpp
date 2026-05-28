#include <windows.h>
#include "DxLib.h"
#include "player.h"
#include "map.h"
#include "collision.h"

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{

	// DxLib初期化
	ChangeWindowMode(TRUE);
	SetGraphMode(1440, 900, 16);

	if (DxLib_Init() == -1)
	{
		return -1;
	}

	playerInit();
	mapInit();

	int nowCount, prevCount;
	nowCount = prevCount = GetNowCount();
	// ゲームループ
	while (ProcessMessage() == 0 && CheckHitKey(KEY_INPUT_ESCAPE) == 0)
	{
		// deltaTime計測
		float deltaTime;
		nowCount = GetNowCount();
		deltaTime = (nowCount - prevCount) / 1000.0f;
		
		//更新処理
		playerUpdate(deltaTime);

		// プレイヤーの当たり判定矩形
		sHitRect playerRect;
		playerRect = GetPlayerHitRect();

		// マップと当たっているかをhitに格納
		bool hit;
		hit = mapHitCalc(playerRect);

		//画面更新処理
		ClearDrawScreen();

		// マップ描画
		mapDraw();

		//プレイヤー描画
		playerDraw();

		// ヒットしたか?を画面表示
		if (hit)
		{
			//DrawString(100, 800, "当たった", GetColor(255, 255, 255));
			playerfixColPosition(playerRect);
		}

		ScreenFlip();

		prevCount = nowCount;
	}

	playerFinalize();
	mapFinalize();

	DxLib_End();
	return 0;
}

