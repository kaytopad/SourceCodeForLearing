/*
CPUとの対戦ゲームとして3つの数字を当てましょう。
０～9までのランダムな数字を生成しましょう。
お互いに交互に入力し、場所と数字があっていたら「Hit」、外れていたら「Miss」を表示しましょう。
3つ当たったら、勝利となります。
作成する関数は、Game関数、InputCheck関数（入力チェック）、Judgement関数を作成してください。
※ほかに追加で関数を作成しても問題ありません。
*/

#include"20240826_header2_imai.h"

int main(void)
{
    //定数
    const int INDEX = 3;

    //変数
    int plyCard[INDEX] = {}, emyCard[INDEX] = {};
    //乱数の初期化
    srand((unsigned int)time(NULL));
    //カードを配る
    createCrad(plyCard, INDEX);
    printf("PLAYER'SCard\n");
    displayCard(plyCard, INDEX);
    createCrad(emyCard, INDEX);
    printf("３つの数字と場所を全て当てましょう！\n");
    Game(plyCard, emyCard, INDEX);

    printf("answer\n");
    displayCard(plyCard, INDEX);
    displayCard(emyCard, INDEX);
    return 0;
}