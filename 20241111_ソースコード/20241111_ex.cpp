#include<stdio.h>

int main(void)
{
    const int INDEX = 16;
    //•Ï”
    char c;
    int i,j;

    c = 0x20;
    //ƒ‹[ƒv

    for ( i = 0; i < INDEX; i++)
    {
        for ( j = 0; j < INDEX; j++)
        {
            printf("%c ", c + (i * 16) + j);
        }

        printf("\n");
    }

    return 0;
}