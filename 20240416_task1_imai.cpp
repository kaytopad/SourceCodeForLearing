#include <stdio.h>
/*
int 型の変数 x、y に任意の数値を代入し、
x の値を y に、y の値を x に入れ替えて 
x と y の値を表示するプログラムを作成しましょう。
*/
int main(void)
{
    //変数宣言
    int x,y;
    int X, Y;
    //代入
    x = 60;
    y = 30;
    //入れ替え
    //X = y;
    //Y = x;
    //表示
    printf("xの値は%d,yの値は%d\n", y, x);

    return 0;
}