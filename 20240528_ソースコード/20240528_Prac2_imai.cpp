/*ピッチャーとして相手チームを抑えましょう
持ち球は、0：ストレート　1：カーブ　2：スライダー　3：シンカーです。
CPUであるバッターは上記の番号をランダムで選択します。
同じ数字であれば打たれたとして75％の確率でヒットになり、25％の確率でアウトとなります。
ヒットが4回出たら負けになります。
違う数字なら75％の確率でストライクとなり、25％確率でボールとなります。
ボールは4つで1ヒットです。
ストライクは3つで1アウトです。
アウトは3つで勝利となります。
ヒット、アウトが出たらストライクとボールのカウントは0になります。
*/
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#pragma warning(disable:4996)

int main(void)
{
    //変数宣言
    int ply, emy;
    int prod;       //確率
    int Strike = 0, Ball = 0, Out = 0, Hit = 0;     //野球のカウント
    //乱数の初期化
    srand((unsigned int)time(NULL));
    //野球盤スタート
    printf("野球盤ゲームスタートです\n");
    printf("プレイヤーはピッチャーとなり、この回を守り切ってください\n");
    do
    {
        printf("投げる球を選んでください\n0:ストレート1:カーブ2:スライダー3:シンカー\n");
        //投げる球種を選択（入力チェック）
        while (true)
        {
            scanf("%d", &ply);
            if (0 > ply || 3 < ply)
            {
                printf("入力に誤りがあります。再度入力してください。\n");
            }
            else
            {
                break;
            }

        }
        //CPUランダム選択
        emy = rand() % 4;
        //確率計算
        prod = rand() % 4;
        //判定
        //異なればストライク（75％）ボール（25%）
        if (ply != emy)
        {
            if (prod == 0)
            {
                printf("ボール！\n");
                Ball++;
            }
            else
            {
                printf("ストライク！！\n");
                Strike++;
            }

        }
        //同じならHit(75%) or Out(25%)
        else
        {
            Strike = 0;
            Ball = 0;
            if (prod == 1)
            {
                printf("OUT!!!\n");
                Out++;
            }
            else
            {
                printf("HIT!!\n");
                Hit++;
            }

        }

        if (Strike >=3 || Ball >=4)
        {
            if (Strike >= 3)
            {
                Out++;
            }
            else
            {
                Hit++;
            }
            Strike = 0;
            Ball = 0;
        }
        //3アウトか4ヒットまで繰り返す
        printf("B:%d\nS:%d\nO:%d\nRuinner:%d\n",Ball,Strike,Out,Hit);
    } while (Out < 3 && Hit <4);

    //決着！
    if (Out >= 3)
    {
        printf("PLAYER WINNER！！\n");
    }
    else
    {
        printf("CPU WINNER!!\n");
    }
    return 0;
}