/*
簡単なゲームのスコア管理システムを名前空間を使って実装してください。


ゲームには2つのプレイヤーが登場します。
各プレイヤーはスコアと名前を持っています。
プレイヤーはポイントを獲得したり、失ったりすることができます。
また、プレイヤーの名前とスコアを表示する関数を作成してください。

名前空間Playerにプレイヤーのスコアを管理する構造体とその操作関数を実装してください。
ゲームの進行管理を行うGame名前空間を作成し、その中でゲームの進行を管理する関数startGameを実装してください。
要件
Player名前空間には以下の内容を実装してください：

構造体 PlayerData
メンバ変数：
name (プレイヤーの名前)
score (プレイヤーのスコア)
操作関数
addScore(PlayerData& player, int points)：プレイヤーのスコアにポイントを加算する。
subtractScore(PlayerData& player, int points)：プレイヤーのスコアからポイントを減算する。
printPlayer(const PlayerData& player)：プレイヤーの名前とスコアを表示する。
Game名前空間には以下を実装してください：
関数 startGame
ゲーム開始時に2人のプレイヤーを作成し、スコア操作とスコアの表示を行う。
実装例：

プレイヤー1の名前は "Alice"、プレイヤー2の名前は "Bob" としてください。
ゲーム内で、各プレイヤーにポイントを加算・減算し、結果を出力する。
*/
#include<iostream>
#include<random>
namespace Player
{
	struct PlayerData
	{
		std::string name;
		int score;
	};

	//プレイヤーのスコアにポイントを加算する。
	void addScore(PlayerData& player, int points)
	{
		player.score += points;
	}
	//プレイヤーのスコアからポイントを減算する。
	void subtractScore(PlayerData& player, int points)
	{
		player.score -= points;
	}
	//プレイヤーの名前とスコアを表示する。
	void printPlayer(const PlayerData& player)
	{
		std::cout << "Player:" << player.name << std::endl;
		std::cout << "Score:" << player.score << std::endl;
	}

}

namespace Game
{
	using namespace Player;
	//ランダム生成
	int random(int min, int max)
	{
		//乱数の種
		std::random_device rd;
		//19937エンジンを用いてランダムな数字を生成
		std::mt19937 gen(rd());
		//uniform_int_distributionを使って指定した範囲の整数を生成
		std::uniform_int_distribution<> dis(min, max);

		return dis(gen);
	}

	void startGame()
	{
		//プレイヤーの初期化
		Player::PlayerData ply1;
		Player::PlayerData ply2;

		//プレイヤーの入力
		std::cout << "PLAYER1の名前を入力してください。" << std::endl;
		std::cin >> ply1.name;
		std::cout << "PLAYER2の名前を入力してください。" << std::endl;
		std::cin >> ply2.name;
		//スコア生成
		ply1.score = random(10, 100);
		ply2.score = random(10, 100);

		//プレイヤーを表示
		printPlayer(ply1);
		printPlayer(ply2);

		//ゲームスタート
		while (ply1.score >= 0 && ply2.score >= 0)
		{
			std::cout << ply1.name << "の攻撃" << std::endl;
			int play1AtkScoer = random(-10, 50);
			std::cout << ply1.name << "の攻撃は" << play1AtkScoer << "点" << std::endl;
			addScore(ply1, play1AtkScoer);
			subtractScore(ply2, play1AtkScoer);
			std::cout << ply2.name << "の攻撃" << std::endl;
			int play2AtkScoer = random(-10, 50);
			std::cout << ply2.name << "の攻撃は" << play2AtkScoer << "点" << std::endl;
			addScore(ply2, play2AtkScoer);
			subtractScore(ply1, play2AtkScoer);

			printPlayer(ply1);
			printPlayer(ply2);

		}
	}
}

int main()
{
	Game::startGame();
	return 0;

}