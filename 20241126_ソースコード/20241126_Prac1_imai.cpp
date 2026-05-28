/*
数学の計算を行うクラスを作成してください。
クラス名：MathHelper

基本的な数学計算をサポートするクラス。
メンバ変数

int a：最初の値
int b：2番目の値
コンストラクタ

MathHelper(int x, int y)
2つの整数を受け取り、それらをaとbに初期化する。

コンストラクタが呼び出されたときに「MathHelperオブジェクトが作成されました。」というメッセージを表示する。

デストラクタ

デストラクタが呼び出されたときに「MathHelperオブジェクトが削除されました。」というメッセージを表示する。
メンバ関数

int add()
aとbの合計を返す。
int multiply()
aとbの積を返す。
実行内容
MathHelperのオブジェクトを作成し、次の操作を行います：
5と3を入力として与える。
合計を計算して出力する。
積を計算して出力する。
プログラム終了時にデストラクタが自動的に呼ばれ、メッセージが表示される。
*/
#include<iostream>
using namespace std;

class MathHelper
{
	int a;
	int b;

public:
	//コンストラクタ＆デストラクタ
	MathHelper(int x, int y)
	{
		a = x;
		b = y;
		cout << "MathHelperオブジェクトが作成されました。" << endl;
	}
	~MathHelper() {
		cout << "MathHelperオブジェクトが削除されました。" << endl;
	}
	//メンバー関数
	int add()
	{
		return a + b;
	}

	int multiply()
	{
		return a * b;
	}

};

int main(void)
{
	MathHelper math(5, 3);

	cout << "5 + 3 = " << math.add() << endl;
	cout << "5 * 3 = " << math.multiply() << endl;
}