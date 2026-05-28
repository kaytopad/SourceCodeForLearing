#pragma once
#include "DxLib.h"

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
///　プレイヤー描画
/// </summary>
void playerDraw();

/// <summary>
///　プレイヤー後始末
/// </summary>
void playerFinalize();