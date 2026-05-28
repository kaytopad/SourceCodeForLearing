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

void scrollUpdate(float deltaTime, float playerX)
{
    //スクリーン幅
    float centerX = screenWidth / 2;
    
    //右側に行ったとき
    if (playerX > centerX + scrollx && scrollx < scrollXMax)
    {
        scrollx = playerX - centerX;
        if (scrollx > scrollXMax)
        {
            scrollx = scrollXMax;
        }
    }
    //左側に行ったとき
    else if (playerX < centerX + scrollx && scrollx > 0)
    {
        scrollx = playerX - centerX;
        if (scrollx < 0)
        {
            scrollx = 0;
        }

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
