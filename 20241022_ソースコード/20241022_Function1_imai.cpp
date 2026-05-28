#include"20241022_header1_imai.h"
//キャラクターの追加
void addCharacter(Character* characters, int* count, int* capacity)
{
    //容量不足の場合再割り当てを行う
	if (*count >= *capacity)
	{
		*capacity *= 2;
		//新しい容量でメモリを確保
		Character *characters = new Character[*capacity];
	}

		printf("キャラクターの名前を入力してください。\n");
		scanf("%S", &(characters[*count].Name));
		printf("HPを入力してください。\n");
		scanf("%d",&characters[*count].Hp);
		printf("ATKを入力してください。\n");
		scanf("%d",&characters[*count].atk);
		printf("DEFを入力してください。\n");
		scanf("%d", &characters[*count].def);

	(*count)++;
}
//キャラクターの削除
void deletCharacter(Character* characters, int* count, int index)
{
	int i;
	for ( i = index; i < *count -1 ; i++)
	{
		characters[i] = characters[i + 1];
	}
	(*count)--;
}
//キャラクターの表示
void displayCharacter(Character* characters, int* count)
{
	if (*count == 0) {
		printf("キャラクターが存在しません。\n");
		return;
	}

	for (int i = 0; i < *count; i++)
	{
		printf("%d:\n名前：%S\nHP:%d,ATK:%d,DEF:%d", i + 1, characters[i].Name, characters[i].Hp,characters[i].atk,characters[i].def);
		printf("\n");
	}
}
