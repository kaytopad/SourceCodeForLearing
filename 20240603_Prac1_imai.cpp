#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#pragma warning(disable:4996)
/*
約数当てゲーム
ランダムで10〜50までの整数が生成されます。
プレイヤーはその整数を当てましょう。
ヒントとして、3つの約数が表示されます。
そのヒントを元に、正解をしましょう。
正解できるまで入力が可能です。
*/

int main(void)
{
    //変数宣言
    int target, ans, i = 1, count = 0;
    //乱数の初期化
    srand((unsigned int)time(NULL));
    //ランダムな数字を生成
    target = 13;

    printf("ヒントは以下の通りです。\n");
    //ヒント表示
    while (count < 3 && i <= target)
    {
        //約数
        if (target % i == 0)
        {
            printf("%d,", i);
            count++;
        }
        i++;
    }

    printf("\n");


    //ゲームスタート
    while (1)
    {
        printf("では、数を当てましょう\n");

        scanf("%d", &ans);

        if (ans == target)
        {
            printf("正解です\n");
            break;
        }
        else
        {
            printf("不正解です。\n");
        }
    }
    return 0;
}

