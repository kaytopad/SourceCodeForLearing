#include"collison.h"

//衝突判定初期化
void initRect(sHitRect& dstRect, float w, float h)
{
    dstRect.width = w;
    dstRect.hight = h;

    dstRect.worldLX = 0.0f;
    dstRect.worldRX = w;
    dstRect.worldLY = 0.0f;
    dstRect.worldRY = h;
}

//衝突判定座標の更新

void updateWorldRect(sHitRect& dstRect, float x, float y)
{
    dstRect.worldLX = x;
    dstRect.worldLY = y;

    dstRect.worldRX = x + dstRect.width;
    dstRect.worldRY = y + dstRect.hight;
}

//衝突判定を画面に表示
void drawRect(const sHitRect& rect)
{
    DrawBox(static_cast<int>(rect.worldLX), static_cast<int>(rect.worldLY),
        static_cast<int>(rect.worldRX - 1), static_cast<int>(rect.worldRY - 1), GetColor(255, 0, 0),
        FALSE);
}

bool isHitRect(const sHitRect& rect1, const sHitRect& rect2)
{
    return (rect1.worldLX < rect2.worldRX &&
        rect2.worldLX < rect1.worldRX &&
        rect1.worldLY < rect2.worldRY &&
        rect2.worldLY < rect1.worldRY);
}
