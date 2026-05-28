#include<stdio.h>
/*
九九表を表示してみましょう。
（1の段から9の段まで）
*/
int main(void)
{
    //変数宣言
    int i, j;
    //九九の生成
    for ( i = 0; i < 9; i++)
    {
        for ( j= 0; j < 9; j++)
        {
            printf("%d × %d = %d\n", i + 1, j + 1, (i + 1) * (j + 1));
        }
        //一段ごと表示
        printf("\n");
    }


    return 0;
}