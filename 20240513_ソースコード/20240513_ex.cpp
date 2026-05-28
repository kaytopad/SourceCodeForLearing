#include <stdio.h>
#pragma warning(disable:4996)

int main()
{
    int h;
    printf("グー：1　チョキ：2　パー：3　のいずれかを入力　：　");
    scanf("%d", &h);

    switch (h)
    {
    case 1:
        printf("グー");
        break;
    case 2:
        printf("チョキ");
        break;
    case 3:
        printf("パー");
        break;
    default:
        printf("1-3以外が入力されました。");

    }

    return 0;
}