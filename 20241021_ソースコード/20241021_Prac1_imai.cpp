/*
配列の要素を逆順にする関数を作成してください。
整数型の配列とその要素数を引数として受け取り、配列内の要素を逆順にする関数 reverseArray を作成してください。
ポインタを使って配列の要素を操作し、値を入れ替えてください。
*/
#include<stdio.h>
#include <stdlib.h>
#include<time.h>
void reverseArray(int* arry, int index)
{
    //変数宣言
    int i;
    int temp;
    //逆順へ入れ替え
    for (i = 0; i < index / 2; i++)
    {
        //左側と右側の要素を入替る
        temp = arry[i];
        arry[i] = *(arry + index - 1 - i);
        *(arry + index - 1 - i) = temp;
    }
}

int main(void)
{
    const int INDEX = 5;
    //配列
    int ary[INDEX];
    //乱数の初期化
    srand((unsigned int)time(NULL));
    //配列にランダムな数字を代入＆表示
    for (int i = 0; i < INDEX; i++)
    {
        ary[i] = rand() % 12;
        printf("%d", ary[i]);
    }
    printf("\n");
    //逆順に入れ替え
    reverseArray(ary, INDEX);
    //入れ替え配列を表示
    for (int j = 0; j < INDEX; j++)
    {
        printf("%d", ary[j]);
    }


    return 0;
}