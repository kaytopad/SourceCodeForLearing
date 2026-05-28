#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#pragma warning(disable:4996)

/*
・CPUと対戦するじゃんけんゲームを作りましょう。
・選択は数字で選択し、手の割り振りは以下の通りです。
　0:グー　1:チョキ　2:パー
　※入力チェックを作成し、不正な文字は入力できないようにしましょう。
・5回勝負をして、結果を表示しましょう。
*/
//定数
const int ROUND = 5;
const int HAND = 3;
const int HANDMIN = 0;
const int HANDMAX = 2;
//ハンドサイン（出した手を表示）

void handSing(int num)
{
	switch (num)
	{
	case 0:
		printf("ぐー\n");
		break;
	case 1:
		printf("ちょき\n");
		break;
	case 2:
		printf("ぱー\n");
		break;
	}

}

int inputCheck(int min,int max)
{
	int ply;
	while (true)
	{
		scanf("%d", &ply);
		if (min > ply || max< ply)
		{
			printf("入力に誤りがあります。再度入力して下さい。\n");
		}
		else
		{
			break;
		}
	}

	return ply;

}
void Game()
{
	//変数宣言
	int i;
	int ply, emy, jug, plyCnt = 0, emyCnt = 0, draw = 0;
	//乱数の初期化
	srand((unsigned int)time(NULL));
	//ゲームスタート
	for (i = 0; i < ROUND; i++)
	{
		//player入力
		ply = inputCheck(HANDMIN, HANDMAX);
		emy = rand() % HAND;
		printf("PLAYER'S Hand:");
		handSing(ply);
		printf("ENEMY'S Hand:");
		handSing(emy);
		jug = ply - emy;
		//判定
		if (jug == -1 || jug == 2)
		{
			printf("PLAYER'S Win\n");
			plyCnt++;
		}
		else if (jug == 0)
		{
			printf("DRAW\n");
			draw++;
		}
		else
		{
			printf("Enemy'S Win\n");
			emyCnt++;
		}

	}
	//結果表示
	printf("結果表示：%d勝%d分%d敗", plyCnt, draw, emyCnt);
}
int main(void)
{

	Game();
	return 0;
}