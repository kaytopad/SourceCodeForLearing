#include"DxLib.h"

//各定数
const int WIDTH = 800;			//画面の幅
const int HEIGHT = 600;			//画面の高さ
const int X = 40;			//初期のX座標
const int Y = 80;				//初期のY座標
const int VX = 5;				//ｘの速度
const int VY = 5;				//ｙの速度
const int BALLR = 10;			//ボールの半径
const int RACKETWIDTH = 120;	//ラケット幅
const int RACKETHIGHT = 12;		//ラケット高さ

double frameCount = 0;
int lastTime, currentTime;

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	//----------------------------------// 
	//基本設定
	//----------------------------------// 

	ChangeWindowMode(TRUE);				//ウィンドウモードにする
	DxLib_Init();						//ライブラリを初期化 Initialise
	SetMainWindowText("TennisGame");
	SetDrawScreen(DX_SCREEN_BACK);		//背景をセットする
	SetGraphMode(WIDTH, HEIGHT, 32);			//ウィンドウのサイズとカラーモードを決める
	//ライブラリ初期化でエラー起きたら終了
	if (DxLib_Init() == -1)
	{
		return -1;
	}
	//ボールを設定
	int ballX = X;
	int ballY = Y;
	int ballVx = VX;
	int ballVy = VY;
	int ballR = BALLR;

	//ラケットを設定
	int racketX = WIDTH / 2;
	int racketY = HEIGHT - 50;
	int racketW = RACKETWIDTH;
	int racketH = RACKETHIGHT;

	//ゲームフレームカウント
	currentTime = lastTime - GetNowCount();

	//乱数の初期化
	SRand(0);

	while (ScreenFlip() == 0 && ProcessMessage() == 0 && ClearDrawScreen() == 0)
	{
		currentTime = GetNowCount();
		//ゲームフレームカウント
		double deltaTime =  (currentTime - lastTime) / 1000.0;

		frameCount += deltaTime;
		ClearDrawScreen();
		//ボールの処理
		//X軸への移動
		ballX = ballX + ballVx;
		if (ballX < ballR && ballVx < 0)
		{
			ballVx = -ballVx;
		}
		if (ballX > WIDTH - ballR && ballVx > 0)
		{
			ballVx = -ballVx;
		}
		//Ｙ軸への移動
		ballY = ballY + ballVy;
		if (ballY < ballR && ballVy < 0)
		{
			ballVy = -ballVy;
		}
		if (ballY > HEIGHT && ballVy > 0)
		{
			ballVy = -ballVy;
		}
		DrawCircle(ballX, ballY, ballR, GetColor(255, 255, 255), TRUE);

		//ラケットの処理を記載する
		//左に進
		if (CheckHitKey(KEY_INPUT_LEFT) == 1)
		{
			racketX = racketX - 10;
			//左に行ったとき
			if (racketX < racketW / 2)
			{
				racketX = racketW / 2;
			}
		}
		//右に進む
		if (CheckHitKey(KEY_INPUT_RIGHT) == 1)
		{
			racketX = racketX + 10;
			if (racketX > WIDTH - racketW /2)
			{
				racketX = WIDTH - racketW / 2;
			}
		}

		//ラケットを描画
		DrawBox(racketX - racketW / 2, racketY - racketH / 2, racketX + racketW / 2, racketY + racketH / 2, 0x0080ff, TRUE);
		ScreenFlip();

		//ヒットチェック
		int dx = ballX - racketX;			//X軸方向の距離
		int dy = ballY - racketY;			//Y軸方向の距離
		//跳ね返り
		if (-racketW / 2 -10 < dx && dx < racketW / 2 + 10 && -20 < dy && dy < 0)
		{
			ballVy = -5 - GetRand(5);
		}
		lastTime = currentTime;
	}

	//DXライブラリ使用の終了
	DxLib_End();
	return 0;

}