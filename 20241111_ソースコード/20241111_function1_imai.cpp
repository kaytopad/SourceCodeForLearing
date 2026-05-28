#include"20241111_header1_imai.h"

int count_char(char* str, char target)
{
    int count = 0,i;
    
    for ( i = 0; i < str[i] != '\0'; i++)
    {
        if (str[i] == target)
        {
            count++;
        }
    }

    return count;
}