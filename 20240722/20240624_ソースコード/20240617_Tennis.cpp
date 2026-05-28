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

	//ラケットを設定
	int racketX = WIDTH / 2;
	int racketY = HEIGHT - 50;

	int ballX = X;
	int ballY = Y;
	int ballVx = VX;
	int ballVy = VY;
	int ballR = BALLR;
	int racketW = RACKETWIDTH;
	int racketH = RACKETHIGHT;

	//ゲームの進行に関する変数
	enum 
	{
		TITLE,
		PLAY,
		OVER
	};
	//シーンのセレクトナンバー
	int selectScene = TITLE;
	//タイマー
	int timer = 0;
	//ヒットチェック変数
	int dx, dy;
	//ゲームフレームカウント
	currentTime = lastTime - GetNowCount();

	//乱数の初期化
	SRand(0);

	//スコア変数
	int score = 0;
	int hightScore = 1000;
	//効果音（SE）変数
	int addScore = LoadSoundMem("./Sound/sound1.mp3");
	int hitBar = LoadSoundMem("./Sound/sound2.mp3");
	int updateScore = LoadSoundMem("./Sound/sound3.mp3");


	while (ScreenFlip() == 0 && ProcessMessage() == 0 && ClearDrawScreen() == 0)
	{
		currentTime = GetNowCount();
		//ゲームフレームカウント
		double deltaTime =  (currentTime - lastTime) / 1000.0;

		frameCount += deltaTime;
		ClearDrawScreen();
		timer++;
		switch (selectScene)
		{
		case TITLE:
			//タイトル画面を表示
			SetFontSize(50);
			DrawString(WIDTH / 2 - 50 / 2 * 12 / 2, HEIGHT / 3, "TENNIS GAME", GetColor(255, 69, 0));
			//スタートボタンを点滅させる
			if (timer % 60 < 30)
			{
				SetFontSize(30);
				DrawString(WIDTH / 2 - 30 / 2 * 21 / 2, HEIGHT * 2 / 3, "Press SPACE to start.", GetColor(238, 130, 238));
			}

			//スペースキーを押してゲームスタート
			if (CheckHitKey(KEY_INPUT_SPACE) == 1)
			{
				ballX = X;
				ballY = Y;
				ballVx = VX;
				ballVy = VY;
				ballR = BALLR;
				racketW = RACKETWIDTH;
				racketH = RACKETHIGHT;
				score = 0;
				selectScene = PLAY;
			}


			break;

		case PLAY:
			//ボールを設定
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
				score += 10;
				PlaySoundMem(addScore, DX_PLAYTYPE_BACK);
				if (score > hightScore)
				{
					PlaySoundMem(updateScore,DX_PLAYTYPE_BACK);
					hightScore = score;
				}
				ballVy = -ballVy;
			}
			//if (ballY > HEIGHT && ballVy > 0)
			//{
			//	//ゲームオーバーのフラグを立てる
			//	ballVy = -ballVy;
			//}
			if (ballY > HEIGHT)
			{
				selectScene = OVER;
				timer = 0;
				break;
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

			//跳ね返り
			//ヒットチェック
			dx = ballX - racketX;			//X軸方向の距離
			dy = ballY - racketY;			//Y軸方向の距離
			if (-racketW / 2 -10 < dx && dx < racketW / 2 + 10 && -20 < dy && dy < 0)
			{
				PlaySoundMem(hitBar, DX_PLAYTYPE_BACK);
				ballVy = -5 - GetRand(5);
			}
			//ラケットを描画
			DrawBox(racketX - racketW / 2, racketY - racketH / 2, racketX + racketW / 2, racketY + racketH / 2, 0x0080ff, TRUE);
			//スコアとハイスコアの表示
			SetFontSize(30);
			DrawFormatString(10,10,GetColor(255,255,255), "SCORE : %d",score);
			DrawFormatString(WIDTH -300, 10, GetColor(255, 0, 0), "HIGHTSCORE : %d", hightScore);

			break;
		case OVER:

			//スコア表示
			SetFontSize(30);

			DrawFormatString(WIDTH / 4 - 50 , HEIGHT * 2 / 3, GetColor(224, 255, 255), "SCORE : %d", score);
			DrawFormatString(WIDTH / 4 - 50 , HEIGHT * 3 / 4, GetColor(224, 255, 255), "HIGHTSCORE : %d", hightScore);
			SetFontSize(40);
			DrawString(WIDTH / 2 - 40 / 2 * 9 / 2, HEIGHT / 3, "GAME OVER", GetColor(255, 0, 0));

			if (timer > 60 *5)
			{
				selectScene = TITLE; 
				break;
			}

			break;
		}
		ScreenFlip();


		lastTime = currentTime;
	}

	//DXライブラリ使用の終了
	DxLib_End();
	return 0;

}