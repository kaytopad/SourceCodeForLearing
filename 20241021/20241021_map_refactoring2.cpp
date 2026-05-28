#include<stdio.h>
#include<stdlib.h>
#pragma warning(disable:4996)
#include"20241021_Header.h"

int main(void)
{
    sMapLayer map;
    
    map = mapLayerLoader("mapTest.csv");

    //データ確認
    int ix, iy;

    for ( iy = 0; iy < map.mapYNum; iy++)
    {
        for ( ix = 0; ix < map.mapXNum; ix++)
        {
            printf("%d,", map.mapDate[iy][ix]);
        }
        printf("\n");
    }
    return 0;
}