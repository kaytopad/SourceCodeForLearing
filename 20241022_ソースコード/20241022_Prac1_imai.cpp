#include"20241022_header1_imai.h"
/*
ゲームキャラクターには「HP（体力）」「攻撃力」「防御力」のステータスがあります。
これらのステータスをキャラクターごとに動的に管理するプログラムを作成してください。
要件
キャラクターのステータスを格納するための構造体 Character を定義してください。
名前（最大20文字）
HP（整数）
攻撃力（整数）
防御力（整数）
キャラクターのリストを動的に管理するために、Newを使用してください。ただし、ポインタのポインタは使用しないでください。
キャラクターを追加する機能を実装してください。
指定されたインデックスのキャラクターを削除する機能を実装してください。
削除後はリストを詰めて連続的にしてください。
現在の全てのキャラクターのステータスを表示する機能を実装してください。
プログラム終了時には動的に確保したメモリを解放してください。
*/

int main(void)
{
    //変数宣言
    int capactiy = 2;
    int count = 0;
    int Choice;
    int index;
    Character* character = new Character[capactiy];
    
    do
    {
        printf("1:キャラクター追加　2：キャラクター削除　3：キャラクターの表示　0:終了\n以下の内容から選択してください。");
        scanf("%d", &Choice);

        switch (Choice)
        {

        case 1:
            addCharacter(character,&count,&capactiy);
            break;
        case 2:
            printf("何番目のキャラクターを消しますか？");
            scanf("%d", &index);
            deletCharacter(character, &count, index);
            break;
        case 3:
            displayCharacter(character, &count);
            break;
        case 0:
            printf("プログラムを終了させます。\n");
            break;
        default:
            printf("無効な値が入力されました。再度選択してください。\n");
            break;
        }
    } while (Choice != 0);
    //動的に確保したメモリの解放
    delete[] character;

    return 0;
}