#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#pragma warning(disable:4996)
//定数
const int STU_HPMP_MAX = 38;
const int STU_HPMP_MIN = 18;
const int STU_SKL_MAX = 26;
const int STU_SKL_MIN = 5;

/// <summary>
/// ステータス構造体
/// </summary>
typedef struct status
{
    char name[128];
    int HP;
    int MP;
    int ATK;
    int DEF;
    int AGI;
    int gernder;
    int tribe;
}Status;

/// <summary>
/// キャラクター作成関数
/// </summary>
/// <param name="charcter">キャラクター構造体配列</param>
/// <param name="index">最大要素数</param>
void charcterCreate(Status charcter[],int index);

/// <summary>
/// 入力チェック関数
/// </summary>
/// <param name="min">最小値aram>
/// <param name="max">最大値</param>
/// <returns></returns>
int inputCheck(int min,int max);

/// <summary>
/// 能力値修正関数
/// </summary>
/// <param name="charcter">キャラクター構造体配列</param>
/// <param name="index">最大要素数</param>
void abillityCorrection(Status charcter[],int index );

/// <summary>
/// パーティー表示関数
/// </summary>
/// <param name="charcter">キャラクター構造体配列</param>
/// <param name="index">最大要素数</param>
void displayParty(Status party[], int index);

/// <summary>
/// 性別表示関数
/// </summary>
/// <param name="gen">性別判定</param>
void genderDisplay(int gen);

/// <summary>
/// 種族表示関数
/// </summary>
/// <param name="tri">種族判定</param>
void tribeDisplay(int tri);


