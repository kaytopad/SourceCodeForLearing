#include<stdio.h>
#pragma warning(disable:4996)
/*
サイズを示す数値を入力し、何等かの文字で、そのサイズの×印を表示するプログラムを作成しなさい。
サイズ 3 の例

X X

  X

X X

*/
int main(void)
{
    //変数宣言
    int i, j;
    int size;
    //段数入力
    printf("何段の図形を作成しますか？");
    scanf("%d", &size);
    //図形を表示
    for ( i = 0; i < size; i++)
    {
        for ( j = 0; j < size; j++)
        {
            //0もしくはその個数の時にXを表示する
            if (i == j || (size-i-1) == j)
            {
                printf("X");
            }
            //それ以外は空白
            else
            {
                printf(" ");
            }
        }
        printf("\n");

    }
    return 0;
}