#include<stdio.h>
#pragma warning(disable:4996)

int max2(int a, int b)
{
    int max;
    max = a;
    if (max < b )
    {
        max = b;
    }

    return max;
}

int max4(int a, int b, int c, int d)
{
    return max2(max2(a, b), max2(c, d));
}

int main(void)
{
    int a,b,c,d,max;

    printf("4つの数字から最大値を表示してください。\n");

    scanf("%d", &a);
    scanf("%d", &b);
    scanf("%d", &c);
    scanf("%d", &d);

    max = max4(a, b, c, d);

    printf("最大値は%dでした。", max);

    return 0;
}