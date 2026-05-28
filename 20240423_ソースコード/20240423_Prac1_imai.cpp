#include <stdio.h>
#pragma warning(disable:4996)
/*
4つの数字を入力して、最大値を表示しましょう。
*/
int main(void)
{
    //変数宣言
    int num1,num2,num3,num4;
    int max1, max2;
    //キーボードから入力
    printf("キーボードから整数を入力し、最大値を表示しなさい。\n");
    scanf("%d",&num1);
    scanf("%d", &num2);
    scanf("%d", &num3);
    scanf("%d", &num4);
    //仮最大値設定
    max1 = num1;
    max2 = num3;
    //最大値を判定
    if (max1 < num2)
    {
        max1 = num2;
    }
    if (max2 < num4)
    {
        max2 = num4;
    }
    if (max1 < max2)
    {
        max1 = max2;
    }
    //最大値表示
    printf("４つの数字の最大値は%dです\n", max1);
    return 0;
}