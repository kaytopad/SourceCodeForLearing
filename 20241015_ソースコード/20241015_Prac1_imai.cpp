#include"20241015_header1_imai.h"
/*
5教科のテスト点数と平均点を出しましょう。
5教科（国語、数学、社会、理科、英語）の教科の点数を入力してしてください。
入力する部分を関数にして、引数に教科の点数をいれるポインターを配列の代わりに使いましょう。
最後に、合計点数と平均点を表示しましょう。
*/
int main(void)
{
    const int INDEX = 5;
    //変数宣言（配列、ポインター変数を含む）
    int sum;
    double avg;
    int greade[INDEX];
    int* grea = greade;
    //各教科入力
    gradeBook(grea, INDEX);
    //合計＆平均点計算
    calculattion(grea,&sum,&avg,INDEX);
    //解答出力
    printf("合計点数：%d \n 平均点 : %.2f",sum,avg);
    return 0;
}