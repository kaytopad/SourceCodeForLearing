#include "Player.h"

//定数
const int animPatterNum = 3;        //アニメーションのパターンの数
const int animDown = 0;             //下向き
const int animLeft = 1;             //左向き
const int animRight = 2;            //右向き
const int animUp = 3;               //上向き
const int animTypeNum = 4;          //アニメーションの種類
const float animationFPS = 6.0f;    //秒間6コマでアニメーション
const float moveSpeed = 100.0f;     //移動速度

//変数
float px, py;                       //プレイヤーの座標
float vx, vy;                       //プレイヤーの速度
float animTimer;                    //アニメーションタイマー
int animNowType;                    //現在のアニメ種類
int animNowPattern;                 //現在のアニメパターン
int animNowIndex;                   //アニメーション画像配列の添え字

int playerImg[animPatterNum * animTypeNum];     //プレイヤーの画像ハンドル

//プレイヤーの初期化
void playerInit()
{
    px = 100.0f;
    py = 100.0f;
    vx = 0.0f;
    vy = 0.0f;
    animTimer = 0.0f;

    //現在のアニメ種類
    animNowType = animDown;
    //アニメのパターン
    animNowPattern = 0;

    animNowIndex = 0;

    //画像ファイルの読み込み
    LoadDivGraph("img/chara.png", animPatterNum * animTypeNum, animPatterNum, animTypeNum, 64, 96, playerImg);

}
//アニメーション更新

void playerUpdate(float deltaTime)
{
    //アニメーションの計算
    animTimer += deltaTime;
    if (animTimer > 1.0 /animationFPS)
    {
        animTimer = 0.0f;
        animNowPattern++;
        animNowPattern %= animPatterNum;
    }

    animNowIndex = animNowPattern + animNowType * animPatterNum;

}

//アニメーションの描画
void playerDraw()
{
    DrawGraph(static_cast<int>(px), static_cast<int>(py),playerImg[animNowIndex],TRUE);
}

void playerFinalize()
{
    if (playerImg[0] != 1)
    {
        for (int i = 0; i < animPatterNum * animTypeNum; i++)
        {
            DeleteGraph(playerImg[i]);
        }
    }
}