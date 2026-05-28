#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#pragma warning(disable:4996)
/*
性別、種族（人間、エルフ、ドワーフ、ホビット）を入力します。
※性別、種族は選択形式にしましょう
※種族の選択̪は0：人間 1：エルフ 2：ドワーフ 3:ホビット
※性別は、0：男　1：　女
体力、魔力、攻撃力、防御力、素早さはランダムで生成しましょう
※体力、魔力の範囲は（18～55）
※攻撃力、防御力、素早さの範囲は（5～30）

種族修正として、以下の内容に修正します。
人間：全ての数値に+2
エルフ：魔力・素早さ+8、体力・攻撃力・防御力-3
ドワーフ：攻撃力・防御力+8、魔力・素早さ-8
ホビット：体力・素早さ+8、防御力・魔力-4
※修正されて、数値が最低数値を下回った場合、最低数値に変更しましょう。
*/
typedef struct status
{
    char name[128]; //名前
    int gender;     //性別
    int race;       //種族
    int HP;         //体力
    int MP;         //魔力
    int ATK;        //攻撃力
    int DEF;        //防御力
    int AGL;        //素早さ

}status;


int main(void)
{
    //構造体を変数として定義
    status chara;
    //乱数の初期化
    srand((unsigned int)time(NULL));
    //名前の入力
    printf("キャラクターを生成しましょう。\nまずは、名前の入力です。\n");
    scanf("%s",&chara.name);
    //性別の選択
    printf("性別を選択してください。\n0：男性　1:女性");
    scanf("%d", &chara.gender);
    //能力生成
    printf("種族を選択してください。\n0：人間 1：エルフ 2：ドワーフ 3:ホビット");
    scanf("%d", &chara.race);
    //種族の選択
    chara.HP = (rand() % 39) + 18;
    chara.MP = (rand() % 39) + 18;
    chara.ATK = (rand() % 26) + 5;
    chara.DEF = (rand() % 26) + 5;
    chara.AGL = (rand() % 26) + 5;
    //種族別能力値修正＆最低数値修正
    switch (chara.race)
    {
        //人間
    case 0:
        chara.HP += 2;
        chara.MP += 2;
        chara.ATK += 2;
        chara.DEF += 2;
        chara.AGL += 2;
        break;
        //エルフ
    case 1:
        chara.HP -= 3;
        chara.MP += 8;
        chara.ATK -= 3;
        chara.DEF -= 3;
        chara.AGL += 8;
        break;
    //ドワーフ
    case 2:
        chara.HP += 8;
        chara.MP -= 8;
        chara.DEF += 8;
        chara.AGL -= 8;
        break;
        //ホビット
    case 3:
        chara.HP += 8;
        chara.MP -= 4;
        chara.DEF -= 4;
        chara.AGL += 8;
        break;

    }
    //修正
    if (chara.HP < 15)
    {
        chara.HP = 15;
    }
    else if (chara.MP < 15)
    {
        chara.MP = 15;
    }
    else if (chara.ATK < 5)
    {
        chara.ATK = 5;
    }
    else if (chara.DEF < 5)
    {
        chara.DEF = 5;
    }
    else if (chara.AGL < 5)
    {
        chara.AGL = 5;
    }

    //表示

    printf("キャラクターの完成です\n名前：%s\n",chara.name);

    switch (chara.gender)
    {
    case 0:
        printf("性別:男性\n");
        break;
    case 1:
        printf("性別:女性\n");
        break;
    }

    switch (chara.race)
    {
    case 0:
        printf("人間\n");
        break;
    case 1:
        printf("エルフ\n");
        break;
    case 2:
        printf("ドワーフ\n");
        break;
    case 3:
        printf("ホビット\n");
        break;
    }

    printf("体力:%d\n魔力:%d\n攻撃力:%d\n防御力:%d\n素早さ:%d", chara.HP, chara.MP, chara.ATK, chara.DEF, chara.AGL);
    return 0;
}