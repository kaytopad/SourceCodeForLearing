#include <stdio.h>
#pragma warning(disable:4996)
/*
キーボードから２つの整数を入力してください。
※範囲は、0〜50までとします。
２つの数字を足してください。
和が偶数なら「丁」を画面に表示してください。
和が奇数なら「半」を画面に表示してください。
*/
int main(void)
{
    //変数宣言
    int num1;
    int num2;
    int sum;
    //インフォメーション
    printf("キーボードから２つの整数を入力してください。※範囲は、0から50までとします。\n");
    //キーボードから入力
    scanf("%d", &num1);
    scanf("%d", &num2);
    //入力チェック
    if (0 >= num1 || 50 <= num1 || 0 >= num2 || 50 <= num2)
    {
        printf("入力に誤りがあります。\n");
    }
    //計算＆結果表示
    else
    {
        sum = num1 + num2;
        //和を計算して、丁半を出力
        if (sum % 2 == 0)
        {
            //偶数
            printf("丁\n");
        }
        else
        {
            //奇数
            printf("半\n");
        }
    }

    return 0;
}