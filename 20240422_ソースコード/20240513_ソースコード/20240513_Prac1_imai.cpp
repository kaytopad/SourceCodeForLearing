#include <stdio.h>
#pragma warning(disable:4996)
/*
1～12月までの日数を表示するプログラミングを作成しましょう。
キーボードから数字を入力してください。
入力した月の日数を表示してください。
例：
入力→3
3月の日数は、31日です。
※入力以外は、「入力に誤りがあります。」を表示させてください。
*/
int main(void)
{
    //変数宣言
    int month;
    int year;
    //キーボードから入力。
    printf("1-12月を入力して、月の日数を表示してください。\n");
    scanf("%d", &month);
    //月からの日数判定
    switch (month)
    {

    case 2:
        printf("西暦を入力してください\n");
        scanf("%d", &year);
        if (0 < year)
        {
            //うるう年
            if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
            {
                printf("%d年はうるう年なので、29日です", year);

            }
            else
            {
                printf("%d年は通常年なので、28日です", year);
            }

        }
        else
        {
            printf("紀元前になるので、わかりません。%d月の日数は28日or29日です\n",month);
        }
        break;
    case 4:
    case 6:
    case 9:
    case 11:
        printf("%d月の日数は、30日です", month);
        break;
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:
        printf("%d月の日数は、31日です", month);
        break;
    default:
        //入力以外
        printf("入力に誤りがあります。\n");

    }

    return 0;
}