#pragma once
#include "DxLib.h"

struct sHitRect
{
    float width;        //当たり矩形幅ピクセル数
    float hight;        //当たり矩形高さピクセル数
    float worldLX;      //左上X座標
    float worldLY;      //左上Y座標
    float worldRX;      //右下X座標
    float worldRY;      //右下Y座標
};

/// <summary>
/// 当たり判定初期化
/// </summary>
/// <param name="dstRect">初期化したい当たり判定変数</param>
/// <param name="w">当たり判定の幅</param>
/// <param name="h">当たり判定高さ</param>
void initRect(sHitRect& dstRect,float w,float h);
//更新(Updat)

/// <summary>
/// 当たり判定の移動更新処理　
/// </summary>
/// <param name="dstRect"> 更新したい当たり判定変数</param>
/// <param name="x"> 当たり判定左上x座標</param>
/// <param name="y"> 当たり判定左上y座標</param>
void updateWorldRect(sHitRect& dstRect,float x,float y);
//描画(Display)


/// <summary>
/// 当たり判定矩形の描画
/// </summary>
/// <param name="rect">描画したい当たり判定矩形</param>
void drawRect(const sHitRect&rect);

//矩形の衝突したかを返す
/// <summary>
/// 二つの矩形が衝突したかを返す
/// </summary>
/// <param name="rect1">矩形1</param>
/// <param name="rect2">矩形2</param>
/// <returns>矩形の二つが衝突したかをtrue/falseで返す</returns>
bool isHitRect(const sHitRect& rect1, const sHitRect& rect2);
