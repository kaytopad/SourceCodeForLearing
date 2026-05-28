#include<iostream>

//名前空間宣言　名前空間の名前
namespace MyNamespace 
{
    int x = 0;

    void display() {
        std::cout << "名前空間のメソッドです" << std::endl;
    }

}

namespace MyNameSpace
{
    int x = 20;

    void display2() {
        std::cout << "名前空間part2のメソッドです" << std::endl;
    }
}

using namespace MyNameSpace;

int main(void)
{

    x = 10;
    std::cout << MyNamespace::x << std::endl;
    std::cout << x << std::endl;
    

    display2();

    return 0;
}