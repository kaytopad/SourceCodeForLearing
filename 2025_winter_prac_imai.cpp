#include"2025_winter_header_imai.h"

int main(void) {
    int deck[TOTAL_CARDS];
    int p_chips[PLAYER_NUM] = { START_CHIPS, START_CHIPS };
    int p_cards[PLAYER_NUM][TOTAL_CARDS] = { {0} };

    int chips_on_table = 0;
    int current_card_idx = 0;
    int turn = 0; // 0: 人間, 1: CPU

    initialize_deck(deck);
    shuffle_deck(deck);

    printf("=== Geschenkt vs CPU 開始 ===\n");

    while (current_card_idx < PLAYER_CARDS) {
        const int card = deck[current_card_idx];
        display_status(turn, p_chips, card, chips_on_table);

        int choice = 0;

        // --- 手番の処理 ---
        if (turn == 0) {
            // 人間の入力
            if (p_chips[turn] <= 0) {
                printf("チップがないため、強制的にカードを取ります。\n");
                choice = 1;
            }
            else {
                printf("1:カードを取る / 2:パス\n選択 > ");
                while (scanf("%d", &choice) != 1 || (choice != 1 && choice != 2)) {
                    printf("1 または 2 を入力してください > ");
                    while (getchar() != '\n');
                }
            }
        }
        else {
            // CPUの思考
            if (p_chips[turn] <= 0) {
                printf("CPUはチップがないため、カードを取りました。\n");
                choice = 1;
            }
            else {
                // 1か2をランダムに決定
                choice = (rand() % 2) + 1;
                printf("CPUの選択 > %s\n", (choice == 1) ? "取る" : "パス");
            }
        }

        // --- 行動の反映 ---
        if (choice == 1) {
            p_cards[turn][card - MIN_CARD_VALUE] = 1;
            p_chips[turn] += chips_on_table;
            chips_on_table = 0;
            current_card_idx++;
            // 取った人が次の親（turnはそのまま）
        }
        else {
            p_chips[turn]--;
            chips_on_table++;
            turn = (turn + 1) % PLAYER_NUM; // 交代
        }
    }

    printf("\n=== 最終結果発表 ===\n");
    for (int i = 0; i < PLAYER_NUM; i++) {
        int final_score = calculate_score(p_cards[i], p_chips[i]);
        printf("%s: %3d 点\n", (i == 0) ? "あなた(P1)" : "CPU(P2)", final_score);
    }

    if (calculate_score(p_cards[0], p_chips[0]) < calculate_score(p_cards[1], p_chips[1])) {
        printf("\nおめでとうございます！あなたの勝ちです。\n");
    }
    else if (calculate_score(p_cards[0], p_chips[0]) > calculate_score(p_cards[1], p_chips[1])) {
        printf("\n残念！CPUの勝ちです。\n");
    }
    else {
        printf("\n引き分けです。\n");
    }

    return 0;
}