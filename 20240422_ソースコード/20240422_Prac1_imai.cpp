#include <stdio.h>
#pragma warning(disable:4996)
/*
キーボードから整数2つを入力してください。
その2つの整数を使い、足し算、引き算、掛け算、割り算、剰算を行って
その答えを画面に出力してください。
*/

int main(void)
{
    //変数宣言
    int num1;
    int num2;
    //インフォメーション
    printf("キーボードから整数2つを入力してください。\n");
    //キーボードから入力
    printf("1回目:");
    scanf("%d",&num1);
    printf("2回目:");
    scanf("%d", &num2);
    //結果表示
    printf("和：%d\n",num1+num2);
    printf("差：%d\n", num1 - num2);
    printf("積：%d\n", num1 * num2);
    printf("商：%.2f\n", (float)num1 / (float)num2);
    printf("剰：%d\n", num1 % num2);
    

    return 0;
}