/*
0：グー　1：チョキ　2：パーとしてジャンケンゲームを作成しましょう。
CPUはランダムで上記の数字を選択します。
プレイヤーは、キーボードから数字を入力します。
プレイヤーが勝った場合は、「PLAYER WIN」として、CPUが勝った場合は、「CPU WIN」を表示し、同じなら「DRAW」を表示してください。
5回勝負を行い、結果を表示しましょう。
※例：5回勝負終了：何勝何分け何敗
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
    int i;          //ループカウント
    int win=0, Los=0, Drw=0;  //勝敗カウント
    //ランダムな初期化
    srand((unsigned int)time(NULL));
    //ランダム数字を生成
    printf("じゃんけんゲームを作成しましょう。\n");
   //じゃんけんの開始

    for ( i = 0; i < 5; i++)
    {
        printf("0：グー　1：チョキ　2：パーとしてジャンケンゲームをします\nプレイヤーの手を入力してください。\n");
        emy = rand() % 3;
        //printf("%d\n", emy);
        //キーボードから入力
        scanf("%d", &ply);
        //入力不可チェック
        if (ply >= 0 && ply <= 2)
        {
            //手の表示
            switch (ply)
            {
            case 0:
                printf("Playerはグーです\n");
                break;
            case 1:
                printf("Playerはチョキです\n");
                break;
            case 2:
                printf("Playerはパーです\n");
                break;
            }
            switch (emy)
            {
            case 0:
                printf("CPUはグーです\n");
                break;
            case 1:
                printf("CPUはチョキです\n");
                break;
            case 2:
                printf("CPUはパーです\n");
                break;
            }

            //判定
            cal = ply - emy;
            //PLAYERWIN
            if (cal == -1 || cal == 2)
            {
                printf("PLAYER WIN!\n");
                //勝ちの増加
                win++;
            }
            //DRAW
            else if (cal == 0)
            {
                printf("DRAW\n");
                //引き分け
                Drw = Drw+1;
            }
            //CPUWIN
            else
            {
                printf("CPU WIN!\n");
                //負けの増加
                Los++;
            }

        }
        else
        {
            printf("入力に誤りがあります。\n");
        }

    }

    //結果表示
    printf("5回勝負の結果：%d勝%d分け%d敗\n",win,Drw,Los);
    return 0;
}