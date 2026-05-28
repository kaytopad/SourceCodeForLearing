/*
最大値と最小値を求める関数を作成してください。
整数型の配列とその要素数を引数として受け取り、配列内の最大値と最小値を求める関数 findMinMax を作成してください。
関数の結果をポインタを通して呼び出し元に返してください。
*/
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void findMinMax(int *arry,int Index,int *min,int *max)
{
    //初期値として配列の最初の要素を設定する
    *min = *arry;
    *max = *arry;
    //配列から最小値と最大値を更新
    for (int i = 0; i < Index; i++)
    {
        if (arry[i] < *min)
        {
            *min = arry[i];
        }

        if (arry[i] > *max)
        {
            *max = arry[i];
        }

    }

}

int main(void)
{
    //定数
    const int INDEX = 5;
    //配列
    int ary[INDEX];
    //変数宣言
    int min, max;
    //乱数の初期化
    srand((unsigned int)time(NULL));
    //配列にランダムな数字を代入＆表示
    for (int i = 0; i < INDEX; i++)
    {
        ary[i] = rand() % 12;
        printf("%d,", ary[i]);
    }
    printf("\n");

    findMinMax(ary,INDEX,&min,&max);

    printf("最大値は%d\n", max);
    printf("最小値は%d\n", min);
    return 0;
}