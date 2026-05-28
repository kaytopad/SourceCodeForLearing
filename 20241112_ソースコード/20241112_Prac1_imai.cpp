#include<stdio.h>
#pragma warning(disable:4996)
#include"20241112_header1_imai].h"

int main(void) 
{
    //変数
    char src[128];
    char cpy[128];
    char* str;
    char* dst;
    int len;

    printf("文字を入力してください。\n");
    scanf("%s", &src);
    str = src;
    dst = cpy;
    //文字列を確認関数
    len = strlen(str);
    //文字列コピー関数
    strcpy(str, dst);

    printf("文字数が%dで、コピーしてきた内容は%sです。\n", len, cpy);



    return 0;
}