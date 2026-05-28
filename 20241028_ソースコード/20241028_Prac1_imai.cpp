/*0から100までのランダムな整数を含む配列が与えられます。
この配列の合計を、ポインターのインクリメントとデクリメントのみを使って計算する関数を作成してください。
条件
配列のサイズは任意としますが、例として5つの要素を含む配列を使用します。
配列の内容は0から100までのランダムな整数で埋めます。
例
配列が [34, 67, 23, 89, 12] の場合、合計は 225 となります。*/
#include"20241028_header1_imai.h"

int main(void)
{
    const int INDEX = 5;
    int arry[INDEX];
    int i,sum = 0;

    //乱数の初期化
    srand((unsigned int)time(NULL));

    for ( i = 0; i < INDEX; i++)
    {
        arry[i] = rand() % 101;
    }

    printf("配列の内容：");
    for ( i = 0; i < INDEX; i++)
    {
        printf("%d ", arry[i]);
    }

    printf("\n");
    //合計
    sum = sumArray(arry, INDEX);
    printf("合計：%d",sum);
    return 0;
}