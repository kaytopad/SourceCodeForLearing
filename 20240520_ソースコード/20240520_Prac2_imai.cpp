/*
伝統の一戦「狂人vs半神」の対決試合の結果を出しましょう。

得点はランダムで0点から5点とします。
各回で得点を表示しましょう。
9回が終わったら、それぞれの得点とどちらかが勝ったか、引き分けかを表示しましょう
*/
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int main(void)
{
    //変数宣言
    int i;
    int teamG,teamT;
    int pointG = 0, pointT = 0;
    //乱数の初期化
    srand((unsigned int)time(NULL));
    //9回繰り返す
    for ( i = 0; i < 9; i++)
    {
        //狂人の攻撃、点数を表示
        teamG = rand() % 6;
        printf("%d回表:狂人の攻撃%d点獲得しました。 ", i + 1, teamG);
        //半神の攻撃、点数を表示
        teamT = rand() % 6;
        printf("%d回裏:半神の攻撃%d点獲得しました。 ", i + 1, teamT);
        printf("\n");
        //点数を計算
        pointG += teamG;
        pointT += teamT;
    }

    printf("狂人%d vs 半神%d\n",pointG,pointT);

    //試合の結果
    if (pointG == pointT)
    {
        printf("Draw！！引き分けです\n");
    }
    else if (pointG > pointT)
    {
        printf("狂人の勝ちです！\n");
    }
    else
    {
        printf("半神の勝ちです！\n");
    }

    return 0;
}