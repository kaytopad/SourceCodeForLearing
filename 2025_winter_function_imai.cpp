#include "2025_winter_header_imai.h"

// 3～35のカードを順番に山札へセットする
void initialize_deck(int deck[])
{
    int i;
    for (i = 0; i < TOTAL_CARDS; i++) 
    {
        deck[i] = i + MIN_CARD_VALUE;
    }
}
// フィッシャー・イェーツのアルゴリズムによるシャッフル
void shuffle_deck(int deck[])
{
    int i,j;
    int temp;
    srand((unsigned int)time(NULL));
    for ( i = TOTAL_CARDS -1 ; i > 0; i--)
    {
        j = rand() % (i+1);
        temp = deck[i];
        deck[i] = deck[j];
        deck[j] = temp;
    }


}
// 最終スコアの計算
int calculate_score(int player_cards[], int chips)
{
    int card_score = 0;
    int in_sequence = 0;
    int i, j;

    for ( i = 0; i < TOTAL_CARDS; i++)
    {
        if (player_cards[i])
        {
            if (!in_sequence)
            {
                card_score += (i + MIN_CARD_VALUE);
                in_sequence = 1;
            }

        }
        else
        {
            in_sequence = 0;
        }
    }

    return card_score - chips;

}
// 現在の状況をコンソールに表示
void display_status(int p_id, int chips[], int current_card, int chips_on_table)
{
    printf("\n--- [Player %d の手番] ---\n", p_id + 1);
    printf("公開カード: [%2d] | 場のチップ: %d枚\n", current_card, chips_on_table);
    printf("所持チップ: P1:%d枚, P2:%d枚\n", chips[0], chips[1]);
}