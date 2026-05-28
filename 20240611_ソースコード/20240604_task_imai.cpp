#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#pragma warning(disable:4996)
/*
PLAYERとCPUでそれぞれ3枚の数字のカードを持ています。
※数字は0～9までです。
※数字はランダムで選択します。
※数字は重複しても構いません。
それをCPUより先に全て当てましょう。
入力して数字と場所が一緒なら、"Hit"を表示
数字のみあっていたら、"Chip"を表示
当てっていないときは、"Null"を表示
選択は、キーボードから入力し、CPUはランダムで選択します。
3Hitが表示されたらゲーム終了です。
PLAYERが全て正解なら「PLAYER WINNER」を表示
CPUが全て正解なら「CPU WINNER」を表示
*/
//定数宣言
const int index = 3;

int main(void)
{
    //変数宣言
    int i, j;                   //カウント
    int plyAry[index] = {};     //プレイヤー手札
    int emyAry[index] = {};     //CPUの手札
    int plyAns[index] = {};     //プレイヤーの選択した数字
    int emyAns[index] = {};     //CPUの選択した数字

    int hit = 0,chip = 0,null = 0;  //Hit、Chip、Nullカウント
    int hitBefore, chipbefore;      //Null確認
    bool winorLose = false;         //勝敗フラグ
    //乱数の初期化
    srand((unsigned int)time(NULL));
    //手札の配布（重複有）
    for ( i = 0; i < index; i++)
    {
        plyAry[i] = rand() % 10;
        emyAry[i] = rand() % 10;
    }

    printf("PLAYERHand：");
    for ( i = 0; i < index; i++)
    {
        printf("%d,", plyAry[i]);
    }


    printf("\nゲームスタート");
    //ゲームスタート
    while (true)
    {
        //プレイヤーの選択（入力チェック）
        printf("PLAYERTURN：0～9で3つ選択してください。\n");
        for ( i = 0; i < index; i++)
        {
            while (true)
            {
                scanf("%d", &plyAns[i]);
                if (0 > plyAns[i] || 9 < plyAns[i])
                {
                    printf("入力に誤りがあります。再度入力してください。\n");
                }
                else
                {
                    break;
                }
            }
        }
        //プレイヤーの答えのチェック
        for ( i = 0; i < index; i++)
        {
            hitBefore = hit;
            chipbefore = chip;
            for ( j = 0; j < index; j++)
            {
                //Hitカウント
                if (i == j && plyAns[i] == emyAry[j])
                {
                    hit++;
                    break;
                }
                //Chipカウント
                else if (plyAns[i] == emyAry[j])
                {
                    chip++;
                    
                }

            }

            if (hitBefore == hit && chipbefore == chip)
            {
                null++;
            }

        }
        printf("%dHit：%dChip：%dNull\n", hit, chip, null);
        //答えが正解ならbreakで抜ける違ったら、CPUへターン移動
        if (hit == 3)
        {
            printf("BINGO\n");
            //勝敗フラグをtrueに変換
            winorLose = true;
            break;

        }
        else
        {
            printf("もう一回です。\n");
            hit = 0;
            chip = 0;
            null = 0;
        }
        //CPUの選択（ランダム）
        for ( i = 0; i < index; i++)
        {
            emyAns[i] = rand() % 10;
            printf("%d,",emyAns[i]);
        }
        printf("\n");
        //CPUの答えのチェック
        for (i = 0; i < index; i++)
        {
            hitBefore = hit;
            chipbefore = chip;
            for (j = 0; j < index; j++)
            {
                //Hitカウント
                if (i == j && emyAns[i] == plyAry[j])
                {
                    hit++;
                    break;
                }
                //Chipカウント
                else if (emyAns[i] == plyAry[j])
                {
                    chip++;

                }

            }

            if (hitBefore == hit && chipbefore == chip)
            {
                null++;
            }

        }
        printf("%dHit：%dChip：%dNull\n", hit, chip, null);
        //答えが正解ならbreakで抜ける違ったら、もう一回
        if (hit == 3)
        {
            printf("BINGO\n");
            break;

        }
        else
        {
            printf("もう一回です。");
            hit = 0;
            chip = 0;
            null = 0;
        }
        

    }

    //プレイヤーが3HitであればPLAYERWINNERが表示
    if (winorLose)
    {
        printf("PLAYERWINNER\n");
    }
    else
    {
        //CPUが3HitならCPUWINNERが表示
        printf("CPUWINNER\n");

    }



    return 0;
}