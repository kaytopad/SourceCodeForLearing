#include"20241021_Header_refactoring2.h"
#include<stdio.h>
#include<stdlib.h>
#pragma warning(disable:4996)



sMapLayer mapLayerLoader(const char* csvFileName)
{
    sMapLayer returnmap = { 0 };

    //ファイルを開く
    FILE* fp;
    fp = fopen(csvFileName, "rt");

    if (!fp)
    {
        printf("ファイルを開けません。");
        return returnmap;
    }
    //csvファイルの列と行
    int col = 0, row = 0;
    //ファイルを1行分空読みし、1行のデータ数を数えます。
    char c = 0;

    while (c != '\n')
    {
        c = fgetc(fp);
        if (',' == c)
        {
            col++;
        }
    }
    col++;
    returnmap.mapXNum = col;

    int bufferLen = col * 6 + 1;
    char* buf = new char[bufferLen];
    char* ptmp = buf;

    //ファイルポインタを先頭に戻し行数を読み
    fseek(fp, 0, SEEK_SET);

    while (fgets(buf, bufferLen - 1, fp) != NULL)
    {
        row++;
    }

    returnmap.mapYNum = row;
    //２次元配列を動的確保
    returnmap.mapDate = new int* [row];


    int ix, iy;
    for (iy = 0; iy < row; iy++)
    {
        returnmap.mapDate[iy] = new int[col];
    }
    //ファイルポインタを先頭に戻し行数を読み
    fseek(fp, 0, SEEK_SET);
    //ファイルからデータを配列に移す
    char* readPoint;
    char* firstPoint;

    //行ループ
    for (iy = 0; iy < row; iy++)
    {
        //１行取り込み
        fgets(buf, bufferLen - 1, fp);
        readPoint = firstPoint = buf;

        //列ループ
        for (ix = 0; ix < col; ix++)
        {
            while (',' != *readPoint && '\n' != *readPoint)
            {
                readPoint++;
            }

            //カンマをNULL文字に置き換える
            *readPoint = '\0';

            returnmap.mapDate[iy][ix] = atoi(firstPoint);
            //次のデータ読み取り位置まで進める
            readPoint++;
            firstPoint = readPoint;
        }
    }

    //ファイルを閉じる
    fclose(fp);


    delete[] buf;

    return returnmap;
}