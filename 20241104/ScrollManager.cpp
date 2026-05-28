#include "ScrollManeger.h"
#include "collision.h"
#pragma warning(disable:4996)

//スクロールX方向値
float scrollx;

//スクリーン幅
int screenWidth;
//スクリーン高さ
int screenHeight;
//ステージ全体のX方向最大値
float scrollXMax;

//スクリーンのワールド空間上の矩形範囲
sHitRect worldScreenRect;

//スクリーンの移動速度
const float scrollSpeed = 0.7f;

void scrollManagerInit(int _screenWidth, int _screenHeight, const sHitRect& worldRect)
{
    //スクリーンの幅
    screenWidth = _screenWidth;
    //スクリーンの高さ
    screenHeight = _screenHeight;
    scrollXMax = worldRect.worldRX - screenWidth;

    initRect(worldScreenRect, static_cast<float>(_screenWidth), static_cast<float>(_screenHeight));

}

void scrollUpdate(float deltaTime)
{
    //スクリーンの移動
    scrollx += scrollSpeed;
    //最大値（右端）に行ったら動きを止める
    if (scrollx > scrollXMax)
    {
        scrollx = scrollXMax;
    }

    //スクリーンのワールド座標更新
    updateWorldRect(worldScreenRect, scrollx, 0.0f);

}

int scrollGetDrawOffsetx()
{
    return static_cast<int>(scrollx);
}

sHitRect scrollGetWorldScreenRect()
{
    return worldScreenRect;

}
