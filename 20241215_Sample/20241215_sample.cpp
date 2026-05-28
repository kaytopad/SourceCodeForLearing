#include "DxLib.h"

// ゲームの状態を定義
#define GAME_STATE_PLAYING 0
#define GAME_STATE_PAUSED  1

// グローバル変数
int gameState = GAME_STATE_PLAYING; // 現在のゲーム状態
int screenWidth = 640;             // ウィンドウ幅
int screenHeight = 480;            // ウィンドウ高さ

// ポーズ画面の表示
void DrawPauseScreen() {
    // 画面全体を暗くする（半透明）
    SetDrawBlendMode(DX_BLENDMODE_ALPHA, 128);
    DrawBox(0, 0, screenWidth, screenHeight, GetColor(0, 0, 0), TRUE);
    SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);

    // ポーズ文字表示
    DrawString(screenWidth / 2 - 80, screenHeight / 2 - 20, "PAUSED", GetColor(255, 255, 255));

    // 再開と終了の選択肢
    DrawString(screenWidth / 2 - 100, screenHeight / 2 + 40, "Press SPACE to Resume", GetColor(200, 200, 200));
    DrawString(screenWidth / 2 - 100, screenHeight / 2 + 80, "Press ESC to Quit", GetColor(200, 200, 200));
}

int main() {
    // DxLibの初期化
    ChangeWindowMode(TRUE); // ウィンドウモードに設定
    if (DxLib_Init() == -1) {
        return -1; // 初期化に失敗したら終了
    }
    SetDrawScreen(DX_SCREEN_BACK); // 裏画面設定

    while (ScreenFlip() == 0 && ProcessMessage() == 0 && ClearDrawScreen() == 0) {
        // ゲームプレイ中の処理
        if (gameState == GAME_STATE_PLAYING) {
            // ESCキーでポーズ画面に移行
            if (CheckHitKey(KEY_INPUT_ESCAPE)) {
                gameState = GAME_STATE_PAUSED;
            }

            // ゲームの動作（プレイヤーや敵の処理を追加）
            DrawString(10, 10, "Game Playing...", GetColor(255, 255, 255));
        }

        // ポーズ中の処理
        else if (gameState == GAME_STATE_PAUSED) {
            DrawPauseScreen();

            // ポーズ解除
            if (CheckHitKey(KEY_INPUT_SPACE)) {
                gameState = GAME_STATE_PLAYING;
            }

            // 終了
            if (CheckHitKey(KEY_INPUT_ESCAPE)) {
                break;
            }
        }
    }

    // DxLibの終了処理
    DxLib_End();
    return 0;
}
