#include"20241104_header1_imai.h"

void studentInput(Student* student)
{
	//名前入力フラグ
	bool isValidName;
	//得点入力フラグ
	bool isVaildScore;
	//数字入力
	char scoreInput[10];
	//名前の入力
	while (true)
	{
		printf("名前を入力してください。\n");

		scanf("%S", &student->name);
		isValidName = true;
		for (int i = 0; i < strlen(student->name); i++)
		{
			if (!isalpha(student->name[i]))
			{
				isValidName = false;
				break;
			}
		}

		if (isValidName == false)
		{
			printf("名前に数字が入力されました。再度入力してください。\n");
		}
		else
		{
			break;
		}

	}
	//得点の入力
	while (true)
	{
		printf("得点を入力してください。\n");
		scanf("%s", &scoreInput);
		isVaildScore = true;
		for (int i = 0; i < strlen(scoreInput); i++)
		{
			if (!isdigit(scoreInput[i]))
			{
				isVaildScore = false;
				break;
			}
		}
		if (isVaildScore == false)
		{
			printf("得点は整数で入力してください。\n");
		}
		else
		{
			student->score = atoi(scoreInput);

			if (0 > student->score || 100 < student->score)
			{
				printf("0から100の範囲で入力してください。\n");
			}
			else
			{
				break;
			}

		}
	}



}

void grade(Student* student)
{
	if (student->score >= 90)
	{
		student->grade = 'S';
	}
	else if (student->score >= 70)
	{
		student->grade = 'A';
	}
	else if (student->score >= 50)
	{
		student->grade = 'B';
	}
	else if (student->score >= 30)
	{
		student->grade = 'C';
	}
	else
	{
		student->grade = 'D';
	}
}