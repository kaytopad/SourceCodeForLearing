#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#pragma warning(disable:4996)

/*
Eゲーム
0:King(王様)　1:Citizen(市民)　2:Servant(下僕)とします。
CPUは、0:Kingか1:Citizenを選択します。
PLAYERは、1:Citeizenか2:Servantが選べます。
Playerが勝った時は、「PlayerWIN」を表示しましょう。
CPUが勝った時は、「CPUWIN」を表示しましょう。
同じなら「Draw」を表示します。
KingとCitizenでは、Kingの勝ちとなります。
CitizenとServantでは、Citizenの勝ちになります。
KingとServantでは、Servantが勝ちとなります。
printCard関数を作成し、PLAYERとCPUで選んだカード名を表示しましょう。
inputCheck関数を作成し、PLAYERの入力チェックを行いましょう。
judgeGame関数を作成し、ゲームの判定を行い結果を表示させましょう。
*/


//定数
const int NUMBER = 2;
const int MIN = 1;
const int MAX = 2;

//カード表示関数
void printCard(int select)
{
    switch (select)
    {
        case 0:
            printf("KING(王様)\n");
            break;
        case 1:
            printf("Citizen(市民)\n");
            break;
        case 2:
            printf("Servant(下僕)\n");
            break;
    }
}

//入力チェック関数
int inputCheck(int min, int max)
{
    int card;
    while (true)
    {
        scanf("%d", &card);
        if (min > card || max < card)
        {
            printf("入力に誤りがあります。再度入力してください。\n");
        }
        else
        {
            break;
        }

    }

    return card;
}
//ゲーム判定
void judgeGame(int ply, int emy)
{
    int judg;
    judg = ply - emy;

    if (judg == 2)
    {
        printf("PLAYER WINNER\n");
    }
    else if (judg == 0)
    {
        printf("Draw\n");
    }
    else
    {
        printf("CPU WINNER\n");
    }

}

int main(void)
{
    //変数宣言
    int ply, emy;
    //乱数の初期化
    srand((unsigned int)time(NULL));

    printf("Eゲーム\n0:King(王様)　1:Citizen(市民)　2:Servant(下僕)し、その中から選びましょう。\n");
    printf("CPUは、0:Kingか1:Citizenを選択します。\nPLAYERは、1:Citeizenか2:Servantが選べます。\n");
    printf("KingとCitizenでは、Kingの勝ちとなります。\nCitizenとServantでは、Citizenの勝ちになります。\nKingとServantでは、Servantが勝ちとなります。\n");
    printf("PLAYERは手を入力してください。\n");

    //ランダムな手を作成
    emy = rand() % NUMBER;
    //プレイヤー入力
    ply = inputCheck(MIN, MAX);
    //カードの表示
    printf("PLAYER'S SELECT : ");
    printCard(ply);
    printf("CPU'S SELECT : ");
    printCard(emy);

    //勝負判定
    judgeGame(ply, emy);

    return 0;
}