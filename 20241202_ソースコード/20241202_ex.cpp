#include<iostream>
#include<string>
using namespace std;

class  Player
{
//クラス内部でしか取り扱い
private:
    string name;
    int score;
public:
    //コンストラクタ
    Player() { name = "unkown"; score = 0; }
    //ゲッター
    string getName() const { return name; }
    int getScore() const { return score; }

    //セッター
    void setName(const std::string& newName)
    {
        if (!newName.empty())
        {
            name = newName;
        }
        else {
            cout << "Error：名前が空です。" << endl;
        }
    }

    void setScore(int newScore) 
    {
        if (newScore >= 0)
        {
            score = newScore;
        }
        else
        {
            cout << "Error：不正な数字が入力されました" << endl;
        }
    }

};

//メイン

int main(void)
{
    Player player;
    //不正な値が入力されました
    player.setName("");
    player.setScore(-10);
    //正常な値
    player.setName("JOJO");
    player.setScore(50);

    //結果の表示
    cout << "名前：" << player.getName() << endl;
    cout << "スコア：" << player.getScore() << endl;



    return 0;
}