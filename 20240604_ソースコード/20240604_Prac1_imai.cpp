/*
10 個の数値を入力する。
入力された数値を偶数と奇数に分類して表示する。
*/
#include<stdio.h>
#pragma warning(disable:4996)

int main(void)
{
    //変数宣言
    int i;          //ループカウント
    int index = 10; //インデックス（要素数）
    int ary[10];    //配列（10個用意）
    //10個の数値を入力
    printf("10個の数字を入力してください。\n");
    for ( i = 0; i < index; i++)
    {
        scanf("%d", &ary[i]);
    }
    //入力した数値を偶数と奇数で分類して表示する
    //偶数
    printf("偶数\n");
    for ( i = 0; i < index; i++)
    {
        if (ary[i] % 2 == 0)
        {
            printf("%d\n", ary[i]);
        }
    }
    //奇数
    printf("奇数\n");
    for (i = 0; i < index; i++)
    {
        if (ary[i] % 2 != 0)
        {
            printf("%d\n", ary[i]);
        }
    }



    return 0;
}
