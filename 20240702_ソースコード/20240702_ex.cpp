#include <stdio.h>
#pragma warning(disable:4996)

//ピラミッド表示
void printPiramid()
{
    int i, j,n;
    printf("ピラミッドの段数を入力してください:");
    scanf("%d", &n);
    for ( i = 0; i < n; i++)
    {
        for ( j = 0; j < n-i-1; j++)
        {
            printf(" ");
        }
        for ( j = 0; j < (i*2)+1; j++)
        {
            printf("*");
        }
        printf("\n");
    }
}

int main(void)
{
    printPiramid();
    return 0;
}