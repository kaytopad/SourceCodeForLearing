#include"20241028_header1_imai.h"

int sumArray(int* arr, int size)
{
    int sum = 0,i;
    //配列の先頭を指すポインタ
    int* ptr = arr;

    for ( i = 0; i < size; i++)
    {
        sum += *ptr;
        ptr++;
    }
    return sum;
}