
/*手順
あなたはダイバーとなり、海底に眠る財宝を集めるゲームを作成します。
水深1000mまで潜ることができますが、酸素ボンベの量には限りがあります。
酸素がなくなる前に海上へ戻り、できるだけ多くのポイントを獲得しましょう。
ゲームのルール
潜れる最大水深は 1000m です。
酸素ボンベの初期量は 3200ml です。
1回で潜れる深度は 10〜100m までで、10m刻みとします。
潜った距離 10mにつき酸素を1ml消費します。
潜った後、財宝を探すかどうかを選択できます。
財宝を探した場合、
潜った深度 × 2 のポイントを獲得します。

例：50m → 100ポイント
財宝を持っている状態でさらに潜ると、酸素の減少量が増えます。
酸素減少量 ＝ 進んだ距離 ×（現在のポイント ÷ 10）
各深度で何度でも「潜る」「財宝を探す」を繰り返せます。
浮上を選択した場合、それ以上潜ることはできません。
酸素が 0以下 になった場合、ゲームオーバーとなり、ポイントは0になります。
無事に海上へ戻れた場合、獲得したポイントが最終スコアになります。*/

#include"20251215_header_imai.h"

int main(void)
{
    int current_depth = 0;
    int oxygen = INITIAL_OXYGEN;
    int total_points = 0;
    int input_cmd;
    int move_dist;
    bool is_active = true;

    printf("--- 深海ダイバー：トレジャーハンター ---\n");


    while (is_active)
    {
        display_status(current_depth, oxygen, total_points);

        printf("アクション: [%d]潜る [%d]財宝探す [%d]浮上開始 [%d]終了\n>> ", 1, 2, 3,0);

        input_cmd = checkInput(0, 3);

        switch (input_cmd)
        {

        case 0:
            printf("ゲームを終了します\n");
            break;
        case 1:
            printf("距離 (%dm-%dm): ", MIN_MOVE_DIST, MAX_MOVE_DIST);
            scanf("%d", &move_dist);
            if (is_valid_move(move_dist) && (current_depth + move_dist <= MAX_DEPTH)) {
                oxygen -= calculate_consumption(move_dist, total_points);
                current_depth += move_dist;
            }
            else {
                printf("!! 移動不可な距離です。\n");
            }
            break;
        case 2:
            total_points += (current_depth * POINT_MULTIPLIER);
            printf("★ 財宝を発見！合計 %d pt\n", total_points);
            break;
        case 3:
            // 浮上関数を呼び出し、ループを終了する
            oxygen = perform_ascent(current_depth, oxygen, total_points);
            is_active = false;
            break;

        }

        // 潜水中に酸素が切れたら終了
        if (oxygen <= 0) is_active = false;

    }

    /* 最終判定 */
    if (oxygen >= 0) 
    {
        printf("\n【生還成功！】\n最終スコア: %d ポイント\n", total_points);
    }
    else 
    {
        printf("\n【遭難...】\n酸素が尽き、海の藻屑となりました。獲得ポイントは0です。\n");
    }

	return 0;
}