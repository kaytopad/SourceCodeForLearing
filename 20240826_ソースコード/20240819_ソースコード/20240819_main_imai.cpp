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
#include"20240819_header_imai.h"


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
        for (i = 0; i < DROW_CARD; i++)
        {
            plySum += drowCard();
        }
        for (i = 0; i < DROW_CARD; i++)
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
    Result(plySum, emySum);
    return 0;
}
