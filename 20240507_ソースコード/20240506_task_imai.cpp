#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#pragma warning(disable:4996)

/*
5月5日に作ったゲームに機能を追加しましょう。
打たれた時、25%の確率でファールにして勝負を「引き分け」を追加してください。
*/

int main(void)
{
    //変数宣言
    int pitcher, Batter;
    int fullFlag;
    printf("野球盤ゲーム\nピッチャーから投げられる球を打ち返しましょう\n0：ストレート　1：カーブ　2：スライダー\n");
    //乱数の初期化
    srand((unsigned int)time(NULL));
    //ピッチャーの選択（ランダム）
    pitcher = rand() % 3;
    fullFlag = rand() % 4; //0～99
    //プレイヤー（バッター）の入力
    scanf("%d", &Batter);
    //HitかOutを判定・表示
    printf("ピッチャーは%dでした。\n", pitcher);
    if (Batter >= 0  && Batter <= 2)
    {
        if (pitcher == Batter)
        {
        //打った時に25%の確率でファール
            //if (fullFlag <= 25)
            //{
            //    printf("引き分け\n");
            //}
            if (fullFlag == 0)
            {
                printf("DRAW\n");
            }
            else
            {
                printf("Hit!\n");
            }
        }
        else
        {
            printf("Out!\n");
        }
    }
    else
    {
        printf("入力に誤りがあります。\n");
    }
    return 0;
}