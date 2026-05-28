#include <stdio.h>
#pragma warning(disable:4996)
/*
学生の試験結果を表す、次のメンバーを持った構造体を定義しましょう。
名前（char[128]）
点数（int）
成績評価（char）
作成した構造体の変数に、名前と試験の得点をキーボードから入力しましょう。
成績評価は以下のとおりです。
S→90点以上
A→90点未満70点以上
B→70点未満50点以上
C→50点未満30点以上
D→30点未満
構造体の内容を表示する
*/
typedef struct ExamResult
{
    char name[128];
    int point;
    char result;
}ExamResult;

int main(void)
{

    //構造体を変数
    ExamResult exresult;
    //名前の入力
    printf("名前の入力をしてください。\n");
    scanf("%s", &exresult.name);
    //点数の入力
    printf("テストの点数を入力してください。\n");
    scanf("%d", &exresult.point);
    if (0 <= exresult.point && 100 >= exresult.point)
    {
        //成績評価(resultに代入)
        if (exresult.point >= 90)
        {
            exresult.result = 'S';
        }
        else if (exresult.point >= 70)
        {
            exresult.result = 'A';
        }
        else if (exresult.point >= 50)
        {
            exresult.result = 'B';
        }
        else if (exresult.point >= 30)
        {
            exresult.result = 'C';
        }
        else
        {
            exresult.result = 'D';
        }

        //結果の表示
        printf("名前：%s\n点数：%d\n成績評価%c", exresult.name, exresult.point, exresult.result);

    }
    else
    {
        printf("入力に誤りがあります。\n");
    }



    return 0;
}