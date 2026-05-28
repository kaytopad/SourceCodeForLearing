#include<iostream>
using namespace std;

/*
クラス設計
Calculatorクラスを作成する。
属性: 2つの数値 (num1, num2) を保持する。
メソッド:
setNumbers(double n1, double n2): 2つの数値をセットする。
add(): 2つの数値の和を返す。
subtract(): 2つの数値の差を返す。
multiply(): 2つの数値の積を返す。
divide(): 2つの数値の商を返す（ただし、ゼロ除算はエラーメッセージを表示）。
メイン関数
ユーザーが2つの数値を入力する。
どの演算（加算、減算、乗算、除算）を行うかを選択できる。
選択された演算を実行し、結果を表示する。
計算結果を表示した後、ユーザーが「計算を続ける」か「プログラムを終了する」かを選択できる。
ユーザーが終了を選択するまで、数値の入力と計算を繰り返す。
*/
//電卓クラス
class Calculator
{
    //メンバー
private :
    double number1;
    double number2;
    //メソッド
public:
    void setNumber(double num1,double num2) 
    {
        number1 = num1;
        number2 = num2;
    }
    //2つの数値の和
    double add() {
        return number1 + number2;
    }
    //2つの数値の差
    double subtract() {
        return number1 - number2;
    }
    //2つの数値の積
    double multiply()
    {
        return number1 * number2;
    }
    //2つの数値の商（ゼロ除算）
    double divide() {
        if (number2 == 0)
        {
            cout << "エラー：０では割れません。" << endl;
            return 0;
        }

        return number1 / number2;
    }
};

//メイン
int main(void)
{
    //電卓オブジェクト
    Calculator cal;
    //入力する変数
    double num1, num2;
    //選択肢
    int choice;
    //計算継続フラグ
    int continueFlag = 1;
    //電卓で計算開始
    while (continueFlag)
    {
        //数値の入力
        cout << "1つ目の数値を入力してください" << endl;
        cin >> num1;
        cout << "2つ目の数値を入力してください" << endl;
        cin >> num2;

        //数値を設定
        cal.setNumber(num1, num2);

        //演算を選択
        cout << "演算を選択してください" << endl;
        cout << "足し算：1\n引き算:2\n掛け算:3\n割り算:4" << endl;
        cout << "選択：";
        cin >> choice;

        cout << "結果:";

        //演算選択結果を出力
        switch (choice)
        {
        case 1:
            cout << cal.add() << endl;
            break;
        case 2:
            cout << cal.subtract() << endl;
            break;

        case 3:
            cout << cal.multiply() << endl;
            break;
        case 4:
            cout << cal.divide() << endl;
            break;
        default:
            cout << "\n演算の選択にありません。" << endl;
            break;
        }

        cout << "続けかすか？終了しますか？\n1:続ける、0:終了" << endl;
        cin >> continueFlag;

    }

    cout << "終了します。" << endl;
    return 0;


}
