#include "20251110_header2_imai.h"

bool isSorted(int strNumber[], int index)
{
	int i;
	for ( i = 0; i < index - 1; i++)
	{
		if (strNumber[i] > strNumber[i + 1])
		{
			return false;
		}
	}

	return true;
}

int checkInput(int min, int max)
{
	int input;
	while (true)
	{
		scanf("%d", &input);

		if (min > input || max < input)
		{
			printf("入力された値が違います。再度入力してください。\n");
		}
		else
		{
			break;
		}

	}

	return input;


}

void displayNumbers(int strNumbers[], int index)
{
	for (int i = 0; i < index; i++)
	{
		printf("%d,", strNumbers[i]);
	}
	printf("\n");
}