#include<stdio.h>
#pragma warning(disable:4996)

/*
・多次元配列を使い掛け算の九九を完成させなさい。
・1 桁の数値（ 1 ～ 9 に限定）を２つ入力し、その積を表示するプログラムを作成しなさい。
ただし、九九の計算結果が入った配列を予め作成して利用してください。
*/
//変数の影響範囲が変わりますよ（グローバル変数）
const int INDEX = 9;
const int NULLNUM = 0;

int main(void)
{
    
    //変数宣言
    int i, j;
    int num1, num2;
    int kuku[INDEX][INDEX] = {};
    //九九の多次元配列に格納
    for ( i = NULLNUM; i < INDEX; i++)
    {
        for ( j = NULLNUM; j < INDEX; j++)
        {
            kuku[i][j] = (i + 1) * (j + 1);
        }

    }
    //数字を２つ入力
    printf("数字を2つ入力してください。\n1つ目");

    while (true)
    {
        scanf("%d", &num1);
        if (NULLNUM > num1 || INDEX < num1)
        {
            printf("入力に誤りがあります。再度入力してください。\n");
        }
        else
        {
            break;
        }

    }
    printf("2つ目");
    while (true)
    {
        scanf("%d", &num2);
        if (NULLNUM > num2 || INDEX < num2)
        {
            printf("入力に誤りがあります。再度入力してください。\n");
        }
        else
        {
            break;
        }

    }
    printf("%d×%d = %d", num1, num2, kuku[num1 - 1][num2 - 1]);
    return 0;
}