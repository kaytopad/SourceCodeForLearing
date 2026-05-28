#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#pragma warning(disable:4996)

/*

数字を当てるゲームを作成しましょう。
1～50のランダムな数字を当てましょう。
回答回数は、5回までです。
入力に際して、1～50まで以外の数字が入力された時にエラーを表示し、再入力する関数を作成しましょう。
ヒントとして、入力した数字が大きければ「Big」、小さいければ「Small」を表示しましょう。
正解した場合は、「BING」を表示し、ゲームを終了させましょう。
inputCheck関数で入力チェックを行ってください。
ゲーム部分をgame関数を作成しましょう。
*/
//inputCheck関数
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

//Game関数
void game(int max,int min,int round,int ans)
{
    //変数宣言
    int i,ply;
    printf("＝＝＝＝＝＝＝＝＝＝＝＝ゲームスタート＝＝＝＝＝＝＝＝＝＝＝＝\n");
    //数字当ゲーム
    for (i = 0;  i < round; i++)
    {

        printf("%d回目です。数字を入力してください。\n",i +1);
        ply = inputCheck(min,max);
        //同じなら
        if (ply == ans)
        {
            printf("BING\n");
            break;
        }
        //大きかったら
        else if (ply > ans)
        {
            printf("Big\n");
        }
        //小さいかったら
        else
        {
            printf("Small\n");
        }
       
    }
    //答えの表示
    printf("Answer:%d\n",ans);

    if (i < round)
    {
        printf("Player's WINNER\n");
    }
    else
    {
        printf("CPU's WINNER\n");
    }

}

int main(void)
{
    //変数宣言
    int ans;            //解答の数字
    //定数
    const int MIN = 1;
    const int MAX = 50;
    const int ROUND = 5;
    //乱数の初期化
    srand((unsigned int)time(NULL));
    //ゲームインフォーメーション
    printf("数字を当てるゲームを作成しましょう。1～50のランダムな数字を当てましょう\n");
    ans = rand() % MAX + MIN;
    //ゲーム関数の呼びだし
    game(MAX,MIN,ROUND,ans);
    //結果
    return 0;
}
