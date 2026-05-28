#include "202410296_header2_imai.h"
/*
C言語を使用して、整数の配列を処理するプログラムを作成してください。
※配列はランダムで0～30を10個入れてください
引数:
int* arr: 整数の配列へのポインタ。
int size: 配列の要素数。
戻り値:
配列内の最小値を持つ要素のポインタを返します。
もし配列が空またはNULLポインタが渡された場合はNULLを返します。
プログラムの出力:
main 関数で、整数の配列を用意し、find_min 関数を呼び出します。
戻り値がNULLでない場合、最小値を出力します。NULLの場合は「配列が空またはNULLポインタです。」と表示します。
*/
int main(void)
{
    //定数
    const int INDEX = 5;
    const int MAX_NUM = 31;
    //変数
    int nums[INDEX] = {};

  /*  srand((unsigned int)time(NULL));
    for (int i = 0; i < INDEX; i++)
    {
        nums[i] = rand() % MAX_NUM;
        printf("%d番目:%d, ", i + 1, nums[i]);
    }*/

    //ポインタ変数
    int* min_ptr = find_min(nums, INDEX);

    if (min_ptr != NULL)
    {
        printf("\n最小値：%d\n", *min_ptr);
    }
    else
    {
        printf("\n配列が空またはNULLポインタです。\n");
    }

    return 0;
}