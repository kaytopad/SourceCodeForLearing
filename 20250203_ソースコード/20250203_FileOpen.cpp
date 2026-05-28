#include<stdio.h>
#pragma warning(disable:4996)

int main(void)
{
    //FILE型のポインタ変数を生成し、そこにファイルを入れる
    FILE* fp;
    //ポインタ変数であるfpを使って指定されたファイルを開く（モード選択）
    fp = fopen("../20250203_file.txt", "w");
    //書き込みをfprintfで行う
    fprintf(fp, "Hello world\n");
    //ファイルを閉じる
    fclose(fp);
    return 0;
}