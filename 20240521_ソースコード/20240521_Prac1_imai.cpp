#include<stdio.h>
#pragma warning(disable:4996)

/*
個数を示す数値を入力し、その個数分だけ 0 ～ 9 の数字を表示するプログラムを作成しなさい。
数字は 0 , 1 , 2 , 3 , , の順に表示し、9 の次は 0 に戻るものとします。
*/

int main(void)
{
    //変数宣言
    int i;              //ループカウント
    int num,tmp = 0;    //個数の値、カウント
    //個数を入力
    printf("個数を入力してください。\n");
    scanf("%d", &num);
    //個数分繰り返す
    for ( i = 0; i < num; i++)
    {
        //printf("%d　", tmp);
        ////カウントで表示（ただし、9になったら0に戻す）
        //tmp++;
        //if (tmp > 9)
        //{
        //    tmp = 0;
        //    printf("\n");
        //}
        
        //別解
        printf("%d\n", i % 10);

    }
    return 0;
}