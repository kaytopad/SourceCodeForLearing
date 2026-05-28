#pragma once

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#pragma warning(disable:4996)

//関数のプロトタイプ宣言
int inputCheck(int min, int max);
int keeper();
int judge(int kick, int keper);
void game(int min, int max, int score, int& plyScore, int& emyScore);
void Result(int plyScore, int emyScore);
