#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#pragma warning(disable:4996)
/*
PK戦
プレイヤーとCPUで交互にキッカーとキーパーの役目を行い、5回行いましょう。
蹴る方向は、0:正面　1:左下　2:右下　3：左上　4：右上となります。
同じであれば止められて得点にはなりません。異なれば得点となります。
方向が同じであれば（右であれば、右下か右上）、25％の確率でキーパーに止められる。
3点先に先取した方が勝ちとなります。
同点であれば、サドンデス（延長戦）となり、どちらかが多く得点を取った方が勝ちとします。
最終的に、どちらが勝ったかを表示させましょう。
inputCheck関数を作成し、入力をチェックしましょう。
game関数でゲームの流れを作ります。
keeper関数で止められるかどうかを判定させましょう。
*/
//関数プロトタイプ宣言
int inputCheck(int min, int max);
int keeper();
int judge(int kick, int keper);
void game(int min, int max, int score);

int main(void)
{
    //定数
    const int MIN = 0;
    const int MAX = 5;
    const int SCORE = 3;

    //乱数の初期化
    srand((unsigned int)time(NULL));
    //インフォメーション
    printf("コパアメリカ決勝！アルゼンチンvsウルグアイ\n120分の激闘でも決着がつかず、ＰＫ戦に突入しました。\n");

    //ゲーム関数呼び出し
    game(MIN, MAX, SCORE);


    return 0;
}


//入力チェック関数
int inputCheck(int min, int max)
{
    int num;

    while (true)
    {
        scanf("%d", &num);
        if (min > num || max < num)
        {
            printf("入力に誤りがあります。再度入力してください。\n");
        }
        else
        {
            break;
        }
    }

    return num;
}

//keeper関数
//キーパーとの対決の判定、同じ方向だけど25％の確率でゴールする
int keeper()
{
    int score, judg;
    //キーパーの判定

    //25％の確率を生成
    judg = rand() % 4;
    //0になる確率が25％だから
    if (judg == 0)
    {
        printf("キーパー反応したが届かず！Goaaaaaaaaaaaaaaaaaaaaall\n");
        score = 1;

    }
    else
    {
        printf("キーパーファインセーブ！！\n止めたぁ～！！\n");
        score = 0;

    }
    //スコアを戻り値として戻す
    return score;
}
//PKの判定関数
//入力した変数とランダムに生成した変数を引数として代入
//PKで交代した時は、キッカーとキーパー部分入れ替えてあげる
int judge(int kick, int keper)
{
    //スコア変数
    int scoer;
    //同じならキーパーが止める
    if (kick == keper)
    {
        printf("キーパー止めた～！！\n");
        scoer = 0;
    }
    //偶数か奇数でkeeper関数を呼び出し判定
    else if (kick % 2 == 0 && keper % 2 == 0 || kick % 2 != 0 && keper % 2 != 0 || kick != 0 && keeper != 0)
    {
        //スコアに代入
        scoer = keeper();
    }
    //それ以外では得点になる
    else
    {
        printf("決まった！！Goaaaaaaaaaaaaaaaaaaaaall\n");
        scoer = 1;
    }
    //スコア変数を戻り値として返す
    return scoer;
}
//Game関数
void game(int min, int max, int score)
{
    //各種変数を生成
    int ply, emy, plyScore = 0, emyScore = 0, cnt = 0;
    //ゲームスタート
    while (plyScore != 3 && emyScore != 3 || plyScore == emyScore)
    {
        //回数をカウント
        cnt++;
        //ラウンド数を表示
        printf("%d：ROUND", cnt);
        printf("キッカーでどこへ蹴るかを選択してください。0:正面　1:左下　2:右下　3：左上　4：右上\n");
        //入力チェック
        ply = inputCheck(min, max - 1);
        //CPUの変数をランダムで生成
        emy = rand() % max;
        //判定関数へプレイヤーが入力したものと、CPUが生成したもの引数として代入
        //戻り値をプレイヤースコアとして追加
        plyScore += judge(ply, emy);

        //同様の内容をキーパーとキッカーを交代して行う
        printf("キーパーでどこへ飛ぶかを選択してください。0:正面　1:左下　2:右下　3：左上　4：右上\n");
        ply = inputCheck(min, max - 1);
        emy = rand() % max;
        emyScore += judge(emy, ply);

        printf("%d vs %d\n", plyScore, emyScore);
    }

    //最後に判定を記載して終了
    if (plyScore > emyScore)
    {
        printf("ついにやりました！ウルグアイ優勝です！\n悲願の16回目！！コパアメリカ最多優勝国です！\n");
    }
    else
    {
        printf("神の子率いる！アルゼンチン優勝です！\n16回目コパアメリカ最多優勝国です！\n");
    }

}