#include "Player.h"
#include "collison.h"

//定数
const int animPatterNum = 3;        //アニメーションのパターンの数
const int animDown = 0;             //下向き
const int animLeft = 1;             //左向き
const int animRight = 2;            //右向き
const int animUp = 3;               //上向き
const int animTypeNum = 4;          //アニメーションの種類
const float animationFPS = 6.0f;    //秒間6コマでアニメーション
const float moveSpeed = 100.0f;     //移動速度

///---------------------------------------------------///
//---------------追加：2024年9月2日追加---------------///
///---------------------------------------------------///
const int imageSizeX = 64;          //画像横サイズ
const int imageSizeY = 94;          //画像縦サイズ
const int hitSizeX = 40;            //当たり判定サイズ幅
const int hitSizeY = 60;            //当たり判定サイズ高さ

//変数
float px, py;                       //プレイヤーの座標
float vx, vy;                       //プレイヤーの速度
float animTimer;                    //アニメーションタイマー
int animNowType;                    //現在のアニメ種類
int animNowPattern;                 //現在のアニメパターン
int animNowIndex;                   //アニメーション画像配列の添え字
///---------------------------------------------------///
//---------------追加：2024年9月2日追加---------------///
///---------------------------------------------------///
int drawOffsetX;                    //当たり判定からの横方向ずらし量
int drawOffsetY;                    //当たり判定からの縦方向ずらし量


int playerImg[animPatterNum * animTypeNum];     //プレイヤーの画像ハンドル

//当たり判定構造体をプレイヤーで生成
sHitRect playerHit;

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

    //当たり判定初期化
    initRect(playerHit, hitSizeX, hitSizeY);

    //画像ファイルの読み込み
    LoadDivGraph("img/chara.png", animPatterNum * animTypeNum, animPatterNum, animTypeNum, 64, 96, playerImg);

    //描画位置のオフセット値を計算
    //左右から見てセンター、上下方向は底辺基準となるように計算
    drawOffsetX = (hitSizeX - imageSizeX) / 2;
    drawOffsetY = (hitSizeY - imageSizeY);

}
//アニメーション更新

void playerUpdate(float deltaTime)
{
    //移動フラグ
    bool isMove = false;
    //移動する方向を変更させる
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

    //移動速度
    if (isMove)
    {
        vx *= deltaTime;
        vy *= deltaTime;
    }
    else {
        vx = 0.0f;
        vy = 0.0f;
    }

    //位置の更新
    px += vx;
    py += vy;

    //当たり判定位置更新
    updateWorldRect(playerHit, px, py);

    //アニメーションの計算
    if (isMove)
    {
        animTimer += deltaTime;
        if (animTimer > 1.0 /animationFPS)
        {
            animTimer = 0.0f;
            animNowPattern++;
            animNowPattern %= animPatterNum;
        }

    }

    else
    {
        //静止時は足をそろえたパターンに強制
        animNowPattern = 1;
    }

    animNowIndex = animNowPattern + animNowType * animPatterNum;

}

//アニメーションの描画
void playerDraw()
{
    DrawGraph(static_cast<int>(px), static_cast<int>(py),playerImg[animNowIndex],TRUE);
    drawRect(playerHit);
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

sHitRect GetPlayerHitRect()
{
    return playerHit;
}