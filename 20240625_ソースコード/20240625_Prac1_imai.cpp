#include<stdio.h>
#pragma warning(disable:4996)
/*
学生の試験結果を表す、次のメンバーを持った構造体を定義する。
・試験の得点（int型）
・成績評価（char型）
成績評価を設定する関数を定義しましょう。
・作成した構造体のポインタを引数としましょう。
・試験の得点によって成績評価に文字を設定しましょう。
    80点以上→'A'、70点以上→'B'、60点以上→'C'、60点未満→'D'
作成した構造体の変数に、試験の得点を入力しましょう。
作成した関数によって、成績評価を設定しましょう。
構造体の内容（試験の得点、成績評価）を表示しましょう。
*/

//構造体
typedef struct Student
{
    int score;      //点数
    char result;    //成績評価
}student;

//定数
const int NUM_STUDENT = 5;
const int GRADES_A = 80;
const int GRADES_B = 70;
const int GRADES_C = 60;
const int SCORE_MIN = 0;
const int SCORE_MAX = 100;
int main(void)
{
    //変数宣言
    int i;
    //構造体配列宣言
    student stuArry[NUM_STUDENT];
    printf("学生の点数を入力して、成績評価を付けましょう。\n");
    //テストの点数入力（入力チェック0～100）
    for ( i = 0; i < NUM_STUDENT; i++)
    {
        printf("%d人目\n", i + 1);
        //入力チェック
        while (true)
        {
            scanf("%d", &stuArry[i].score);
            if (SCORE_MIN > stuArry[i].score || SCORE_MAX < stuArry[i].score)
            {
                printf("入力に誤りがあります。再度入力してください。\n");
            }
            else
            {
                break;
            }
        }
        //成績評価
        if (stuArry[i].score >= GRADES_A)
        {
            stuArry[i].result = 'A';
        }
        else if (stuArry[i].score >= GRADES_B)
        {
            stuArry[i].result = 'B';
        }
        else if (stuArry[i].score >= GRADES_C)
        {
            stuArry[i].result = 'C';
        }
        else
        {
            stuArry[i].result = 'D';
        }
    }

    //構造体の内容表示
    for ( i = 0; i < NUM_STUDENT; i++)
    {
        printf("%d人目の点数は%d点で成績表は%cです\n",i+1,stuArry[i].score,stuArry[i].result);
    }

    return 0;
}
