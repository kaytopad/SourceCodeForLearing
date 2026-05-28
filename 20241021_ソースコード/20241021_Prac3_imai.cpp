/*
配列 {1, 3, 5, 7, 9} を宣言し、reverseArray 関数を使用して配列の要素を逆順にしてください。
配列の逆順にした結果を表示してください。
findMinMax 関数を使って、配列の最大値と最小値を求め、それぞれを表示してください。

*/

#include<stdio.h>

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

void findMinMax(int* arry, int Index, int* min, int* max)
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
    const int Index = 5;
    //配列
    int arry [] = {1,3,5,7,9};
    int min, max;
    //逆順
    reverseArray(arry, Index);
    printf("逆順：");
    //逆順に表示
    for (int i = 0; i < Index; i++)
    {
        printf("%d,", arry[i]);
    }

    printf("\n");
    //最大値と最小値
    findMinMax(arry,Index,&min,&max);
    printf("最大値は、%d\n",max);
    printf("最小値は、%d\n", min);
    return 0;
}