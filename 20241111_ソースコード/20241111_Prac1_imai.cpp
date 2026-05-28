#include"20241111_header1_imai.h"
/*
以下の内容に沿ったプログラミングをコーティング
入力として文字列と1つの文字が与えられます。
文字列の中で、その指定された文字が何回出現するかをカウントする関数 count_char を作成してください。
関数の仕様：
int count_char(char *str, char target);
str : 入力される文字列（NULL終端の文字列）
target : カウントしたい文字
戻り値 : str に含まれる target の出現回数（整数）
*/

int main(void)
{
    //変数
    char str[128];
    char target;
    int count = 0;
    //入力
    printf("文字を入力してください。\n");
    scanf("%s", &str);
    printf("探したい文字を入力してください。\n");
    scanf(" %c", &target);
    //カウント
    count = count_char(str, target);

    printf("%cは、%s内に、%d回使われていました。\n",target,str,count);


    return 0;
}