#include"20240819_header2_imai.h"

//グローバル変数
int outs = 0;
int strikes = 0;
int ball = 0;
int runner = 0;


int playInning(bool team)
{
	int ply, emy;
	int scrore = 0;

	while (outs < OUTCOUNT)
	{
		if (team)
		{
			printf("狙い球を選択してください。\n0：ストレート　1：カーブ　2：スライダー　3：シンカー\n");
			ply = checkInput(0, 3);
			emy = rand() % 4;
			displayPitchtype(ply);
			displayPitchtype(emy);
			scrore += TrunofBatter(ply,emy);

		}
		else
		{
			printf("投げる球を選択してください。\n0：ストレート　1：カーブ　2：スライダー　3：シンカー\n");
			ply = checkInput(0, 3);
			emy = rand() % 4;
			displayPitchtype(ply);
			displayPitchtype(emy);
			scrore += TrunofBatter(emy,ply);

		}

		printf("B : %d\nS : %d\nO : %d\n", ball, strikes, outs);
		printf("Runner:%d\n", runner);




	}

	runner = 0;
	outs = 0;
	return scrore;

}

void displayPitchtype(int pitch)
{
	switch (pitch)
	{

	case 0:
		printf("ストレート\n");
		break;
	case 1:
		printf("カーブ\n");
		break;
	case 2:
		printf("スライダー　\n");
		break;
	case 3:
		printf("シンカー\n");
		break;
	}
}



int checkInput(int min, int max)
{
	int num;

	while (true)
	{
		scanf("%d", &num);

		if (min > num || max < num)
		{
			printf("入力に誤りがあります。再度入力してください。\n");
		}
		else
		{
			break;
		}
	}
	return num;
}

int TrunofBatter(int Batter,int Pitcher)
{
	int scr = 0;
	int hitChance;
	int strikeOrBall;

	if (Batter == Pitcher)
	{
		hitChance = rand() % 100 + 1;
		if (hitChance < 10)
		{
			scr += runner + 1;
			printf("HomeRun！！\n%d点追加！！\n",scr);
			runner = 0;
		}
		else if (hitChance < 75)
		{
			printf("Hit!!\n");
			runner++;			
		}
		else
		{
			printf("OUT!!\n");
			outs++;
		}
		strikes = 0;
		ball = 0;
	}
	else
	{
		strikeOrBall = rand() % 100 + 1;

		if (strikeOrBall < 75)
		{
			strikes++;
			if (strikes < STRIKCOUNT)
			{
				printf("STRIKE!!\n");
			}
			else
			{
				printf("STRIKE!\nBatterOUT!!\n");
				outs++;
				strikes = 0;
				ball = 0;
			}

		}

		else
		{
			ball++;
			printf("BALL\n");
			if (ball == BALLCOUNT)
			{
				printf("FourBall\n");
				runner++;
			}
		}
	}

	if (runner == RUNNERCOUNT)
	{
		printf("1点追加\n");
		runner--;
		scr++;
	}

	return scr;
}