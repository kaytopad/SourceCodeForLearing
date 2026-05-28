#include <iostream>
#include<fstream>
#include<string>
int main(void)
{
    /*
    int number;
    //コンソール画面へ出力
    std::cout << "数字を入力してください。"<<std::endl;
    //コンソール画面から入力
    std::cin >> number;

    std::cout << "入力された数字は、" << number << std::endl;
    //文字列
    std::string name;
    std::cin >> name;

    std::cout << name << std::endl;
    */

    //ファイルの入出力
    std::ifstream inputFile("J1順位表.txt");
    std::ofstream outputFile("J1順位表_追加.txt");
    std::string line;
    while (std::getline(inputFile,line))
    {
        std::cout << line << std::endl;
        outputFile << line << std::endl;
    }

    outputFile << "6:東京V" << std::endl;

    inputFile.close();
    outputFile.close();
    return 0;
}