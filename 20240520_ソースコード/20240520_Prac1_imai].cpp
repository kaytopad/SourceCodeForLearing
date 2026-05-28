/*
とある食堂の月間の売り上げは？？
福岡市内にある健康を第一に考えたご飯を提供してくれるとある食堂
店主の1人のみで行なっているので、提供する食事も1日に25食までとなっています。
月の営業日は22日として、月の売り上げはいくらでしょうか？
※1日の食数はランダムで生成しましょう。
1食950円です。
*/
#include <stdio.h>
#include <stdlib.h>
#include<time.h>

int main(void)
{
    //変数宣言
    int i;  //ループカウント
    int numMeals;
    int sale_day;
    int sale_month;
    int sum = 0;
    //乱数の初期化
    srand((unsigned int)time(NULL));
    //22日（営業日分繰り返し）
    for ( i = 0; i < 22; i++)
    {
        //ランダムで1日の食数と売上を計算、月の売り上げに追加
        numMeals = rand() % 26;
        sale_day = numMeals * 950;
        sum += numMeals;
        printf("%d日目%d食%d円\n", i + 1, numMeals, sale_day);
        //sum = sum + numMeals;

    }
    //売上金額（月間の売上）を表示
    sale_month = sum * 950;
    printf("\n月の合計食数は%d食で、月の売上は%d円でした\n",sum,sale_month);
    return 0;
}