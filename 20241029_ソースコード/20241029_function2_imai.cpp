#include "202410296_header2_imai.h"

int* find_min(int* arr, int size)
{
    int* min_ptr;

    if (arr == NULL || size == 0)
    {
        return NULL;
    }
    //Å¬’l‚Ì‰Šú‰»
    min_ptr = &arr[0];

    for (int i = 0; i < size; i++)
    {
        if (arr[i] < *min_ptr)
        {
            min_ptr = &arr[i];
        }
    }
    return min_ptr;
}