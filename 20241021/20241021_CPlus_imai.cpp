#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

int main(void)
{
    std::string linebuf;                       // 1行読み込みバッファ
    std::string data;                          // カンマ区切りで切り出したデータ格納用
    std::string filePath = "mapTest.csv";  // CSVファイル名

    std::vector<std::vector<int>> map;         // マップの2次元配列

    //ファイルオープン
    std::ifstream csvFile(filePath);
    if (csvFile.fail())
    {
        std::cout << "ファイルのオープンに失敗" << std::endl;
        return 0;
    }

    // ファイルからCSV読み込み
    int line = 0;
    while (getline(csvFile, linebuf))
    {
        // map配列の行を追加
        map.emplace_back();
        //カンマ区切りで読みやすいように istringstream型に変換
        std::istringstream iStream(linebuf);

        // カンマ区切り単位でdataに文字列格納
        while (getline(iStream, data, ','))
        {
            // 文字列データを数値に変換して、map[line][]の末尾に追加
            map[line].emplace_back(stoi(data));
        }
        line++;
    }

    // マップにデータが格納されたか表示
    for (int iy = 0; iy < map.size(); iy++)
    {
        for (int ix = 0; ix < map[iy].size(); ix++)
        {
            std::cout << map[iy][ix] << ",";
        }
        std::cout << std::endl;
    }

    return 0;
    //ファイルクローズ処理は不要。デストラクタで処理されます。
}