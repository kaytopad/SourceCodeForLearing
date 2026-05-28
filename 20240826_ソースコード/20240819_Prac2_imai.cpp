/*
野球盤ゲームpart5
9回の表と裏で対戦をゲームを作成しましょう。
先攻プレイヤー（バッター）、後攻CPU（ピッチャー）とします。
持ち球は、0：ストレート　1：カーブ　2：スライダー　3：シンカーです。
CPUは上記の番号をランダムで選択します。
同じ数字であれば打たれたとして75％の確率でヒットになり、25％の確率でアウトとなります。
また、10％の確率でホームランが出てランナー分の得点が加算されます。
違う数字なら75％の確率でストライクとなり、25％確率でボールとなります。
ボールは4つで1ヒットです。
ストライクは3つで1アウトです。
アウトは3つで攻守の交代です。
ヒット、アウト、ホームランが出たらストライクとボールのカウントは0になります。
9回の裏が3アウトになったらゲームが終了です。
終了したら、点数を表示しどちらが勝ったのかを表示してください。
関数はfunctionファイルに記載しましょう。
*/
#include"20240819_header2_imai.h"

int main(void)
{
	//変数宣言
	int plyScore = 0;
	int emyScore = 0;
	bool team = true;

	//乱数の初期化
	srand((unsigned int)time(NULL));

	//ゲームスタート
	plyScore += playInning(team);

	//攻守交代＆アウトカウント初期化
	printf("攻守交代\nPLAYER:%d vs CPU:%d\n",plyScore,emyScore);
	team = false;
	emyScore += playInning(team);

	printf("GameSet!!\n");
	//判定
	if (plyScore > emyScore)
	{
		printf("PLAYER:%d vs CPU:%dでプレイヤーの勝利\n", plyScore, emyScore);
	}
	else if (plyScore == emyScore)
	{
		printf("PLAYER:%d vs CPU:%dで引き分け\n", plyScore, emyScore);
	}

	else
	{
		printf("PLAYER:%d vs CPU:%dでCPUの勝利\n", plyScore, emyScore);
	}
	

	return 0;
}