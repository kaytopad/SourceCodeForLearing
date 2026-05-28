#include"20251110_header2_imai.h"

//定数
const int INDEX = 6;
const int NUMBER = 100;

int main(void)
{

	int numbers[INDEX];
	int swap_count = 0;
	int inputIndex;

	int i;
	int tmp;
	srand((unsigned int)time(NULL));

	for ( i = 0; i < INDEX; i++)
	{
		numbers[i] = rand() % NUMBER;
	}

	while (true)
	{

		printf("現在の配列：");
		displayNumbers(numbers,INDEX);
		printf("インデックス:");
		for ( i = 0; i < INDEX; i++)
		{
			printf("%d,", i);
		}
		printf("\n");

		//完了チェック
		if (isSorted(numbers,INDEX))
		{
			printf("Congratulations！！\n");
			printf("最終的な合計入れ替え回数: %d 回\n",swap_count );
			break;
		}

		printf("どこを入れ替えますか？0～4\n");

		inputIndex = checkInput(0,4);

		tmp = numbers[inputIndex];
		numbers[inputIndex] = numbers[inputIndex + 1];
		numbers[inputIndex + 1] = tmp;

		swap_count++;
		
	}

	return 0;
}