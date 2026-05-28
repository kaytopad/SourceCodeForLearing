#include<iostream>
using namespace std;

//動物クラス（基底クラス）
class Animal {

public:
    void bark()
    {
        cout << "動物が鳴きます" << endl;
    }
};

//犬クラス（派生クラス）
class  dog:public Animal
{
public:
    void bark() {
        cout << "わんわん" << endl;
    }
};

int main() 
{
    dog mydog;

    mydog.bark();
    mydog.Animal::bark();

    return 0;


}