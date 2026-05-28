/*
福岡市内にある健康を第一に考えたご飯を提供してくれるとある食堂
店主の1人のみで行なっているので、提供する食事も1日に25食までとなっています。

月の営業日は22日として、月の売り上げはいくらでしょうか？
※1日の食数はキーボードから入力してください。
※最低1食は売り上げます。
1食950円です。
また、22日の中で確認したい日を入力して、その日の食数と売り上げを表示しましょう。
*/
#include<stdio.h>
#pragma warning(disable:4996)

#define INDEX 22
#define PRICE 950
int main(void)
{
    //変数宣言
    int i;
    int food[INDEX];
    int days;
    int sum = 0;
    //キーボードから食数を入力
    printf("月の営業日は22日として、月の売り上げはいくらでしょうか？\n");
    for ( i = 0; i < INDEX; i++)
    {
        printf("%d日目", i + 1);
        //入力チェック
        while (true)
        {
            scanf("%d", &food[i]);
            if (0 >= food[i] || 25 < food[i])
            {
                printf("入力に誤りがあります。再度入力してください。\n");
            }
            else
            {
                break;
            }

        }
        sum += food[i];
        printf("%d日目:%d食、売上金額%d円\n", i + 1, food[i], food[i] * PRICE);
    }
    //月の合計売上と食数を表示
    printf("22日の売上金額＆食数は、%d円、%d食数\n",sum*PRICE, sum);
    printf("確認したい日を入力してください。\n");
    //入力チェック
    while (true)
    {
        scanf("%d", &days);
        if (0 >= days || 22 < days)
        {
            printf("入力に誤りがあります。再度入力してください。\n");
        }
        else
        {
            break;
        }
    }
    //確認したい日をキーボードから入力売上と食数を表示
    //
    printf("%d日目：%d食%d円",days,food[days-1], food[days - 1] * PRICE);
    return 0;
}