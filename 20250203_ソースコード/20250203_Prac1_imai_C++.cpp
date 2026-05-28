/*
C++での記載
*/
#include <iostream>
#include<fstream>
#include<string>
#define FILENAME "../user_data_C++.txt"

int main(void)
{
    std::string name;
    int age = 0;
    //ユーザーから入力を取得
    std::cout << "名前を入力してください。" << std::endl;
    std::cin >> name;
    std::cout << "年齢を入力してください。" << std::endl;
    std::cin >> age;
    //ファイルに書き込み
    std::ofstream ofs(FILENAME);
    if (!ofs)
    {
        std::cout << "ファイルがありません" << std::endl;
        return 1;
    }

    ofs << name << "\n" << age << "\n";
    ofs.close();
    //ファイルから読み込み
    std::ifstream ifs(FILENAME);
    if (!ifs)
    {
        std::cout << "ファイルがありません" << std::endl;
        return 1;
    }

    ifs >> name >> age;
    ifs.close();

    //読み込んだファイルから出力
    std::cout << "\n名前:" << name << "\n年齢:" << age << std::endl;

    return 0;
}