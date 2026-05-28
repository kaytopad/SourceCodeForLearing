/*
0～15までのランダムな整数を作成しなさい。
プレイヤーはキーボードからどんな数字なのかを入力し答えを当ててください。
正解なら「BING」、±3いないなら「Near」、それ以外なら「Loser」を表示しなさい。
*/

#include<stdio.h>
#pragma warning(disable:4996)
#include<stdlib.h>
#include<time.h>

int main(void)
{
    //変数宣言
    int correctAns;
    int answerNum;
    int errorNum;
    //ランダム初期化
    srand((unsigned int)time(NULL));
    //ランダムな数字を生成
    correctAns = rand() % 16;
    //キーボードから入力する
    printf("ランダムな数字を当てましょう。\nキーボードから入力してください。\n");
 
    scanf("%d", &answerNum);
    //誤差の計算
    errorNum = correctAns - answerNum;
    //入力不可チェック
    if (answerNum > 0 && answerNum < 15)
    {
        //判定する
        //正解
        if (answerNum == correctAns)
        {
            printf("BING!\n");
        }
        //±3以内か
        else if (errorNum <= 3 && errorNum >= -3)
        {
            printf("Near\n");
        }
        //不正解
        else
        {
            printf("Loser\n");
        }

    }
    else
    {
        printf("入力に誤りがあります。\n");
    }
    //正解発表
    printf("正解発表！\n%dでした。",correctAns);

    return 0;
}