#include"20240820_header2_imai.h"

/*
PK戦
プレイヤーとCPUで交互にキッカーとキーパーの役目を行い、5回行いましょう。
蹴る方向は、0:正面　1:左下　2:右下　3：左上　4：右上となります。
同じであれば止められて得点にはなりません。異なれば得点となります。
方向が同じであれば（右であれば、右下か右上）、25％の確率でキーパーに止められる。
3点先に先取した方が勝ちとなります。
同点であれば、サドンデス（延長戦）となり、どちらかが多く得点を取った方が勝ちとします。
最終的に、どちらが勝ったかを表示させましょう。
inputCheck関数を作成し、入力をチェックしましょう。
game関数でゲームの流れを作ります。
keeper関数で止められるかどうかを判定させましょう。また、スコアは参照渡しでメイン関数に渡しましょう。
*/

int main(void)
{
    //定数
    const int MIN = 0;
    const int MAX = 5;
    const int SCORE = 3;

    int playerScore = 0, enemyScore = 0;
    //乱数の初期化
    srand((unsigned int)time(NULL));
    //インフォメーション
    printf("コパアメリカ決勝！アルゼンチンvsウルグアイ\n120分の激闘でも決着がつかず、ＰＫ戦に突入しました。\n");


    //ゲーム関数呼び出し
    game(MIN, MAX, SCORE,playerScore,enemyScore);

    Result(playerScore, enemyScore);

    return 0;
}