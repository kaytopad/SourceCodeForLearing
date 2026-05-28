#include "20251215_header_imai.h"

void display_status(int depth, int oxygen, int points)
{
	printf("==================================\n");
    printf("  現在水深: %4dm / %dm\n", depth, MAX_DEPTH);
    printf("  残り酸素: %4dml\n", oxygen);
    printf("  現在スコア: %4d pt\n", points);
    printf("==================================\n");
}

int calculate_consumption(int distance, int points)
{
    int base = (distance / DIST_STEP) * OXYGEN_PER_UNIT;
    int penalty = distance * (points / PENALTY_DIVISOR);
    return base + penalty;
}

bool is_valid_move(int move)
{
    if (move < MIN_MOVE_DIST || move > MAX_MOVE_DIST || move % DIST_STEP != 0) {
        return false;
    }
    return true;
}

int perform_ascent(int depth, int oxygen, int points) {
    if (depth <= 0) return oxygen;

    int cost = calculate_consumption(depth, points);
    printf("\n>>> 海上へ浮上を開始します（距離: %dm）\n", depth);
    printf(">>> 消費される酸素予定量: %dml\n", cost);

    return oxygen - cost;
}


int checkInput(int min, int max)
{
    int input;
    while (true)
    {
        
        if (scanf("%d", &input) != 1)
        {
            printf("数値を入力してください。\n");
            while (getchar() != '\n');
            continue;

        }
        if (min > input || max < input)
        {
            printf("入力された値が違います。再度入力してください。\n");
        }
        else
        {
            break;
        }

    }

    return input;


}