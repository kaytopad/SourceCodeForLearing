#include<iostream>
#include<string>
using namespace std;

/*Dog クラスのインスタンスを作成する。
Name で名前を設定する。
ShowProfile メソッドで名前を表示する。
メイン関数にてDogクラスをオブジェクト化してください。
*/
//Dogクラス
class Dog
{
private:
    //メンバー変数
    string name;
    //コンストラクタ
public:
    Dog(string Name)
    {
        name = Name;
    }
    //デストラクタ
    ~Dog(){}
    //メソッド

    void ShowProfile() {
        std::cout << "犬の名前は、" << name << "です。" << std::endl;
    }
};

int main(void)
{
    //犬の名前を入力
    std::cout << "犬の名前を入力してください。" << std::endl;
    string dog_Name;
    std::cin >> dog_Name;
    //表示
    //実体
    Dog dog(dog_Name);

    //dispalyメソッドを呼び出し
    dog.ShowProfile();
    dog.~Dog();
    return 0;

}