#include<stdio.h>
#pragma warning(disable:4996)
/*
5人5教科のテスト点数と平均点を出しましょう。
5教科（国語、数学、社会、理科、英語）の教科の点数を入力して、各教科合計点数を出しましょう。
次に、5人の中で一人選択して、その生徒の合計点と平均点を出し、表示させましょう。
*/
//定数
const int SUBJECTNUMBER = 5;
const int STUDENUM = 5;
const int scoreMin = 0;
const int scoreMax = 100;
int main(void)
{
    //変数宣言
    int i, j;
    int score[STUDENUM][SUBJECTNUMBER] = {};
    int sumSubject[SUBJECTNUMBER] = {};
    int sumStudent[STUDENUM] = {};
    int studentNum = 0;

    //各教科を人数分入力
    printf("各教科国語、数学、社会、理科、英語を入力してください。\n");
    for ( i = 0; i < STUDENUM; i++)
    {
        printf("%d人目です。\n",i+1);
        for ( j = 0; j  < SUBJECTNUMBER; j ++)
        {
            switch (j)
            {
            case 0:
                printf("国語を入力してください。\n");
                break;
            case 1:
                printf("数学を入力してください。\n");
                break;
            case 2:
                printf("社会を入力してください。\n");
                break;
            case 3:
                printf("理科を入力してください。\n");
                break;
            case 4:
                printf("英語を入力してください。\n");
                break;
            }
            while (true)
            {
                scanf("%d", &score[i][j]);

                if (scoreMin > score[i][j] || scoreMax < score[i][j])
                {
                    printf("入力に誤りがあります。再度入力してください。\n");
                }
                else
                {
                    break;
                }

            }
            //各教科の合計点数を計算
            sumSubject[j] = score[i][j];
            //各生徒の合計点数を計算
            sumStudent[i] = score[i][j];
        }
    }

    //各教科の合計点を表示
    for ( i = 0; i < SUBJECTNUMBER; i++)
    {
        switch (i)
        {
        case 0:
            printf("国語の点数が%d点。\n",sumSubject[i]);
            break;
        case 1:
            printf("数学の点数が%d点。\n", sumSubject[i]);
            break;
        case 2:
            printf("社会の点数が % d点。\n",sumSubject[i]);
            break;
        case 3:
            printf("理科の点数が%d点。\n", sumSubject[i]);
            break;
        case 4:
            printf("英語の点数が % d点。\n",sumSubject[i]);
            break;
        }
    }
    //合計点と平均点を見たい学生番号を入力する
    printf("合計点と平均点を見たい学生番号を入力してください。（1～5まで）");
    //表示
    while (1)
    {
        scanf("%d", &studentNum);
        if (0 > studentNum || STUDENUM < studentNum)
        {
            printf("入力に誤りがあります。再度入力してください。\n");
        }
        else
        {
            break;
        }
    }
    printf("%d番目の学生の合計点数は%d点です。\n平均点は%f点です\n", studentNum, sumStudent[studentNum - 1], (double)sumStudent[studentNum - 1] / STUDENUM);

    return 0;
}