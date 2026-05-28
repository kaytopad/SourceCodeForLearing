#include "DxLib.h"//Dxライブラリーをインクルード（読み込み）

int WinMain(HINSTANCE, HINSTANCE, LPSTR, int)//Windowsのメインで動かす
{

	//基本設計
	ChangeWindowMode(TRUE);//Windowsの画面をアクティブにする
	DxLib_Init();//DxLibの初期化
	SetDrawScreen(DX_SCREEN_BACK);//画面の背景は黒
	SetGraphMode(800, 600, 32);//画面の大きさ
 
	//DxLibの初期化処理
	if (DxLib_Init() == -1)
	{
	//エラーが起きたら直ちに終了
		return -1;
	}
	//文字の位置
	int stringX = 10;
	int strinhY = 15;
	int stringX1 = 10;
	int strinhY1 = 50;
	//円の初期位置
	int circleX = 150;
	int circleY = 200;
	//マウスの座標
	int mouseX = 0;
	int mouseY = 0;
	//円の色指定
	int circleColor = GetColor(0, 0, 255);
	//文字の色指定
	int StringColor = GetColor(255, 255, 255);
	int StringColor2 = GetColor(255, 0, 0);

	//ゲームループ
	while (ProcessMessage()==0 && CheckHitKey(KEY_INPUT_ESCAPE) == 0)
	{
		//画面の初期化
		ClearDrawScreen();
		//画面に円を描画させる
		DrawCircle(circleX, circleY, 30, circleColor, TRUE);
		//マウスの座標を取得
		GetMousePoint(&mouseX,&mouseY);
		//マウスがクリックされたら
		if ((GetMouseInput()&MOUSE_INPUT_LEFT ) )
		{
			SetFontSize(30);
			DrawString(stringX1,strinhY1,"Hit!",StringColor2);
		}
		//テンキーの上を押したら上に動く
		if (CheckHitKey(KEY_INPUT_UP))
		{
			//円のY座標が40より小さくなったら
			if (circleY <= 40)
			{
				circleY += 3;
			}
			else
			{
				circleY -= 3;
			}
		}
		//テンキーの下を押したら下に動く
		if (CheckHitKey(KEY_INPUT_DOWN))
		{
			if (circleY >= 560)
			{
				circleY -= 3;
			}
			else
			{
				circleY += 3;
			}

		}
		//テンキーの左を押したら左に動く
		if (CheckHitKey(KEY_INPUT_LEFT))
		{
			if (circleX <= 40)
			{
				circleX += 3;
			}
			else
			{
				circleX -= 3;
			}

		}
		//テンキーの右を押したら右に動く
		if (CheckHitKey(KEY_INPUT_RIGHT))
		{
			if (circleX >= 740)
			{
				circleX -= 3;
			}
			else
			{
				circleX += 3;
			}

		}


		//文字の大きさの指定
		SetFontSize(32);
		//画面に文字表示
		//DrawString(10,15,"HelloWould",StringColor);
		DrawFormatString(stringX, strinhY, StringColor, "Mouse X:%d Y:%d", mouseX, mouseY);
		//裏画面の内容を表画面に反映させる
		ScreenFlip();

	}

	//Dxlib使用の終了処理
	DxLib_End();
	//ソースの終了
	return 0;
}