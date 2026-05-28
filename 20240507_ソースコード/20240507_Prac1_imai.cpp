/*
じゃんけんゲームを作成しましょう。
0：グー　1：チョキ　2：パーとしてジャンケンゲームを作成しましょう。
CPUはランダムで上記の数字を選択します。
プレイヤーは、キーボードから数字を入力します。
プレイヤーが勝った場合は、「PLAYER WIN」として、CPUが勝った場合は、「CPU WIN」を表示し、同じなら「DRAW」を表示してください。
*/
#include <stdio.h>
#include<stdlib.h>
#include<time.h>
#pragma warning(disable:4996)

int main(void)
{
    //変数宣言
    int ply, emy;   //プレイヤーとCPUの手
    int cal;        //判定結果
    //ランダムな初期化
    srand((unsigned int)time(NULL));
    //ランダム数字を生成
    emy = rand() % 3;
    printf("じゃんけんゲームを作成しましょう。\n0：グー　1：チョキ　2：パーとしてジャンケンゲームをします\nプレイヤーの手を入力してください。\n");
    printf("%d\n", emy);
    //キーボードから入力
    scanf("%d", &ply);
    //入力不可チェック
    if (ply >= 0 && ply <=2)
    {
        //手の表示
        printf("PLAYER:%d vs CPU:%d\n",ply,emy);
        //判定
        cal = ply - emy;
        //PLAYERWIN
        if (cal == -1 || cal == 2)
        {
            printf("PLAYER WIN!\n");
        }
        //DRAW
        else if (cal == 0)
        {
            printf("DRAW\n");
        }
        //CPUWIN
        else
        {
            printf("CPU WIN!\n");
        }

    }
    else
    {
        printf("入力に誤りがあります。");
    }
    return 0;
}