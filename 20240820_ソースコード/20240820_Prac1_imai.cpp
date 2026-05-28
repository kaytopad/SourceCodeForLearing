#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"20240820_header1_imai.h"
/*
２つの int 型変数の値を交換する関数を作成しましょう。
引数に int 型へのポインタ変数を２つ取り、値を交換します。
この関数を使用して、10 個の整数を小さい順に並べ替えて表示するプログラムを作成しましょう。
※10個の整数はランダムで0～99までとします。
*/
int main(void)
{
    //変数宣言
    int i, j;
    int ary[INDEX];
    //乱数の初期化
    srand((unsigned int)time(NULL));
    //配列
    for ( i = 0; i < INDEX; i++)
    {
        ary[i] = rand() % 100;
        printf("%d番目は、%dです。\n", i + 1, ary[i]);
    }
    printf("\n");
    //入れ替え作業
    for ( i = 0; i < INDEX; i++)
    {
        for ( j= i+1; j < INDEX; j++)
        {
            if (ary[i] > ary[j])
            {
                swap(ary[i], ary[j]);
            }
        }

    }

    //表示
    for ( i = 0; i < INDEX; i++)
    {
        printf("%d番目は、%dです。\n",i+1,ary[i]);
    }
    return 0;
}