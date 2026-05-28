#include <DxLib.h>
 
// キャラクターの定数

const int WINDOW_WIDTH = 640;   // ウィンドウの幅

const int WINDOW_HEIGHT = 480;  // ウィンドウの高さ

const int GROUND_Y = 400;       // 地面の高さ
 
// ジャンプの定数

const float GRAVITY = 0.5f;     // 重力加速度

const float JUMP_SPEED = 12.0f; // ジャンプの初速度
 
// キャラクターの情報

struct Character {

    float x;         // 水平方向の位置

    float y;         // 垂直方向の位置

    float vy;        // 垂直方向の速度

    bool isJumping;  // ジャンプ中かどうか

};
 
// メイン関数

int main() {

    // DxLibの初期化

    ChangeWindowMode(TRUE); // ウィンドウモードに設定

    if (DxLib_Init() == -1) return -1;

    SetDrawScreen(DX_SCREEN_BACK);
 
    // キャラクター初期設定

    Character player = { 300.0f, GROUND_Y, 0.0f, false };
 
    while (ScreenFlip() == 0 && ProcessMessage() == 0 && ClearDrawScreen() == 0) {

        // 入力処理

        if (CheckHitKey(KEY_INPUT_SPACE) && !player.isJumping) {

            player.isJumping = true;  // ジャンプ開始

            player.vy = -JUMP_SPEED;  // 上向き初速度を設定

        }
 
        // ジャンプ中の処理

        if (player.isJumping) {

            // 速度の更新（重力の影響）

            player.vy += GRAVITY;
 
            // 垂直方向の位置を更新

            player.y += player.vy;
 
            // 地面との接触判定

            if (player.y >= GROUND_Y) {

                player.y = GROUND_Y;       // 地面に固定

                player.isJumping = false; // ジャンプ終了

                player.vy = 0;            // 速度リセット

            }

        }
 
        // 水平方向の移動（オプション）

        if (CheckHitKey(KEY_INPUT_RIGHT)) player.x += 5.0f; // 右移動

        if (CheckHitKey(KEY_INPUT_LEFT)) player.x -= 5.0f;  // 左移動
 
        // 描画処理

        DrawBox(player.x - 20, player.y - 40, player.x + 20, player.y, GetColor(255, 255, 255), TRUE); // キャラクター

        DrawLine(0, GROUND_Y, WINDOW_WIDTH, GROUND_Y, GetColor(255, 0, 0));                           // 地面
 
        // 画面更新

        ScreenFlip();

    }
 
    // DxLibの終了処理

    DxLib_End();

    return 0;

}

 