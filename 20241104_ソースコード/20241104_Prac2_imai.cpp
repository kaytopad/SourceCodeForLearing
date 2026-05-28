#include"20241104_header2_imai.h"
/*
プレイヤーと敵が交互に攻撃を行う戦闘シミュレーションを作成しましょう。
プレイヤーと敵のステータス（HPと攻撃力）はランダムで初期化され、戦闘中のダメージもランダムで決まります。
要件
構造体の定義
Playerという構造体を定義してください。この構造体は、以下のメンバーを持ちます：
name（文字列）：プレイヤーまたは敵の名前を格納
hp（int型）：プレイヤーまたは敵のHP（ヒットポイント）
attack（int型）：プレイヤーまたは敵の攻撃力
ランダムなステータスの初期化
initializePlayerという関数を作成してください。
この関数は、構造体ポインターPlayer *playerと、名前を指定するconst char *nameを受け取り、以下のようにプレイヤーまたは敵のステータスを初期化します。
HPと攻撃力はそれぞれ15～55の範囲でランダムな値を設定する。
ダメージ処理
damagePlayerという関数を作成してください。
この関数は、構造体ポインターPlayer *playerと、ダメージ量damage（int型）を受け取り、以下の処理を行います：
ダメージ量をplayer->hpから減算する。ただし、player->hpは0以下にはならないようにする（0未満の場合は0とする）。
戦闘シミュレーション
battleという関数を作成してください。
この関数は、プレイヤーと敵のPlayer構造体のポインターを引数に受け取り、以下の処理を行います：
プレイヤーと敵が交互に攻撃を行うループを構築する。
各攻撃は、5～最大攻撃力の範囲でランダムなダメージ量を決定し、相手のHPからそのダメージ量を引く。
戦闘の過程で、プレイヤーと敵の現在のHPを表示する。
プレイヤーか敵のHPが0以下になった時点で戦闘終了し、勝者を判定してメッセージを表示する。
プログラムの流れ
プレイヤーと敵の構造体を作成し、名前を設定します。
initializePlayer関数でプレイヤーと敵のHPおよび攻撃力を15～55の範囲でランダムに初期化します。
初期化されたプレイヤーと敵のステータスを表示します。
battle関数を呼び出し、戦闘を開始します。プレイヤーと敵が交互に攻撃し、HPが0になった側が敗北します。
戦闘が終了すると結果が表示されます。
※1：HPや攻撃力の範囲は、問題で指定された範囲（15～55や5～最大攻撃力）を使用してください。
※2：プレイヤーと敵が交互に攻撃する際、それぞれの攻撃結果や現在のHPを表示し、戦闘の進行をわかりやすくするようにしてください。
*/

int main(void) 
{
    //構造体変数
    Player player;
    Player enemy;
    char plyName[50];
    char enyName[50];
    //乱数の初期化
    srand((unsigned int)time(NULL));
    //プレイヤー名前を入力
    printf("プレイヤーの名前を入力してください。\n");
    scanf("%s", &plyName);
    //敵の名前を入力
    printf("敵の名前を入力してください。\n");
    scanf("%s", &enyName);

    //初期化
    initializePlayer(&player, plyName);
    initializePlayer(&enemy, enyName);
    printf("名前：%s HP : %d Attack : %d\n", player.name, player.hp, player.attack);
    printf("名前：%s HP : %d Attack : %d\n", enemy.name, enemy.hp, enemy.attack);
    //戦闘処理
    battle(&player, &enemy);

    //結果表示

    if (player.hp > enemy.hp)
    {
        printf("%sの勝利です！！\n", player.name);
    }
    else
    {
        printf("%sの勝利です！！\n", enemy.name);
    }

    return 0;

}