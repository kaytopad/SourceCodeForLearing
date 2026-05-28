#include<iostream>
#include<string>
using namespace std;

//クラスの定義
class Person        //クラス名
{
private:    //クラス内部でのアクセス可能（デフォルト）
    //メンバーの定義
    string name;
    int age;
//protected クラス内部と派生クラス（継承）からアクセス可能
public:     //アクセス指定子　どこからでもアクセス可能

    //コンストラクタ(オブジェクトが初期化された時に呼び出される)
    Person(string Name, int Age)
    {
        name = Name;
        age = Age;
    }
    //デストラクタ
    ~Person();
    //メソッド
    void display()
    {
        std::cout << "私の名前は、" << name << "です" << std::endl;
        std::cout << "年齢は、" << age << "です" << std::endl;
    }
};

//メイン関数
int main(void)
{
    string user_name;
    int user_age;
    std::cout << "名前を入力してください。" << std::endl;
    cin >> user_name;
    std::cout << "年齢を入力してください。" << std::endl;
    cin >> user_age;

    //オブジェクトを生成
    Person person(user_name, user_age);
    person.display();

    return 0;
}