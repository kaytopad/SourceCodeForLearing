#pragma once

//定数
const int MIN_CARD = 1;
const int MAX_CARD = 11;
const int BURST_NUM = 21;
const int DROW_CARD = 2;


//関数プロトタイプ宣言
int inputCheck(int min, int max);
int drowCard();
bool judge(int ply, int emy);
int playerTrun(int sum);
int enemyTrun(int ply, int emy);
void Result(int plySum, int emySum);
