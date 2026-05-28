#include"20241021_Header.h"
#include<stdio.h>
#include<stdlib.h>
#pragma warning(disable:4996)

void mapLayerLoader(const char* csvFileName)
{

    //ファイルを開く
    FILE* fp;
    fp = fopen(csvFileName, "rt");

    if (!fp)
    {
        printf("ファイルを開けません。");
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
    int bufferLen = col * 6 + 1;
    char* buf = new char[bufferLen];
    char* ptmp = buf;

    //ファイルポインタを先頭に戻し行数を読み
    fseek(fp, 0, SEEK_SET);

    while (fgets(buf, bufferLen - 1, fp) != NULL)
    {
        row++;
    }
    printf("col %d row %d\n", col, row);

    //２次元配列を動的確保
    int** map;                  //変数mapはint*が複数ある配列を作りたいので**を書きます。
    map = new int* [row];       //int*型を動的確保するのにこのように書きます。

    int ix, iy;
    for (iy = 0; iy < row; iy++)
    {
        map[iy] = new int[col];
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

            map[iy][ix] = atoi(firstPoint);
            //次のデータ読み取り位置まで進める
            readPoint++;
            firstPoint = readPoint;
        }
    }

    //２次元配列の中身を確認
    for (iy = 0; iy < row; iy++)
    {
        for (ix = 0; ix < col; ix++)
        {
            printf("%d", map[iy][ix]);
        }
        printf("\n");
    }

    //データの解放
    for (iy = 0; iy < row; iy++)
    {
        delete[] map[iy];
    }

    delete[] map;
    delete[] buf;

    //ファイルを閉じる
    fclose(fp);
}