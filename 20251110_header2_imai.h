#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#pragma warning(disable:4996)


/// <summary>/// 
/// ソート関数
/// </summary>/// 
/// <param name="strNumber">入力配列</param>/// 
/// <param name="index">添え字</param>/// 
/// <returns>正解or不正解</returns>
bool isSorted(int strNumber[], int index);

/// <summary>/// 
/// 入力チェック関数
/// </summary>/// 
/// <param name="min">最小値</param>/// 
/// <param name="max">最大値</param>/// 
/// <returns>入力結果</returns>
int checkInput(int min,int max);

void displayNumbers(int strNumbers[],int index);