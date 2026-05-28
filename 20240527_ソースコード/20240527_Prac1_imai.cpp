/*
数字当てゲーム
ランダムで0～100までの数字を当てるゲームを作成しましょう。
プレイヤーは数字を入力してその数字をあてます。
外れた場合、入力して数字が大きいか小さいかのヒントを表示しましょう。
プレイヤーは、数字が当てるまで解答できるようにしてください。
*/

#include <stdio.h>
#include <stdlib.h>
#include<time.h>
#pragma warning(disable:4996)

int main(void)
{
    //変数宣言
    int ans = -1;   //初期値が-1
    int quesiotn;
    int cnt = 0;
    //乱数の初期化
    srand((unsigned int)time(NULL));
    //問題の生成
    quesiotn = rand() % 101;
    printf("数字当てゲームランダムで0～100までの数字を当てるゲームです\n");
    //ゲーム開始
    while (quesiotn != ans)
    {
        //カウントを追加
        cnt++;
        //キーボードから入力
        //入力チェック
        while (true)
        {
            printf("0から100までで数字を入力してください。\n");
            scanf("%d", &ans);
            if (0 > ans || 100 < ans)
            {
                printf("入力に誤りがあります。再度入力してください。\n");
            }
            else
            {
                break;
            }
        }
        //正解なら抜ける
        //不正解ならヒントを出す
        if (quesiotn > ans)
        {
            //小さい
            printf("解答の数字より小さいです\n");

        }
        else if (quesiotn < ans )
        {
            //大きい
            printf("解答の数字より大きいです\n");
        }

    }

   //結果を表示
    printf("おめでとうございます！！正解です！%d\n%d回目で抜け出せました\n",ans,cnt);
    return 0;
}