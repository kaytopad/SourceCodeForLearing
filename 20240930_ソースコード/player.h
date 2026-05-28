#pragma once
#include "dxlib.h"
#include "collision.h"

/// <summary>
/// プレイヤー初期化
/// </summary>
void playerInit();

/// <summary>
/// プレイヤー更新
/// </summary>
/// <param name="deltaTime">1フレーム分の処理時間</param>
void playerUpdate(float deltaTime);

/// <summary>
/// プレイヤー描画
/// </summary>
void playerDraw();

/// <summary>
/// プレイヤー後始末
/// </summary>
void playerFinalize();

/// <summary>
/// プレイヤーの当たり判定矩形を返す
/// </summary>
/// <returns>プレイヤーの当たり判定矩形</returns>
sHitRect GetPlayerHitRect();

/// <summary>
/// 当たり判定矩形からプレイヤー位置を修正する
/// </summary>
/// <param name="hitRect">当たり判定矩形</param>
void playerfixColPosition(sHitRect& hitRect);

