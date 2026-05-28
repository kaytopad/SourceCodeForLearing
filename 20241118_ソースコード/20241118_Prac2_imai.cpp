
/*
ファイルからデータを読み込み、加工して出力するプログラム
問題文
あなたは、学生のテストスコアを管理するプログラムを作成する必要があります。以下の仕様に従ってプログラムを完成させてください。

入力
ファイル scores.txt には、以下のような形式で学生の名前とスコアが記録されています（1行に1人分のデータが記載されています）。

例：
Alice 85
Bob 92
Charlie 78
Diana 88
スコアは整数（0以上100以下）で与えられます。
処理
プログラムは以下の操作を行います。

scores.txt からデータを読み込む。
各学生のスコアが合格点（70点以上）か不合格点（70点未満）かを判定する。
判定結果を別のファイル results.txt に以下の形式で書き込む：
作成ファイル
例：
Alice: Passed
Bob: Passed
Charlie: Failed
Diana: Passed
出力

プログラムの実行後、ファイル results.txt に適切な判定結果が記録されていること。

条件

ファイル読み込みには std::ifstream を、ファイル書き込みには std::ofstream を使用してください
*/
#include <iostream>
#include <fstream>
#include <string>

int main() {
    // 入力ファイルを開く
    std::ifstream inputFile("Score.txt");
    if (!inputFile.is_open()) {
        std::cerr << "Error: Could not open input file 'scores.txt'." << std::endl;
        return 1;
    }

    // 出力ファイルを開く
    std::ofstream outputFile("results.txt");
    if (!outputFile.is_open()) {
        std::cerr << "Error: Could not open output file 'results.txt'." << std::endl;
        return 1;
    }

    std::string name;
    int score = 0;


    // scores.txt からデータを読み込んで処理
    while (inputFile>> name >> score) {

        std::cout << name << ":" << score << std::endl;
        // 判定結果を results.txt に書き込む
        std::string result = (score >= 70) ? "Passed" : "Failed";
        outputFile << name << ":"<< result << std::endl;
    }
    std::cout << "Results have been written to 'results.txt'." << std::endl;

    // ファイルを閉じる
    inputFile.close();
    outputFile.close();

    return 0;
}
