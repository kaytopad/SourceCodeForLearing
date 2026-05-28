#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#pragma warning(disable:4996)
/*
野球盤ゲーム
0：ストレート　1：カーブ　2：スライダーとして、１球勝負の野球ゲームを作成しましょう。
ピッチャーは、ランダムで上記の数字を選択します。
バッター（プレイヤー）はキーボードから入力してボールを打ってください。
※0～3以外を入力したら「Out」を表示させてください。
同じ数字なら「Hit」、違う数字なら「Out」を表示してください。
*/
int main(void)
{

    //変数宣言
    int pitcher, Batter;
    printf("野球盤ゲーム\nピッチャーから投げられる球を打ち返しましょう\n0：ストレート　1：カーブ　2：スライダー\n");
    //乱数の初期化
    srand((unsigned int)time(NULL));
    //ピッチャーの選択（ランダム）
    pitcher = rand() % 3;   
    //プレイヤー（バッター）の入力
    scanf("%d", &Batter);
    //HitかOutを判定・表示
    printf("ピッチャーは%dでした。\n", pitcher);
    if (pitcher == Batter)
    {
        printf("Hit!\n");
    }
    else
    {
        printf("Out!\n");
    }
    return 0;
}