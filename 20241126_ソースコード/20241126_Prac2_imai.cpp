/*

キャラクター管理システム：
RPGゲームのキャラクターを管理するシステムを作成しようとしています。このゲームでは、プレイヤーキャラクター（主人公）を操作し、敵と戦います。
以下が仕様になります。
クラス名：Character
RPGのキャラクターを表します。

メンバ変数
string name：キャラクターの名前
int health：キャラクターの体力（初期値は指定可能、プレイヤーは25～200、敵は5～30の範囲でランダム）
int attackPower：キャラクターの攻撃力（初期値は指定可能、プレイヤーは10～50、敵は2～30の範囲でランダム）
int defensePower：キャラクターの防御力（初期値は指定可能、プレイヤーは10～50、敵は2～30の範囲でランダム）
コンストラクタ
キャラクターの名前、体力、攻撃力、防御力を指定して初期化します。
デストラクタ
キャラクターが破棄される際に「[名前]がゲームから削除されました。」というメッセージを出力します。
メンバ関数
void attack(Character& target)
この関数は、他のキャラクターに攻撃を行います。
ダメージは次の式で計算します：
ダメージ = max(1, attackPower - target.defensePower)
※ ダメージは最低でも1与えます。
攻撃後、「[名前]が[ターゲットの名前]を攻撃し、[ダメージ]ダメージを与えました。」と出力します。
ターゲットのhealthからダメージを減算します。
ターゲットのhealthが0以下になった場合、「[ターゲットの名前]が倒されました。」と出力します。
※ライブラリの説明
このプログラムでは、以下の標準ライブラリを使用します。
それぞれの目的を理解しながら実装してください。

1. <cstdlib>
C++標準ライブラリで、以下の関数を提供します：

rand(): 乱数を生成します。
srand(): 乱数生成のシードを設定します。これを使って乱数のパターンを変更します。
2. <ctime>
時間に関する関数を提供します：

time(): 現在の時刻をエポック時間（1970年1月1日からの経過秒数）として取得します。srand(time(0))で現在時刻を乱数のシードに設定することで、毎回異なる乱数を生成できます。
3. <algorithm>
C++標準ライブラリで、便利なアルゴリズム関数を提供します：

std::max(a, b): 2つの値のうち、大きい方を返します。
このプログラムでは、最低ダメージを1に制限するために使用します。
ゲームの内容：
プレイヤーキャラクターを1体、敵キャラクターを2体作成してください。
プレイヤーの体力はランダムで25～200、防御力と攻撃力はランダムで10～50とします。
敵キャラクターの体力はランダムで5～30、防御力と攻撃力はランダムで2～30とします。
プレイヤーが順番に敵を攻撃します。
2体の敵の体力が0になるか、プレイヤーの体力が0になるまで戦います
*/

#include<iostream>
#include<ctime>
#include<cstdlib>
#include<algorithm>
#include<string>
using namespace std;

class Character
{
    string name;
    int health;
    int attackPower;
    int defensePower;

public:
    //コンストラクタ
    Character(string Name, int Hp, int Atk, int Def)
    {
        name = Name;
        health = Hp;
        attackPower = Atk;
        defensePower = Def;
        cout << "名前：" << name << "(Hp：" << health << " Atk: " << attackPower << " Def : " << defensePower << ")" << endl;
    }
    //デストラクタ
    ~Character() {

    }

    //攻撃
    void attack(Character& target) 
    {
        int damege = max(1, attackPower-target.defensePower);

        target.health - damege;

        if (target.health <= 0)
        {
            target.health == 0;
            cout << target.name << "倒されました。" << endl;
        }

    }
    //生存確認フラグ
    bool isAlive()
    {
        return health > 0;
    }

    //キャラクター情報を表示
    void displayStatus()
    {
        cout << "名前：" << name << endl;
        cout << "HP:" << health << endl;
        cout << "ATK:" << attackPower << endl;
        cout << "DEF:" << defensePower << endl;
    }

 
};

//ランダムな数値作成
int getRandom(int min, int max)
{
    return rand() % (max - min + 1) + min;
}

int main(void)
{
    //乱数の初期化
    srand(time(0));

    const int PLAYER_HP_MAX = 200;
    const int PLAYER_HP_MIN = 25;
    const int ENEMY_HP_MAX = 30;
    const int ENEMY_HP_MIN = 5;
    const int PLAYER_ATKandDEF_MAX = 50;
    const int PLAYER_ATKandDEF_MIN = 10;
    const int ENEMY_ATKandDEF_MAX = 2;
    const int ENEMY_ATKandDEF_MIN = 30;
    
    string userName;
    cout << "名前を入力してください。";
    cin >> userName;

    Character Player(userName, getRandom(PLAYER_HP_MIN, PLAYER_HP_MAX), getRandom(PLAYER_ATKandDEF_MIN, PLAYER_ATKandDEF_MAX),getRandom(PLAYER_ATKandDEF_MIN,PLAYER_ATKandDEF_MAX));
    Character Enemy1("敵1", getRandom(ENEMY_HP_MIN,ENEMY_HP_MAX),getRandom(ENEMY_ATKandDEF_MIN,ENEMY_ATKandDEF_MAX),getRandom(ENEMY_ATKandDEF_MIN,ENEMY_ATKandDEF_MAX));
    Character Enemy2("敵2", getRandom(ENEMY_HP_MIN, ENEMY_HP_MAX), getRandom(ENEMY_ATKandDEF_MIN, ENEMY_ATKandDEF_MAX), getRandom(ENEMY_ATKandDEF_MIN, ENEMY_ATKandDEF_MAX));

    //ゲームループ
    while (Player.isAlive() && (Enemy1.isAlive() || Enemy2.isAlive()))
    {
        cout << "======== PLAYER TURE =========" << endl;

        if (Enemy1.isAlive())
        {
            Player.attack(Enemy1);
        }
        if (Enemy2.isAlive() && Enemy1.isAlive() == false)
        {
            Player.attack(Enemy2);
        }

        cout << "======== ENEMY TURE =========" << endl;

        if (Enemy1.isAlive())
        {
            Enemy1.attack(Player);
        }
        if (Enemy2.isAlive())
        {
            Enemy2.attack(Player);
        }

        //ステータス
        Player.displayStatus();
        Enemy1.displayStatus();
        Enemy2.displayStatus();

    }

    if (Player.isAlive())
    {
        cout << "PLAYER WINNER" << endl;
    }
    else
    {
        cout << "ENEMY WINNER" << endl;
    }

    return 0;
}