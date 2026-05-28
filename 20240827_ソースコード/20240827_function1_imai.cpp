#include"20240827_header1_imai.h"

void charcterCreate(Status charcter[], int index)
{
    srand((unsigned int)time(NULL));

    for (int i = 0; i < index; i++)
    {
        printf("%d人目\n",i+1);
        printf("名前を入力してください。\n");
        scanf("%s", &charcter[i].name);

        printf("性別を入力してください。\n 0:男,1:女\n");
        charcter[i].gernder = inputCheck(0, 1);
        printf("種族を入力してください。\n 0:人間,1:エルフ,2:ドワーフ,3:ホビット\n");
        charcter[i].tribe = inputCheck(0, 3);

        //能力生成
        charcter[i].HP = rand() % STU_HPMP_MAX + STU_HPMP_MIN;
        charcter[i].MP = rand() % STU_HPMP_MAX + STU_HPMP_MIN;
        charcter[i].ATK = rand() % STU_SKL_MAX + STU_SKL_MIN;
        charcter[i].DEF = rand() % STU_SKL_MAX + STU_SKL_MIN;
        charcter[i].AGI = rand() % STU_SKL_MAX + STU_SKL_MIN;
    }

}

void abillityCorrection(Status charcter[], int index)
{
    for (int i = 0; i < index; i++)
    {
        switch (charcter[i].tribe)
        {
        case 0:
            charcter[i].HP += 2;
            charcter[i].MP += 2;
            charcter[i].ATK += 2;
            charcter[i].DEF += 2;
            charcter[i].AGI += 2;
            break;
        case 1:
            charcter[i].HP -= 3;
            charcter[i].MP += 8;
            charcter[i].ATK -= 3;
            charcter[i].DEF -= 3;
            charcter[i].AGI += 8;
            break;
        case 2:
            charcter[i].MP -= 5;
            charcter[i].ATK += 8;
            charcter[i].DEF += 8;
            charcter[i].AGI -= 5;
            break;
        case 3:
            charcter[i].HP += 8;
            charcter[i].MP -= 4;
            charcter[i].DEF -= 4;
            charcter[i].AGI += 8;
            break;
        }

        if (charcter[i].ATK < 5)
        {
            charcter[i].ATK = 5;
        }
        if (charcter[i].DEF < 5)
        {
            charcter[i].DEF = 5;
        }
        if (charcter[i].AGI < 5)
        {
            charcter[i].AGI = 5;
        }
    }
}

void displayParty(Status party[], int index)
{
    for (int i = 0; i < index; i++)
    {
        printf("---------------------------------------------------------\n");
        printf("名前:%S\n",party[i].name);
        printf("性別:");
        genderDisplay(party[i].gernder);
        printf("種族:");
        tribeDisplay(party[i].tribe);
        printf("HP:%d\nMP:%d\nATK:%d\nDEF:%d\nAGI:%d\n",party[i].HP,party[i].MP,party[i].ATK,party[i].DEF,party[i].AGI);
        printf("---------------------------------------------------------\n");
    }
}

void genderDisplay(int gen)
{
    switch (gen)
    {
    case 0:
        printf("男性\n");
        break;
    case 1:
        printf("女性\n");
        break;
    }
}

void tribeDisplay(int tri)
{
    switch (tri)
    {
    case 0:
        printf("人間\n");
        break;
    case 1:
        printf("エルフ\n");
        break;
    case 2:
        printf("ドワーフ\n");
        break;
    case 3:
        printf("ホビット\n");
        break;
    }
}

int inputCheck(int min, int max)
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