#include<stdio.h>
#pragma warning(disable:4996)

void printPiramid(int n)
{
    int i, j;
	for ( i = 0; i < n; i++)
	{
		for ( j = 0; j < n-i-1; j++)
		{
			printf(" ");
		}
		for (j = 0; j < (i*2)+1; j++)
		{
			printf("*");
		}

		printf("\n");

	}
}

int main(void)
{
	int n;
	printPiramid(5);
	printf("ピラミッドの段数:");
	scanf("%d", &n);
	printPiramid(n);
	return 0;

}