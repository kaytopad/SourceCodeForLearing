#pragma once
#include"DxLib.h"
#include "collison.h"
/// <summary>
///　マップの初期化
/// </summary>
void mapInit();


/// <summary>
///　マップの描画
/// </summary>
void mapDraw();

/// <summary>
///　マップの後始末
/// </summary>
void mapFinalize();

/// <summary>
/// マップの当たり判定
/// </summary>
/// <param name ="checkRect">マップと当たっているか調査したい矩形</param>
/// <returns>マップと衝突したかをtrue/falseで返す</returns>
bool mapHitCalc(sHitRect& checkRect);