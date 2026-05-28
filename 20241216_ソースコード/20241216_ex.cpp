#include<iostream>
#include <iostream>
using namespace std;

class Animal
{
    enum AnimalType
    {
        animal,
        Dog,
        Cat
    };
public:
    virtual void makeSound() const {  // 仮想関数
        cout << "動物の音" << endl;
    }

    void makeSound(AnimalType type) {
        if (type == AnimalType::Dog) {
            std::cout << "ワンワン" << std::endl;
        }
        else if (type == AnimalType::Cat) {
            std::cout << "ニャー" << std::endl;
        }
    }

};

class Dog :public Animal
{
public:

    void makeSound() const override {  // オーバーライド
        cout << "ワンワン" << endl;
    }
private:

};

