#include"20240826_header1_imai.h"

int InputCheck(int min, int max)
{
    int num;

    while (true)
    {
        scanf("%d", &num);
        if (min > num || max < num)
        {
            printf("入力に誤りがあります。再度入力してください。\n");
        }
        else
        {
            break;
        }
    }
    return num;
}

void inputGrade(int grades[], int index)
{
    int i;
    for ( i = 0; i < index; i++)
    {
        subjectName(i);
        grades[i] = InputCheck(0,100);
    }
}

int totalScore(int grades[], int index)
{
    int sum= 0;

    for (int i = 0; i < index; i++)
    {
        sum += grades[i];
    }
    return sum;
}

float averageScore(int sum, int subject)
{
    float avg;

    avg = (float)sum / subject;

    return avg;
}


void subjectName(int subjectNumber)
{
    switch (subjectNumber)
    {
    case 0:
        printf("国語の点数を入力してください\n");
        break;
    case 1:
        printf("数学の点数を入力してください\n");
        break;
    case 2:
        printf("社会の点数を入力してください\n");
        break;
    case 3:
        printf("理科の点数を入力してください\n");
        break;
    case 4:
        printf("英語の点数を入力してください\n");
        break;

    }
}

void calculation(int grades[], int index, int& sum, float& avg)
{

    for (int i = 0; i < index; i++)
    {
        sum += grades[i];
    }

    avg = (float)sum / index;
}