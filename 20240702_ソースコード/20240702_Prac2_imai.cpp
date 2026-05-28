#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#pragma warning(disable:4996)
/*
数字当てゲーム
1～50までのランダムな数字を当てましょう。
入力して数字が同じなら「BING」を表示
入力して数字が大きければ「Big」を表示
入力して数字が小さければ「Small」を表示
5回以内に正解しましょう。
ゲームが終了時に、正解を表示、何回で正解したのかを表示しましょう。
ゲーム部分だけ関数化しましょう。関数名は、「numberGame」
*/

//定数
const int ROUND = 5;
const int MIN = 1;
const int MAX = 50;


//関数
void numberGame()
{
    //変数宣言
    int ply, emy,i;
    //問題の数字生成
    emy = rand() % MAX + MIN;
    //ゲームスタート
    for ( i = 0; i < ROUND; i++)
    {
        printf("=================%d回目=================\n",i +1 );
        //入力（入力チェック）
        while (true)
        {
            scanf("%d", &ply);
            if (MIN > ply || MAX < ply)
            {
                printf("入力に誤りがあります。再度入力してください。\n");
            }
            else
            {
                break;
            }
        }
        //同じ
        if (ply == emy)
        {
            printf("BING\n");
            break;
        }
        //大きい
        else if (ply > emy)
        {
            printf("Big\n");
        }
        //小さい
        else
        {
            printf("Small\n");
        }

    }
    //結果表示
    printf("正解は、%dでした\n",emy);
    //5回以内
    if (i < ROUND)
    {
        printf("%d回で正解でした。おめでとうございます！\n",i+1);
    }
    //それ以外
    else
    {
        printf("残念！今回は失敗です・・・次回の挑戦を待っています。\n");
    }

}

int main(void) 
{
    printf("数字当てゲーム");
    printf("1～50までのランダムな数字を当てましょう。\n制限回数は5回です\n");
    //乱数の初期化
    srand((unsigned int)time(NULL));
    //ゲーム関数
    numberGame();
    return 0;

}