#include <stdio.h>
#include<stdlib.h>
#include<time.h>
#pragma warning(disable:4996)
/*
PK戦
プレイヤーとCPUで交互にキッカーとキーパーの役目を行い、5回行いましょう。
蹴る方向は、0:左　1:正面　2:右となります。
同じ方向なら止められて得点にはなりません。異なれば得点となります。
3点先に先取した方が勝ちとなります。
同点であれば、サドンデス（延長戦）となり、どちらかが多く得点を取った方が勝ちとします。
最終的に、どちらが勝ったかを表示させましょう。
*/

void kickDirection(int NUM)
{
	switch (NUM)
	{
		case 0:
			printf("Left\n");
			break;
		case 1:
			printf("Front\n");
			break;
		case 2:
			printf("Right\n");
			break;

	}
}

void judgment(int plyScore, int emyScore)
{
	if (plyScore > emyScore)
	{
		printf("PLAYER WINNER!!\n");
	}
	else
	{
		printf("ENEMY WINNER!!\n");
	}

}
int main(void)
{
	//変数宣言
	int plyScore = 0, emyScore = 0;
	int ply, emy;
	int round = 0;
	int maxRound = 5;
	//乱数の初期化
	srand((unsigned int)time(NULL));
	//ゲーム開始
	while (plyScore != 3 && emyScore != 3 || plyScore == emyScore)
	{
		//ラウンドカウントアップ
		round++;
		//プレイヤーターン
		printf("PlayerTurn\n");
		emy = rand() % 3;
		//printf("%d", emy);
		while (true)
		{
			scanf("%d", &ply);
			if (0 > ply || 3 < ply)
			{
				printf("入力に誤りがあります。再度入力して下さい。\n");
			}
			else
			{
				break;
			}
		}
		//判定

		printf("PLAYER:");
		kickDirection(ply);
		printf("ENEMY:");
		kickDirection(emy);
		printf("\n");
		if (ply != emy)
		{
			printf("Goal\n");
			plyScore++;
		}
		else
		{
			printf("Stop!\n");
		}
		//CPUターン
		printf("EnemyTurn\n");
		emy = rand() % 3;
		//printf("%d", emy);
		while (true)
		{
			scanf("%d", &ply);
			if (0 > ply || 3 < ply)
			{
				printf("入力に誤りがあります。再度入力して下さい。\n");
			}
			else
			{
				break;
			}
		}
		printf("PLAYER:");
		kickDirection(ply);
		printf("ENEMY:");
		kickDirection(emy);
		printf("\n");
		//判定
		if (ply != emy)
		{
			printf("Goal\n");
			emyScore++;
		}
		else
		{
			printf("Stop!\n");
		}

		printf("%dRound\n PLAYER:%d vs ENEMY:%d\n", round, plyScore, emyScore);
		//サドンデス突入選出
		if (round == maxRound && plyScore == emyScore)
		{
			printf("サドンデスに突入しました。\n");
		}

	}
	//勝負判定

	judgment(plyScore, emyScore);

	return 0;
}