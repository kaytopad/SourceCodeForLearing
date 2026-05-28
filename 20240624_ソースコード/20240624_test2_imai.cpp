#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#pragma warning(disable:4996)

/*
・1〜100の中からランダムに選ばれた数字を5回以内に当てましょう。
・選択したら、50以上か以下を表示しましょう。
・入力した数字が小さければ「Low」、大きければ「Hight」のヒントを表示しましょう
*/

//定数
const int NUMBER = 100;
const int NUM_MIN = 1;
const int ROUND = 5;
const int NUM_HALF = 50;

int main(void)
{
	//変数宣言
	int i;
	int ans, ply;
	//乱数の初期化
	srand((unsigned int)time(NULL));
	//答えの生成
	ans = rand() % NUMBER + NUM_MIN;
	//ゲームスタート
	printf("GAME STRAT!!\n");
	//ヒントの表示
	if (ans >= NUM_HALF)
	{
		printf("Over50\n");
	}
	else
	{
		printf("Less than 50\n");
	}
	for ( i = 0; i < ROUND; i++)
	{
		//プレイヤー入力
		while (true)
		{
			scanf("%d", &ply);
			if (NUM_MIN > ply || NUMBER < ply)
			{
				printf("There is an error in your input. Please try again.\n");
			}
			else
			{
				break;
			}

		}
		//判定
		if (ans == ply)
		{
			printf("BING!!\n");
			break;
		}
		else if (ans < ply)
		{
			printf("Hight\n");
		}
		else
		{
			printf("Low\n");
		}

	}

	printf("answer:%d\n", ans);
	if (i < ROUND)
	{
		printf("Player Winner\n");
	}
	else
	{
		printf("Enemy Winner\n");
	}

	return 0;
}