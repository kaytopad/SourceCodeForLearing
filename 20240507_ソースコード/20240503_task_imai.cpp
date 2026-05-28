/*
整数を入力します。
それと同時にランダムで整数を作成します。
※数字の範囲は、0〜100までとします。
入力した数字が、ランダムよりも大きいか小さいかを判定して入力しましょう。
ランダムな数字と入力した数字を足したら、偶数になるか奇数になるか判定し表示しましょう。
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#pragma warning(disable:4996)
int main(void)
{
    //変数宣言
    int randNumber; //ランダムな数字
    int ansNumber;  //入力した数字
    int sum;        //ランダムな数字と入力した数字を足した数
    //ランダムの初期化
    srand((unsigned int)time(NULL));
    //ランダムな数字の生成
    randNumber = rand() % 101;
    printf("数当てゲームPart2\nランダムな数字0～100を当てましょう。\n");
    //キーボードから入力
    scanf("%d", &ansNumber);
    //入力不可チェック
    
    if (ansNumber > 0 && ansNumber < 100)
    {
    //数字が大きいか、小さいかを表示（同じか）
        if (ansNumber > randNumber)
        {
            printf("ランダムな数字より大きいです\n");
        }
        else if(ansNumber < randNumber)
        {
            printf("ランダムな数字より小さいです\n");
        }
        else
        {
            printf("BINGO!!\n");
        }
    //数字を足す
        sum = randNumber + ansNumber;
        printf("足した数字は%dでした\n", sum);
    //足した数字が偶数か奇数か
        if (sum % 2)
        {
            printf("奇数です\n");
        }
        else
        {
            printf("偶数です\n");
        }

    }
    else
    {
        printf("入力に誤りがあります。\n");
    }
    //答えの表示
    printf("ランダムな数字は%dでした\n", randNumber);

    return 0;
}