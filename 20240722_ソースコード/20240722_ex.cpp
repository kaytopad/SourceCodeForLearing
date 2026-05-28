/*
ピッチャーとして相手チームを抑えましょう
持ち球は、0：ストレート　1：カーブ　2：スライダー　3：シンカーです。
CPUであるバッターは上記の番号をランダムで選択します。
同じ数字であれば打たれたとして75％の確率でヒットになり、25％の確率でアウトとなります。
ヒットが4回出たら負けになります。
違う数字なら75％の確率でストライクとなり、25％確率でボールとなります。
ボールは4つで1ヒットです。
ストライクは3つで1アウトです。
アウトは3つで勝利となります。
ヒット、アウトが出たらストライクとボールのカウントは0になります。
pitingType関数を作成し、投げた球の種類を表示しましょう。
Result関数を作成し。勝敗結果を表示しましょう。
*/
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#pragma warning(disable:4996)
//定数
const int PITING_MIN = 0;
const int PITING_MAX = 3;
const int PROBABILITY = 4;
const int STRIKE_COUNT = 3;
const int BALL_COUNT = 4;
const int OUT_COUNT = 3;
const int HIT_COUNT = 4;
//関数プロトタイプ宣言
void pitingType(int piting);
void Result(int out);

int main(void)
{
    //変数宣言
    int ply, emy;
    int prod;//確率
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
            if (PITING_MIN > ply || PITING_MAX < ply)
            {
                printf("入力に誤りがあります。再度入力してください。\n");
            }
            else
            {
                break;
            }

        }
        //球種関数呼び出し
        pitingType(ply);
        //CPUランダム選択
        emy = rand() % PROBABILITY;
        //確率計算
        prod = rand() % PROBABILITY;
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

        if (Strike >= STRIKE_COUNT || Ball >= BALL_COUNT)
        {
            if (Strike >= STRIKE_COUNT)
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
        printf("B:%d\nS:%d\nO:%d\nRunner:%d\n", Ball, Strike, Out, Hit);
    } while (Out < OUT_COUNT && Hit < HIT_COUNT);

    //決着！
    //結果表示関数
    Result(Out);

    return 0;
}

//ピッチャー球種関数
void pitingType(int piting)
{
    //球種表示
    switch (piting)
    {
    case 0:
        printf("ストレート\n");
        break;
    case 1:
        printf("カーブ\n");
        break;
    case 2:
        printf("スライダー\n");
        break;
    case 3:
        printf("シンカー\n");
        break;
    }
}
//結果表示関数
void Result(int out)
{
    if (out >= OUT_COUNT)
    {
        printf("PLAYER WINNER！！\n");
    }
    else
    {
        printf("CPU WINNER!!\n");
    }

}
