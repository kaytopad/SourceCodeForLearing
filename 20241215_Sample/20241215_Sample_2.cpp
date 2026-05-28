#include "DxLib.h"

// ゲームの状態を定義
#define GAME_STATE_PLAYING 0
#define GAME_STATE_PAUSED  1

// グローバル変数
int gameState = GAME_STATE_PLAYING; // ゲーム状態
int screenWidth = 640;             // ウィンドウ幅
int screenHeight = 480;            // ウィンドウ高さ
int pauseScreenHandle;             // ポーズ画面用スクリーンバッファ

// ポーズ画面の表示
void DrawPauseScreen() {
    // バッファに描画した内容を半透明で表示
    SetDrawBlendMode(DX_BLENDMODE_ALPHA, 128); // 半透明モード
    DrawGraph(0, 0, pauseScreenHandle, TRUE);
    SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0); // 通常描画に戻す

    // ポーズ文字表示
    DrawString(screenWidth / 2 - 80, screenHeight / 2 - 20, "PAUSED", GetColor(255, 255, 255));

    // 再開と終了の選択肢
    DrawString(screenWidth / 2 - 100, screenHeight / 2 + 40, "Press SPACE to Resume", GetColor(200, 200, 200));
    DrawString(screenWidth / 2 - 100, screenHeight / 2 + 80, "Press ESC to Quit", GetColor(200, 200, 200));
}

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
    // DxLib初期化
    ChangeWindowMode(TRUE); // ウィンドウモード
    if (DxLib_Init() == -1) {
        return -1;
    }
    SetDrawScreen(DX_SCREEN_BACK); // 裏画面設定

    // スクリーンバッファを作成
    pauseScreenHandle = MakeScreen(screenWidth, screenHeight, TRUE);
    if (pauseScreenHandle == -1) {
        DxLib_End();
        return -1;
    }

    while (ScreenFlip() == 0 && ProcessMessage() == 0 && ClearDrawScreen() == 0) {
        if (gameState == GAME_STATE_PLAYING) {
            // ESCキーでポーズに移行
            if (CheckHitKey(KEY_INPUT_ESCAPE)) {
                // ゲーム画面をバッファに保存
                SetDrawScreen(pauseScreenHandle); // バッファに切り替え
                ClearDrawScreen(); // バッファをクリア
                // 現在のゲーム画面を描画
                DrawString(10, 10, "Game Playing...", GetColor(255, 255, 255));
                SetDrawScreen(DX_SCREEN_BACK); // 描画先を戻す

                gameState = GAME_STATE_PAUSED;
            }

            // ゲームプレイ中の処理
            DrawString(10, 10, "Game Playing...", GetColor(255, 255, 255));
        }
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

    // リソースの解放
    DeleteGraph(pauseScreenHandle);
    DxLib_End();
    return 0;
}