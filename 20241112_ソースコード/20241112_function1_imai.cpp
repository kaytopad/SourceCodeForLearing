#include"20241112_header1_imai].h"
#include<stdio.h>

int strlen(char* str)
{
    int cnt = 0;

	while (*str++)
	{
		cnt++;
	}
	return cnt;
}

void strcpy(char* str, char* dst) 
{
	while (*str++)
	{
		*dst = *str;
		*dst++;
	}
	*dst = '\0';
}