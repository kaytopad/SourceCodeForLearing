#include"20241112_header2_imai.h"

void reverse_string(char* str)
{
	char* start;
	char* end;
	char tmp;
	int len = strLen(str);

	for (int i = 0; i < len / 2; i++)
	{
		tmp = str[i];
		str[i] = str[len - 1 - i];
		str[len - 1 - i] = tmp;
	}
}

int strLen(char* str)
{
	int cnt = 0;
	while (*str++)
	{
		cnt++;
	}
	return cnt;
}
