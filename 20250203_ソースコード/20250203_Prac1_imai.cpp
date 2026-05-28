#include<stdio.h>
#pragma warning(disable:4996)
#define FILENAME "../user_data.txt"
/*
問題：
ユーザーに名前と年齢を入力してもらい、それを "user_data.txt" というファイルに保存してください。また、"user_data.txt" に保存された名前と年齢を読み込み、画面に表示するプログラムを作成してください。
入力例：

名前を入力してください: Taro
年齢を入力してください: 25

出力例：
名前: Taro
年齢: 25
条件：
C言語では fprintf()、C++では std::ofstream を使用すること。
ファイルを 上書きモード で開く。
*/

int main(void)
{
    char name[120];
    int age = 0;
    //ユーザーからの入力
    printf("名前を入力してください。\n");
    scanf("%s", &name);
    printf("年齢を入力してください。\n");
    scanf("%d", &age);
    //ファイルに書き込み
    FILE* fp = fopen(FILENAME, "w");
    //ファイルの有無
    if (fp == NULL)
    {
        perror("ファイルが開きません。");
        return 1;
    }
    fprintf(fp, "%s\n%d\n", name, age);
    fclose(fp);
    //ファイルから読み込み
    fp = fopen(FILENAME, "r");
    if (fp == NULL)
    {
        perror("ファイルが開きません。");
        return 1;
    }
    fscanf(fp, "%s\n%d\n", name, &age);
    fclose(fp);
    //読み込んだファイルから表示
    printf("\n名前：%s\n年齢：%d", name, age);
    return 0;
}