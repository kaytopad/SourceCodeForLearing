#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#pragma warning(disable:4996)

/// <summary>
/// 最小値検出関数
/// </summary>
/// <param name="arr">配列へのポインタ</param>
/// <param name="size">配列の要素</param>
/// <returns>最小値</returns>
int* find_min(int* arr, int size);
