/*
1〜30までのランダムな数字を当てるゲームを作成します。以下のルールで進めてください。

ゲームルール
全5問を出題します。
プレイヤーはランダムに選ばれた1〜30の数字を当てます。
入力した数字が正解より小さければ「Small」、大きければ「Big」と表示します。
正解に至るまで、何度でも入力できます。
経験値は以下の計算式で付与されます：
経験値 = 100 - (試行回数 × 10)
ただし最低経験値は0とします。
経験値が閾値を超えるとレベルアップします。
レベルアップの閾値はレベルごとに10ずつ増加します。
例：レベル1→2は10、レベル2→3は20。
プレイヤークラス
以下の仕様でPlayerクラスを作成してください。

プロパティ
private int score: スコア（経験値）を保持する。
public int level: レベルを保持する。
メソッド
public void AddScore(int points): 引数で受け取ったポイントをスコアに加算する。
スコアが現在のレベルアップ閾値を超えた場合、レベルを1つ上げる。
private void LevelUp(): レベルアップ時の処理を行い、メッセージを表示する。
スコアはprivateとし、直接の外部アクセスは禁止する。
実行例
ランダムな数字が15の場合：
プレイヤー入力: 10 → "Small"
プレイヤー入力: 20 → "Big"
プレイヤー入力: 15 → "Correct! 回数: 3"
獲得経験値: 100 - (3 × 10) = 70
5問終了後、最終レベルを表示する。
*/

#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;

class  Player
{

private:
	int score;
	int level;
	void LevelUp()
	{
		level++;
		cout << "Levelが上がりました！ Lv：" << level << endl;
	}

public:
	Player() { score = 0; level = 1; };
	~Player() {};

	void AddScore(int points) {
		score += points;
		cout << "Score：" << score << endl;

		int threshold = level * 10;

		if (score >= threshold)
		{
			LevelUp();
		}
	}

	int GetLevel()
	{
		return level;
	}

};
	//ゲーム実行

	void Game(Player&player)
	{
		//乱数の初期化
		srand(time(0));
		//ラウンド回数
		const int TOTALROUND = 5;
		int round = 0;
		for ( round = 0; round < TOTALROUND; round++)
		{
			cout << "Round : " << round + 1 << endl;
			//問題
			int target = rand() % 30 + 1;
			int answer = 0;
			int times = 0;

			while (true)
			{
				cout << "１～30までの数字を当てましょう" << endl;
				cin >> answer;
				times++;
				if (answer == target)
				{
					cout << "BING！！" << times << "回目" << endl;
					break;
				}
				else if (answer > target)
				{
					cout << "BIG" << endl;
				}
				else
				{
					cout << "Small" << endl;
				}

			}

			int Point = max(0, 100 - times * 10);
			cout << "獲得ポイントは" << Point << "です" << endl;

			player.AddScore(Point);



		}

	}

int main(void)
{
	//インスタンス化
	Player player;

	Game(player);

	return 0;
}