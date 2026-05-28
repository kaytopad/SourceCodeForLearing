/*
入力として渡された文字列を反転する関数 reverse_string を作成してください。
この関数は、反転された文字列を返すのではなく、渡された文字列そのものを変更する必要があります。
関数の仕様：
void reverse_string(char *str);
str : 入力される文字列（NULL終端の文字列）。関数の呼び出し後、str は反転された文字列になります。
戻り値 : なし
※文字列は10文字以内とします。
*/
#include"20241112_header2_imai.h"

int main(void)
{
    char string[11];

    printf("文字列を入力してください。\n");
    scanf("%10s", &string);

    reverse_string(string);

    printf("反転した文字列は%sです\n",string);


    return 0;
}