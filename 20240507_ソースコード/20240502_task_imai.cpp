/*
ランダムな数字を生成します。
※数字の範囲は0〜15とします。
それを入力してあげましょう。
※ヒントとして、7よりも大きいか小さいかを表示しましょう。
正解したら「BING」を表示し、外れたら「Booo」を表示しましょう。
解答後は、何が正解かを表示しましょう。
*/
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#pragma warning(disable:4996)

int main(void)
{
    //変数宣言
    int ranNumber;
    int asnNumber;
    //ランダムな数字の初期化
    srand((unsigned int)time(NULL));
    //ランダムな数字の生成
    ranNumber = rand() % 16;
    //７より大きいか？小さいか？
    printf("数当てゲーム！\nランダムな数字0～15を選択して当ててください\n");
    if (ranNumber > 7)
    {
        printf("7より大きいです\n");
    }
    else
    {
        printf("7より小さいです\n");
    }
    //確認用
    //printf("%d\n", ranNumber);
    //キーボードから入力
    scanf("%d", &asnNumber);
    //入力不可チェック
    if (asnNumber > 0 && asnNumber < 15)
    {
    //判定
        //正解なら
        if (asnNumber == ranNumber)
        {
            printf("BING!\n");
        }
        //不正解なら
        else
        {
            printf("Booo!\n");
        }
    }
    else
    {
        printf("入力に誤りがあります。\n");
    }
    //正確の表示
    printf("正解は、%dでした。",ranNumber);

    return 0;
}