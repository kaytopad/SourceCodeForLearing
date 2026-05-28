/*
テストの合否を判定させましょう。
テストの点数を入力しましょう
※点数は、0〜100までとします。
入力した点数が75点以上なら「合格」を表示しましょう。
74点未満、30点以上なら「追試」を表示しましょう。
30点未満なら「不合格」を表示しましょう。
*/
#include<stdio.h>
#pragma warning(disable:4996)//エラーの4996をさせない
int main(void)
{   
    //変数宣言
    int point;//英語で書きましょう。
    //キーボードから入力
    printf("テストの点数を入力しましょう※点数は、0～100までとします。\n");
    scanf("%d", &point);
    //入力不可数字の判定
    if (point > 0 && point < 100)
    {
        //判定
        //75点以上なら「合格」
        if (point >= 75)
        {
            printf("合格\n");
        }
        //74点未満から30点以上「追試」
        else if(point >= 30 )
        {
            printf("追試\n");
        }
        //30点未満「不合格」
        else
        {
            printf("不合格\n");
        }


        /*if (point >=75)
        {
            printf("合格\n");
        }
        else
        {
            if (point >= 30)
            {
                printf("追試");
            }
            else
            {
                printf("不合格");
            }

        }*/
    }
    else
    {
        printf("入力に誤りがあります。\n");
    }
    return 0;
}