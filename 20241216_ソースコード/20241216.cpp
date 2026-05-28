#include <iostream>
using namespace std;

class Animal {
public:
    virtual void makeSound() const {  // 仮想関数
        cout << "動物の音" << endl;
    }
    virtual ~Animal() = default; // 仮想デストラクタ
};

class Dog : public Animal {
public:
    void makeSound() const override {  // オーバーライド
        cout << "ワンワン" << endl;
    }
};

class Cat : public Animal {
public:
    void makeSound() const override {
        cout << "ニャー" << endl;
    }
};

int main() {
    Animal* animal1 = new Dog();
    Animal* animal2 = new Cat();

    animal1->makeSound();  // ワンワン
    animal2->makeSound();  // ニャー

    delete animal1;
    delete animal2;
    return 0;
}
