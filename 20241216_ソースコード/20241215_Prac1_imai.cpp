#include<iostream>
#include<vector>
#include<memory>
using namespace std;

/*
ある動物園には複数の動物がいます。動物は食べる行動を持っていますが、各動物が異なる食べ物を好みます。例えば、ライオンは肉を食べますが、ゾウは草を食べます。

次の要件に基づいて、動物園の動物を表すクラスとポリモフィズムを使用して食べる行動を実装してください。

Animal（動物）クラスを作成します。このクラスには Eat メソッドがあります。
Animalクラスを継承して、少なくとも2つの異なる動物（例: Lion（ライオン）、Elephant（ゾウ））クラスを作成します。それぞれの動物クラスには Eat メソッドがあり、適切な食べ物をコンソールに出力します。
ポリモフィズムを使用して、動物園で異なる動物が食べる様子をシミュレートします。各動物の Eat メソッドを呼び出すことで、適切な食べ物が表示されるようにしてください。
*/

//アニマルクラス（基底クラス）
class Animal {

public:
    virtual void Eat() const
    {
        cout << "動物は何かを食べます" << endl;

    }
    //デストラクタ
    virtual ~Animal(){}

};

//派生クラス
class  Lion :public Animal
{
public:
    void Eat() const override {
        cout << "ライオンは肉を食べます" << endl;
    }

};

class  Elephant :public Animal
{
public:
    void Eat() const override {
        cout << "象は草を食べます" << endl;
    }

};

int main() 
{
    vector < shared_ptr<Animal>>zoo;

    //動物を追加

    zoo.push_back(make_shared<Lion>());
    zoo.push_back(make_shared<Elephant>());

    for (const auto&animal:zoo)
    {
        //各動物のEatメソッドを呼び出す
        animal->Eat();
    }

    return 0;
}
