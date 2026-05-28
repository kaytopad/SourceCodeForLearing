#pragma once
#include<stdio.h>
#pragma warning(disable:4996)

/// <summary>
/// 入力チェック関数
/// </summary>
/// <param name="min">最小値</param>
/// <param name="max">最大値</param>
/// <returns>入力値</returns>
int InputCheck(int min, int max);

/// <summary>
/// 成績入力関数
/// </summary>
/// <param name="grades">成績表</param>
/// <param name="index">最大要素数</param>
void inputGrade(int grades[],int index);

/// <summary>
/// 合計点数計算関数
/// </summary>
/// <param name="grades">成績表</param>
/// <param name="index">最大要素数</param>
/// <returns>合計点数</returns>
int totalScore(int grades[], int index);

/// <summary>
/// 平均点計算関数
/// </summary>
/// <param name="sum">合計点数</param>
/// <param name="subject">教科</param>
/// <returns>平均点数</returns>
float averageScore(int sum, int subject);

/// <summary>
/// 教科名出力関数
/// </summary>
/// <param name="subjectNumber">教科番号</param>

void subjectName(int subjectNumber);
