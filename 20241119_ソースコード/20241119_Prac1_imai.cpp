/*
以下の要件に基づいて、名前空間を使って計算ライブラリを実装してください。
名前空間 MathFunctions を作成し、次の関数を実装してください。
add(int a, int b) : 2つの整数を足す関数。
subtract(int a, int b) : 2つの整数を引く関数。
multiply(int a, int b) : 2つの整数を掛ける関数。
divide(int a, int b) : 2つの整数を割る関数（割り算の際にゼロ除算を避けるように処理してください）。
メイン関数で、これらの関数を呼び出し、結果を表示してください。
*/
#include <iostream>

namespace MathFunctions
{
    //足し算
    int add(int a,int b) 
    {
        return a + b;

    }
    //引き算
    int subtract(int a, int b)
    {
        return a - b;
    }
    //掛け算
    int multiply(int a, int b)
    {
        return a * b;
    }
    //割り算
    double divide(int a, int b)
    {
        if (b == 0) 
        {
            std::cerr << "Error:ゼロ除算です" << std::endl;
            return 0.0;
        }
        return static_cast<double>(a) / b;

    }
}

int main(void)
{
    using namespace MathFunctions;
    int num1, num2;
    std::cout <<  "数字を2つ入力してください。" << std::endl;
    std::cout << "1つ目" << std::endl;
    std::cin >> num1;
    std::cout << "2つ目" << std::endl;
    std::cin >> num2;

    //各関数を呼び出し
    std::cout << "足し算:"  << add(num1, num2) << std::endl;
    std::cout << "引き算:" << subtract(num1, num2) << std::endl;
    std::cout << "掛け算:" <<multiply(num1, num2) << std::endl;
    std::cout << "割り算:" <<divide(num1, num2) << std::endl;

    return 0;
}