#include<stdio.h>
#pragma warning(disable:4996)
int main(void)
{
	//入力した数字で判断する80以上なら「OK」を表示、それ以下なら「NG」を表示させます。
	int num;
	printf("数字を入力してください\n");
	scanf("%d", &num);

	if (num >= 80)
	{
		printf("OK\n");
	}
	else if (num <= 80)
	{
		printf("NG\n");
	}

	return 0;
}

