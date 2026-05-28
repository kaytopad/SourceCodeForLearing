#include <stdio.h>
#pragma warning(disable:4996)

int main(void)
{
    //変数宣言
    //int x;
    float x;
    //入力を促す
    printf("キーボードから任意の整数を入力してください。\n");
    //キーボード入力
    //scanf("%d", &x);
    scanf("%f", &x);
    //画面に表示
    //printf("キーボードから入力された数字は%dです。\n",x);
    printf("キーボードから入力された数字は%fです。\n", x);
    return 0;
}