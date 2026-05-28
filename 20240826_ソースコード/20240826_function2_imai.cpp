#include"20240826_header2_imai.h"

void Game(int ply[], int emy[], int index)
{
    int plyAnswer[3] = {}, emyAnswer[3] = {};
    bool plyFlg = false;
    bool emyFlg = false;
    while (!plyFlg && !emyFlg)
    {
        printf("PLAYERS TRUN\n");
        printf("３つの数字を入力してください。");
        inputNumber(plyAnswer, index);
        
        plyFlg = Judgement(plyAnswer, emy,index);

        if (plyFlg)
        {
            break;
        }
        printf("ENEMYS TRUN\n");
        createCrad(emyAnswer, index);
        displayCard(emyAnswer, index);
        emyFlg = Judgement(emyAnswer, ply,index);

    }
   
    if (plyFlg)
    {
        printf("PLAYERWINNER\n");
    }
    else if (emyFlg)
    {
        printf("ENEMYWINNER\n");
    }

}

bool Judgement(int input[], int ans[], int index)
{
    bool flg = false;
    int hit = 0, Miss = 0;
    for (int i = 0; i < index; i++)
    {
        if (input[i] == ans[i])
        {
            hit++;
        }
        else 
        {
            Miss++;
        }
    }
    printf("%dHIT：%dMISS\n", hit, Miss);

    if (hit == 3)
    {
        flg = true;
    }

    return flg;
}

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

void createCrad(int crad[], int index)
{
    for (int i = 0; i < index; i++)
    {
        crad[i] = rand() % NUM_MAX; 
    }
}

void inputNumber(int inputAry[], int index)
{
    for (int i = 0; i < index; i++)
    {
        inputAry[i] = InputCheck(0, 9);
    }
}
void displayCard(int card[], int index)
{
    for (int i = 0; i < index; i++)
    {
        printf("%d:%d\n", i + 1, card[i]);
    }
}