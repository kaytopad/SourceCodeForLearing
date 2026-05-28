#include<iostream>
#include<string>
using namespace std;
/*
以下の内容に沿ったプログラミングをコーティングしてください。
Dogクラス

プロパティ:
private std::string name: 犬の名前を保持します。
private int age: 犬の年齢を保持します。
メソッド:
public void SetName(std::string name): 名前を設定する。
public void SetAge(int age): 年齢を設定する。
public void ShowProfile() const: 名前と年齢を表示する。
カプセル化

すべてのプロパティはprivateで定義し、直接アクセスを禁止してください。
プロパティの値は、SetNameおよびSetAgeメソッドを通じて設定します。
メイン関数

Dogクラスのインスタンスを作成します。
SetNameメソッドを使用して名前を設定します。
SetAgeメソッドを使用して年齢を設定します。
ShowProfileメソッドを呼び出して、名前と年齢を表示します。
*/

class Dog 
{
private:
    string name;
    int age;
public:
    //名前の設定
    void SetName(std::string name) {
        if (!name.empty())
        {
            this->name = name;
        }
        else
        {
            cout << "名前が空です。" << endl;
        }
    }
    //年齢の設定
    void SetAge(int age) {
        if (age >= 0)
        {
            this->age = age;
        }
        else
        {
            cout << "不正な値が入力されました。" << endl;
            this->age = 0;
        }
    }
    //プロフィール表示
    void ShowProfile() const {
        cout << "名前：" << name << endl;
        cout << "年齢：" << age << endl;
    }

};

int main(void) {
    
    //インスタンス化
    Dog dog;
    string dogName;
    int dogAge;
    //犬の名前入力
    cout << "犬の名前を入力してください。" << endl;
    cin >> dogName;
    dog.SetName(dogName);
    //年齢を入力
    cout << "犬の年齢を入力してください。" << endl;
    cin >> dogAge;
    dog.SetAge(dogAge);
    //表示
    dog.ShowProfile();

    return 0;
}