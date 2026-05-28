#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#pragma warning(disable:4996)

//定数
const int OUTCOUNT = 3;
const int RUNNERCOUNT = 4;
const int STRIKCOUNT = 3;
const int BALLCOUNT = 4;



/// <summary>
/// プレイイニング関数
/// </summary>
/// <param name="team">攻撃/守備フラグ</param>
/// <returns>得点</returns>
int playInning(bool team);

/// <summary>
/// 球種画面表示
/// </summary>
/// <param name="pitch">投げた球</param>
void displayPitchtype(int pitch);
/// <summary>
/// ホームラン確率
/// </summary>
/// <returns>ホームラン率</returns>
int getHomerun();
/// <summary>
/// ヒット＆ストライク確率
/// </summary>
/// <returns>確率</returns>
int getHitAndStrikeChance();

/// <summary>/// 
/// 入力チェック関数
/// </summary>/// 
/// <param name="min">最小値</param>/// 
/// <param name="max">最大値</param>/// 
/// <returns>入力</returns>
int checkInput(int min, int max);

/// <summary>///
/// 打席関数
/// </summary>/// 
/// <param name="Batter">バッターの入力値</param>/// 
/// <param name="Pitcher">ピッチャーの入力値</param>/// 
/// <returns>得点</returns>
int TrunofBatter(int Batter, int Pitcher);