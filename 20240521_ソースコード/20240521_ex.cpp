#include <stdio.h>
#pragma warning(disable:4996)

int main(void)
{
    int sum = 0;
    int i, tmp;

    for ( i = 0; i < 5; i++)
    {
        printf("%dl–Ú:", i + 1);
        scanf("%d", &tmp);
        sum += tmp;
    }

    printf("\n‡Œv = %d@•½‹Ï = %.2f\n",sum ,sum /5.0);
    return 0;
}