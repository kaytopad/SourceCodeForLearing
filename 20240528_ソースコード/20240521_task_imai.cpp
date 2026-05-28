/*
サイズを示す数値を入力し、何等かの文字で例のような三角形を表示するプログラムを作成しなさい。

例：
　X
 XXX
XXXXX

*/

#include<stdio.h>
#pragma warning(disable:4996)

int main(void)
{
    //変数宣言
    int i, j;
    int size;
    //段落数字を入力
    printf("サイズを示す数値を入力し、何等かの文字で例のような三角形を表示しましょう\n");
    scanf("%d", &size);
    //多重ループで描画
    for ( i = 0; i < size; i++)
    {
        for ( j = 0; j < size + i; j++)
        {
            //段落数分だけ追加
            if (j < size - 1 -i)
            {
                printf(" ");
            }
            else
            {
                printf("△");
            }

        }
        printf("\n");
    }

    return 0;
}