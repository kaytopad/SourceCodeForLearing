#pragma once

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#pragma warning(disable:4996)

//定数
const int NUM_MAX = 10;
const int NUM_MIN = 0;

/// <summary>
/// ゲーム関数
/// </summary>
/// <param name="ply">プレイヤーカード</param>
/// <param name="emy">CPUカード</param>
/// <param name="index"></param>
void Game(int ply[],int emy[],int index);

/// <summary>
/// 判定関数
/// </summary>
/// <param name="input">入力した解答</param>
/// <param name="ans">当てられる解答</param>
/// <param name="index">最大要素数</param>
/// <returns>正解or不正解</returns>
bool Judgement(int input[], int ans[],int index);

/// <summary>
/// 入力チェック関数
/// </summary>
/// <param name="min">最小値</param>/// 
/// <param name="max">最大値</param>/// 
/// <returns>入力値</returns>
int InputCheck(int min, int max);

/// <summary>///
/// カード生成関数
/// </summary>/// 
/// <param name="crad">カード配列</param>/// 
/// <param name="index">最大要素数</param>
void createCrad(int crad[], int index);

/// <summary>
/// 解答入力関数
/// </summary>/// 
/// <param name="inputAry">入力配列</param>/// 
/// <param name="index">最大要素数</param>
void inputNumber(int inputAry[], int index);

/// <summary>
/// 表示関数
/// </summary>
/// <param name="card">表示したい関数</param>
/// <param name="index">最大要素数</param>
void displayCard(int card[], int index);