/*
2枚以上のカードで21に近づけたら勝ちです。
プレイヤーとCPUの2人の勝負となります。
数字が1～11までのカードを2枚受け取ります。
この時に、どちらかが21になった場合はゲーム終了となり、21になった方が勝ちとなります。
カードを引くかどうかを決めます。
引くを決めたら、カードを追加します。
この時に、22以上になってしまったらゲームに敗北になります。
引かないを決めたらCPUのターンに移行します。
CPUは、プレイヤーより小さい場合はカードを自動的に引きます。
大きくなるか、22以上になる場合は終了です。
お互いが21の場合は引き分けです。
選択のための入力を、Yesを0、Noを1とします。
各種関数は、関数プロトタイプ宣言を行い、メイン関数のあとに作成しましょう。
*/
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#pragma warning(disable:4996)

//定数
const int MIN_CARD = 1;
const int MAX_CARD = 11;
const int BURST_NUM = 21;
const int DROW_CARD = 2;
//関数プロトタイプ宣言
int inputCheck(int min, int max);
int drowCard();
bool judge(int ply, int emy);
int playerTrun(int sum);
int enemyTrun(int ply, int emy);

int main(void)
{
    int plySum = 0, emySum = 0;
    int i;
    bool gameFlag = false;
    srand((unsigned int)time(NULL));

    //ゲームスタート
    while (true)
    {
        //カード2枚引きます
        for ( i = 0; i < DROW_CARD; i++)
        {
            plySum += drowCard();
        }
        for ( i = 0; i < DROW_CARD; i++)
        {
            emySum += drowCard();
        }
        printf("PLAYER : %d\nENEMY：%d\n", plySum, emySum);
        //21以上になっていないか確認
        gameFlag = judge(plySum, emySum);
        if (gameFlag)
        {
            break;
        }
        //PLAYERTURN
        plySum = playerTrun(plySum);
        gameFlag = judge(plySum, emySum);
        if (gameFlag)
        {
            break;
        }
        //ENEMYTURN
        emySum = enemyTrun(plySum, emySum);
        gameFlag = judge(plySum, emySum);
        if (gameFlag)
        {
            break;
        }

    }

    //結果表示
    if (plySum == BURST_NUM)
    {
        printf("BLACKJACK！！PLAY WINNER");
    }
    else if (emySum == BURST_NUM)
    {
        printf("BLACKJACK！！ENEMY WINNER");
    }
    else if (plySum > emySum || emySum > BURST_NUM)
    {
        printf("PLAYER WIINER\n");
    }
    else if (plySum == emySum)
    {
        printf("DRAW\n");
    }
    else
    {
        printf("ENEMY WIINER\n");
    }
    return 0;
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

int drowCard()
{
    int num;
    //ランダムなカード生成
    num = rand() % MAX_CARD + MIN_CARD;
    //引いたカードを表示
    printf("引いたカードは%d\n", num);
    return num;
}

bool judge(int ply, int emy)
{
    bool flg = false;
    
    if ((ply == BURST_NUM || emy == BURST_NUM) || (ply == BURST_NUM && emy == BURST_NUM))
    {
        flg = true;
    }
    else if (ply > BURST_NUM || emy > BURST_NUM)
    {
        flg = true;
    }

    return flg;
}

int playerTrun(int sum)
{
    int plySelect = 0;
    bool flg = false;
    while (true)
    {
        printf("PLAYER TRUN\n現在の数字%dです。\nカードを引きます\nYes:0 No:1\n",sum);
        //カードを引きますか？
     
        plySelect = inputCheck(0, 1);
        if (plySelect == 0)
        {
            sum += drowCard();
            flg = judge(sum, 1);
            if (flg)
            {
                break;
            }
        }
        else
        {
            break;
        }

    }

    return sum;

}

int enemyTrun(int ply, int emy)
{
    bool flg = false;

    while (true)
    {
        printf("ENEMY TRUN\n現在の数字%dです。", emy);

        if (ply > emy || emy != BURST_NUM)
        {
            emy += drowCard();
            flg = judge(ply, emy);
            if (flg)
            {
                break;
            }
        }
        else if (ply == emy)
        {
            break;
        }

    }

    return emy;
}