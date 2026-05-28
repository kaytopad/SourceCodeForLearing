/*
5教科のテスト点数と平均点を出しましょう。
5教科（国語、数学、社会、理科、英語）の教科の点数を入力してしてください。
入力する部分を関数にして、引数に教科の点数をいれる配列を渡してください。
最後に、合計点数と平均点を表示しましょう。
*/
#include"20240826_header1_imai.h"

int main(void)
{
    //定数
    const int INDEX = 5;

    //変数
    int sum = 0;
    float avg;
    int grades[INDEX] = {};
    printf("5教科（国語、数学、社会、理科、英語）の教科の点数を入力してしてください。\n");
    printf("点数は0～100点までです。\n");
    //点数の入力
    inputGrade(grades, INDEX);
    //参照渡しにして、合計点数と平均点を算出しましょう
    calculation(grades, INDEX, sum, avg);
  

    printf("合計点数%dです\n平均点数が%.1f", sum, avg);
    return 0;
}