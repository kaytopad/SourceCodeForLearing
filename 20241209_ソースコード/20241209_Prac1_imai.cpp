#include<iostream>
using namespace std;
/*
Animal 基底クラスを作成します。
このクラスには以下のメンバーを持たせてください。
string Name プロパティ (名前)
void Speak() メソッド (動物が話す)
Animal クラスを基底クラスとして Dog クラスと Cat クラスを作成します。
Dog クラスには void Fetch() メソッド (犬が物を取ってくる)
Cat クラスには void Scratch() メソッド (猫が引っかく)
*/
class  Animal
{
public:
    string Name;
    void Speak() {
        cout << "動物が鳴きます" << endl;
    }

};

class  Dog: public Animal
{
public:
    void Fetch() {
        cout << "犬が物を取ってきます。" << endl;
    }

};

class  Cat:public Animal
{
public:
    void Scratch() {
        cout << "猫が引っかく" << endl;
    }
};

int main() 
{
    Dog dog;
    Cat cat;

    cout << "犬の名前を入力してください" << endl;
    cin >> dog.Name;
    cout << "猫の名前を入力してください" << endl;
    cin >> cat.Name;

    cout << dog.Name << "は";
    dog.Fetch();
    cout << cat.Name << "は";
    cat.Scratch();
    
}