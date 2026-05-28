#include<iostream>
using namespace std;

class number
{
    int num;

public:
    //デフォルトコンストラクタ
    number() {
        num = 0;
        cout << "デフォルトコンストラクタが呼び出されました。" << endl;

    }

    //引数付きコンストラクタ
    number(int Num) 
    {
        num = Num;
        cout << "コンストラクタが呼び出されました。" << endl;
    }
    //デストラクタ
    ~number() {
        cout << "デストラクタが呼び出されました。" << endl;
    }
    //メンバー関数
    void display()
    {
        cout << "値は：" << num << "です" << endl;
    }

};

int main(void)
{
    //オブジェクト（インスタンス化）
    //デフォルトコンストラクタ
    number Number;
    //コンストラクタ
    number Number1(10);

    Number.display();
    Number1.display();

    return 0;

}