#pragma once
#include<stdio.h>
#pragma warning(disable:4996)

/// <summary>
/// 入力チェック関数
/// </summary>
/// <param name="min">最小値</param>
/// <param name="max">最大値</param>
/// <param name="tmp">入力値</param>
void checkInput(int min, int max,int *tmp);

/// <summary>
/// 成績表入力関数
/// </summary>
/// <param name="grade">成績表配列ポインター</param>
/// <param name="size">配列のインデックス</param>
void gradeBook(int *grade,int size);

/// <summary>
/// 計算関数
/// </summary>
/// <param name="greade">成績表配列ポインター</param>
/// <param name="sum">合計点数</param>
/// <param name="avg">平均点数</param>
/// <param name="size">配列のインデックス</param>
void calculattion(int* greade,int *sum,double *avg,int size);

/// <summary>
/// 表示巻子
/// </summary>
/// <param name="number">科目ナンバー</param>
void display(int number);

