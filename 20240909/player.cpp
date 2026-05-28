#include "player.h"
#include "collision.h"

const int animPatternNum = 3;     // アニメーションのパターン数
const int animDown       = 0;     // 下方向
const int animLeft       = 1;     // 左方向
const int animRight      = 2;     // 右方向
const int animUp         = 3;     // 上方向
const int animTypeNum    = 4;     // アニメーションの種類
const float animationFPS = 6.0f;  // 秒間 6コマのアニメーション
const float moveSpeed    = 200.0f;// 移動速度 (ここで指定した値分のピクセル/秒進む) 

const int   imageSizeX   = 64;    // 画像横サイズ
const int   imageSizeY   = 96;    // 画像縦サイズ
const int   hitSizeX     = 40;    // 当たり判定サイズ幅
const int   hitSizeY     = 60;    // 当たり判定サイズ高さ

float px, py;                     // プレイヤーの座標
float vx, vy;                     // プレイヤーの速度
float animTimer;                  // アニメーションタイマー
int   animNowType;                // 現在のアニメ種類
int   animNowPattern ;            // 現在のアニメパターン
int   animNowIndex;               // アニメーション画像配列の添え字 0～11までの数値
int   drawOffsetX;                // 当たり判定からの横方向ずらし量
int   drawOffsetY;                // 当たり判定からの縦方向ずらし量

int playerImg[animPatternNum * animTypeNum]; // プレイヤーの画像ハンドル

sHitRect playerHit;

void playerInit()
{
	px = 100.0f;
	py = 100.0f;
	vx = 0.0f;
	vy = 0.0f;
	animTimer = 0.0f;

	animNowType = animDown;     // 正面向きアニメーション種類
	animNowPattern = 0;         // 
	
	animNowIndex = 0;

	// 当たり判定初期化
	initRect(playerHit, hitSizeX, hitSizeY);

	// 横3 縦4 計12枚の画像ファイルの読み込み
	LoadDivGraph("img/chara.png", animPatternNum * animTypeNum, animPatternNum, animTypeNum, imageSizeX, imageSizeY, playerImg);

	// 描画位置のオフセット値を計算
	// 左右から見てセンター、上下方向は底辺基準となるように計算
	drawOffsetX = (hitSizeX - imageSizeX) / 2;
	drawOffsetY = (hitSizeY - imageSizeY);

}

void playerUpdate(float deltaTime)
{
	///////////////////////////////////////////
	// 入力処理
	///////////////////////////////////////////
	bool isMove = false;

	if (CheckHitKey(KEY_INPUT_UP))
	{
		vy = -moveSpeed;
		animNowType = animUp;
		isMove = true;
	}
	if (CheckHitKey(KEY_INPUT_DOWN))
	{
		vy = +moveSpeed;
		animNowType = animDown;
		isMove = true;
	}
	if (CheckHitKey(KEY_INPUT_LEFT))
	{
		vx = -moveSpeed;
		animNowType = animLeft;
		isMove = true;
	}
	if (CheckHitKey(KEY_INPUT_RIGHT))
	{
		vx = +moveSpeed;
		animNowType = animRight;
		isMove = true;
	}

	// キー入力より移動速度求める
	if (isMove)
	{
		vx *= deltaTime;
		vy *= deltaTime;
	}
	else
	{
		vx = 0.0f;
		vy = 0.0f;
	}	
	// 位置更新
	px += vx;
	py += vy;
	// 当たり判定位置更新
	updateWorldRect(playerHit, px, py);

	////////////////////////////
	// アニメーション計算
	////////////////////////////
	if (isMove)
	{
		// animTimer で時間経過を測り、 1.0 / animationFPS →次のアニメーションパターンに進んでよい秒数に
		// なったら次のコマに進める
		animTimer += deltaTime;
		if (animTimer > 1.0f / animationFPS)
		{
			// タイマーを0に 次のパターンに進めるが、animPetternNumを超えないようにループさせる
			animTimer = 0.0f;
			animNowPattern++;
			animNowPattern %= animPatternNum; // 余りなので 0,1,2のいずれかになる
		}
	}
	else
	{
		animNowPattern = 1; // 静止時は足をそろえたパターンに強制する
	}

	// 最終的な添え字を計算 
	// 添え字 = 一つのパターンのコマ数 + アニメーション種類 * １つのアニメーションのパターン枚数
	animNowIndex = animNowPattern + animNowType * animPatternNum;

}

void playerDraw()
{
	// 描画位置は
	DrawGraph(static_cast<int>(px) + drawOffsetX, static_cast<int>(py) + drawOffsetY, playerImg[animNowIndex], TRUE);
	drawRect(playerHit);
}


void playerFinalize()
{
	if (playerImg[0] != -1)
	{
		for (int i = 0; i < animPatternNum * animTypeNum; i++)
		{
			DeleteGraph(playerImg[i]);
		}
	}
}

sHitRect GetPlayerHitRect()
{
	return playerHit;
}


void playerfixColPosition(sHitRect& hitRect)
{
	px = hitRect.worldLX;
	py = hitRect.worldLY;

	playerHit = hitRect;
}