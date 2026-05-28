#include<stdio.h>
/*
ポインタ変数pNumを作成してください。
変数pNumをNullポインタで初期化
初期化を確認しましょう。
*/
int main(void)
{
    //ポインタ変数
    int* pNum = NULL;

    if (!pNum)
    {
        printf("pNumは初期化されています");
    }
    else
    {
        printf("pNumは初期化されていません。");
    }

    return 0;
}