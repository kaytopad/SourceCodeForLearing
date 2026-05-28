#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#pragma warning(disable:4996)
#include"20240819_header_imai.h"


int inputCheck(int min, int max)
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

int drowCard()
{
    int num;
    //ランダムなカード生成
    num = rand() % MAX_CARD + MIN_CARD;
    //引いたカードを表示
    printf("引いたカードは%d\n", num);
    return num;
}

bool judge(int ply, int emy)
{
    bool flg = false;

    if ((ply == BURST_NUM || emy == BURST_NUM) || (ply == BURST_NUM && emy == BURST_NUM))
    {
        flg = true;
    }
    else if (ply > BURST_NUM || emy > BURST_NUM)
    {
        flg = true;
    }

    return flg;
}

int playerTrun(int sum)
{
    int plySelect = 0;
    bool flg = false;
    while (true)
    {
        printf("PLAYER TRUN\n現在の数字%dです。\nカードを引きます\nYes:0 No:1\n", sum);
        //カードを引きますか？

        plySelect = inputCheck(0, 1);
        if (plySelect == 0)
        {
            sum += drowCard();
            flg = judge(sum, 1);
            if (flg)
            {
                break;
            }
        }
        else
        {
            break;
        }

    }

    return sum;

}

int enemyTrun(int ply, int emy)
{
    bool flg = false;

    while (true)
    {
        printf("ENEMY TRUN\n現在の数字%dです。", emy);

        if (ply > emy || emy != BURST_NUM)
        {
            emy += drowCard();
            flg = judge(ply, emy);
            if (flg)
            {
                break;
            }
        }
        else if (ply == emy)
        {
            break;
        }
        else
        {
            break;
        }

    }

    return emy;
}


//結果表示

void Result(int plySum, int emySum)
{

    if (plySum == BURST_NUM)
    {
        printf("BLACKJACK！！PLAY WINNER");
    }
    else if (emySum == BURST_NUM)
    {
        printf("BLACKJACK！！ENEMY WINNER");
    }

    else if (plySum > BURST_NUM)
    {
        printf("PLAYER BURST!!\nENEMY WINNER\n");
    }
    else if (emySum > BURST_NUM)
    {
        printf("ENEMY BURST!!\nPLAYER WINNER\n");
    }
    else if (plySum > emySum)
    {
        printf("PLAYER WINNER\n");
    }
    else if (plySum == emySum)
    {
        printf("DRAW\n");
    }
    else
    {
        printf("ENEMY WINNER\n");
    }
}