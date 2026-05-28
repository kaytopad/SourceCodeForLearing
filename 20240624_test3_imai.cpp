/*
ジャックポット
概要：
・CPUとプレイヤーが交互に２つの六面サイコロを振り、1から9までのマスを陣取りするゲームです。

ゲームの流れ：
・プレイヤーは交互に六面サイコロを2個振る。
・出た目の数に合わせて、対応するマスを取ることができます。
　プレイヤーは以下のうち1つを選択できる:
　　①六面サイコロの目
　　②六面サイコロの目の合計
例：
　六面サイコロの目が、1と5の場合→1、5、6のどれかのマスを取る事が出来ます。
・取られているもしくは取っている場合は、取る事はできません。
・この一連の動作を交互に行ってください。
ゲームの終了：
・どちらかのプレイヤーがマスを取る事が出来なくなった時点でゲーム終了。
・もし全てのマスが取った場合、そのターンでマスを取ったプレイヤーが勝ちとなります。
*/
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#pragma warning(disable:4996)

//定数
const int NUM_BOARDS = 9;        //ボードの枚数
const int NUM_DICE = 6;         //サイコロの目数
const int NUM_DICEROLL = 3;      //サイコロ出目

int main(void)
{
    //変数宣言
    int i;
    //ターンチェック
    int checkTrun = 1;
    //ボード
    bool board[NUM_BOARDS];
    //出た目
    int rollDice[NUM_DICEROLL] = { 0,0,0 };
    int cnt = 0;
    int choice = 0;
    //全て取られたか？
    bool allAcquisition = true;
    //出た目以外での数字
    bool numChoice;
    //乱数の初期化
    srand((unsigned int)time(NULL));
    //ボードの初期化
    for ( i = 0; i < NUM_BOARDS; i++)
    {
        board[i] = true;
    }
    printf("====JACKPOT GAME=====\n");
    printf("CPUとプレイヤーが交互に２つの六面サイコロを振り、1から9までのマスを陣取りするゲームです\n先攻はプレイヤーからです\n");
    printf("====GAME START=====\n");
    while (true)
    {
        //初期化
        cnt = 0;
        switch (checkTrun)
        {
        case 1:
            printf("===PLAYER TURN===\n");
            break;
        case 2:
            printf("===ENEMY TURN===\n");
            break;
        }
        //6面サイコロを２個振る機能
        for ( i = 0; i < NUM_DICEROLL; i++)
        {
            if (i == 2 )
            {
                rollDice[i] = rollDice[0] + rollDice[1];
            }
            else
            {
                rollDice[i] = rand() % NUM_DICE + 1;

            }
            printf("%d,", rollDice[i]);

        }
        printf("\n");
        //マスの状態を管理する機能
        for ( i = 0; i < NUM_DICEROLL; i++)
        {
            if (rollDice[i] > 9)
            {
                cnt++;
            }
            if (!board[rollDice[i]-1])
            {
                cnt++;
            }
        }
        if (cnt == 3 )
        {
            printf("取れるマスがありません\n");
            switch (checkTrun)
            {
            case 1:
                printf("ENEMY WINNER\n");
                break;
            case 2:
                printf("PLAYER WINNER\n");
                break;
            }
            break;
        }
        //出た目に対応するマスを獲得する機能
        printf("取るマスを選択してください。");
        for ( i = 0; i < NUM_BOARDS; i++)
        {
            if (board[i])
            {
                printf("%d,", i + 1);
            }
        }
        printf("\n");
        //獲得するマスの選択
        while (true)
        {
            switch (checkTrun)
            {
            case 1:
                scanf("%d", &choice);
                break;
            case 2:
                choice = rollDice[rand()%NUM_DICEROLL];
                break;
            }
            numChoice = false;
            for ( i = 0; i < NUM_DICEROLL; i++)
            {
                if (choice == rollDice[i] && choice >= 1 && choice <= NUM_BOARDS && board[choice - 1])
                {
                    numChoice = true;
                    break;
                }

            }

            if (numChoice)
            {
                board[choice - 1] = false;
                break;
            }
            else
            {
                printf("入力に誤りがあります。再度入力してください。\n");
            }


            
        }
        //全て獲得フラグを設定
        allAcquisition = true;
        //ゲームの終了を判定する機能
        for ( i = 0; i < NUM_BOARDS; i++)
        {
            if (board[i])
            {
                allAcquisition = false;
                break;
            }
        }
        if (allAcquisition)
        {
            printf("全てマスを獲得しました。\n");
            switch (checkTrun)
            {
            case 1:
                printf("PLAYER WINNER & ALL COMPLETE\n");
                break;
            case 2:
                printf("ENEMY WINNER & ALL COMPLETE\n");
                break;
            }
            break;
        }
        //2人プレイヤーのターンを管理する機能
        checkTrun = (checkTrun == 1) ? 2 : 1;

    }
    return 0;
}