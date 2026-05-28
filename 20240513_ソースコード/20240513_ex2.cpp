#include <stdio.h>
#pragma warning(disable:4996)

typedef struct pos2D
{
    int x;
    int y;
}pos2D;

int main(void)
{
    pos2D chara1;
    pos2D chara2;
    chara1.x = 30;
    chara1.y = 40;
    chara2.x = 0;
    chara2.y = 0;
    printf("(%d,%d)", chara2.x, chara2.y);

    return 0; 
}