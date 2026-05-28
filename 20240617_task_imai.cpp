/*
以下の内容に沿ったプログラムを作成しましょう。
CPUと対戦ゲーム「どっちの数字が大きいか」を作成しましょう。
0〜50までのランダムな数字を10個配布されます。
その中から、プレイヤーとCPUは一つ選択します。
※プレイヤーは1番目から10番目は選択できます。CPUはランダムで選択します。
※注意：一度使った番号はそれ以降使うことはできません。
その時に、数字を大きい方に3点追加されます。
引き分けならお互いに1点ずつ追加されます。
それを7回繰り返して、得点の多い方が勝者となります。
*/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#pragma warning(disable:4996)

//定数
const int INDEX = 10;
const int ROUND = 7;
const int NUM_MAX = 50;
const int NUM_MIN = 0;
const int WIN_POINT = 3;
const int DRAW_POINT = 1;

int main(void)
{
	//変数宣言
	int i,j;
	int gameCnt;
	int ply, emy;						//プレイヤーとCPUの選択変数
	int plyPoint = 0, emyPoint = 0;		//プレイヤーとCPUの得点
	int plyHand[INDEX][INDEX] = {0,0};		//プレイヤー手札
	int emyHand[INDEX][INDEX] = {0,0};		//CPU手札
	//乱数の初期化
	srand((unsigned int)time(NULL));
	//プレイヤーとCPUの手札配布
	for ( i = 0; i < INDEX; i++)
	{
		plyHand[0][i] = rand() % NUM_MAX + 1;
		emyHand[0][i] = rand() % NUM_MAX + 1;
	}
	//プレイヤー手札公開
	for ( i = 0; i < INDEX; i++)
	{
		printf("player:%d番目：%d\n", i + 1, plyHand[0][i]);
	}
	printf("\n");
	//ゲームループ
	for ( gameCnt = 0; gameCnt < ROUND; gameCnt++)
	{
		printf("どちらの数字が大きいでしょう？？\n手札を選択して、大きい方が得点を獲得できます。");
		printf("手札を選択してください。\n");

		//出す手札を選択（入力チェックあり）
		while (true)
		{
			scanf("%d", &ply);
			//添え字を調整する
			ply--;
			if (NUM_MIN > ply || INDEX <= ply)
			{
				printf("入力に誤りがあります。再度入力してください。\n");
			}
			else if (plyHand[1][ply])
			{
				printf("そこは選択できません。再度違う番号を選択してください。\n");
			}
			else
			{
				break;
			}
		}

		plyHand[1][ply] = 1;

		//CPUのカード選択
		while (true)
		{
			//乱数で選択
			emy = rand() % INDEX;
			if (emyHand[1][emy] == 0)
			{
				break;
			}

		}

		printf("PLAYERNUMBER %d vs ENEMYNUMBER %d\n",plyHand[0][ply],emyHand[0][emy]);
		//勝負の結果ポイント加算
		if (plyHand[0][ply] > emyHand[0][emy])
		{
			plyPoint += WIN_POINT;
			printf("PLAYER win!\n");
		}
		else if (plyHand[0][ply] == emyHand[0][emy])
		{
			plyPoint += DRAW_POINT;
			emyPoint += DRAW_POINT;
		}
		else
		{
			emyPoint += WIN_POINT;
			printf("CPU win\n");
		}


		//残りの手札公開&得点
		for ( i = 0; i < INDEX; i++)
		{
			if (plyHand[1][i] == 0)
			{
				printf("%d番目：%d\n", i + 1, plyHand[0][i]);
			}
		}

		printf("PLAYER %d vs ENEMY %d \n", plyPoint, emyPoint);

	}

	//7回勝負終了、結果の表示
	if (plyPoint > emyPoint)
	{
		printf("PLAYER WINNER\n");
	}
	else  if (plyPoint == emyPoint)
	{
		printf("DRAW\n");
	}
	else
	{
		printf("CPU WINNER\n");
	}



	return 0;
}