#include"20241015_header1_imai.h"

void display(int number)
{
	switch (number)
	{
	case 0:
		printf("国語");
		break;
	case 1:
		printf("数学");
		break;
	case 2:
		printf("社会");
		break;

	case 3:
		printf("理科");
		break;

	case 4:
		printf("英語");
		break;


	default:
		break;
	}
}

void checkInput(int min, int max, int* tmp)
{

    int num;
	while (true)
	{
		scanf("%d", &num);
		if (num < min || num > max )
		{
			printf("入力に誤りがあります。再度入力してください。\n");
		}
		else
		{
			*tmp = num;
			break;
		}
	}
}

void gradeBook(int* grade,int size)
{
	int score;
	for (int i = 0; i < size; i++)
	{
		display(i);
		printf("を入力してください。\n");
		checkInput(0, 100, &score);
		grade[i] = score;
	}
}

void calculattion(int* greade, int* sum, double* avg, int size)
{
	*sum = 0;
	for (int i = 0; i < size; i++)
	{
		*sum += greade[i];
	}

	*avg = static_cast<double>(*sum) / size;
}