/*
Dxlibを使ってゲームを作成しましょう。
今回作成するのは、ブロック崩しです。
画面の大きさは（920×680）
ブロックの大きさは42×10
ブロックは縦4個、横5個
バーの大きさ120×10
*/
#include"DxLib.h"

//定数
const int BLOCK_WIDTH = 55;
const int BLOCK_HIGHT = 20;
const int BLOCK_NUM_X = 10;
const int BLOCK_NUM_Y = 6;
const int BLOCK_IN = 8;

const int BALL_RADIUS = BLOCK_IN + 2;

//ループ
int i, j;
//ブロックのポジション
int Xpos, Ypos;
int BarX, BlockX;

int Xpos2, Ypos2;

//クリアフラグ
bool isClear = true;

//ブロックの構造体
typedef struct block
{
    int x, y;
    int width = BLOCK_WIDTH;
    int hight = BLOCK_HIGHT;
    //表示フラグ
    bool isVisible = true;

}block;
//ボールの構造
typedef struct ball
{
    int x, y;
    int xdirectio = 1, ydirectio = 1;
}ball;
//バーの構造体
typedef struct bar
{
    int x = 5, y = 540;
    int width = 120;
    int hight = 10;

}bar;

//構造体変数
block Blocks[BLOCK_NUM_X][BLOCK_NUM_Y];
ball Ball;
bar Bar;

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{

    //----------------------------------// 
    //基本設定
    //----------------------------------// 

    ChangeWindowMode(TRUE);				//ウィンドウモードにする
    DxLib_Init();						//ライブラリを初期化 Initialise
    SetMainWindowText("ブロック崩し");
    SetDrawScreen(DX_SCREEN_BACK);
    SetGraphMode(680, 560, 32);
    //ライブラリ初期化でエラー起きたら終了
    if (DxLib_Init() == -1)
    {
        return -1;
    }

    //ブロックの初期化
    for ( i = 0; i < BLOCK_NUM_Y; i++)
    {
        Ypos = 120 + (i * (BLOCK_HIGHT + 10));
        for ( j = 0; j < BLOCK_NUM_X; j++)
        {
            Xpos = j * (BLOCK_WIDTH + 10) + 10;
            Blocks[j][i] = {};
            Blocks[j][i].x = Xpos;
            Blocks[j][i].y = Ypos;
        }
    }
    //ボールの初期化
    Ball.x = Bar.x + Bar.width / 2;
    Ball.y = Bar.y - BALL_RADIUS * 3;

    //ゲームスタート

    while (ScreenFlip() == 0 && ProcessMessage() == 0 && ClearDrawScreen() == 0)
    {
        //ボールの移動
        Ball.x += 3 * Ball.xdirectio;
        Ball.y += 3 * Ball.ydirectio;

        //壁に当たったら
        //横（X座標）
        if (Ball.x < 0 || Ball.x > 680)
        {
            Ball.xdirectio *= -1;
        }
        //縦（Y座標）
        if (Ball.y < 0)
        {
            Ball.ydirectio *= -1;
        }
        //バーとボールの当たり判定
        if (Bar.x < Ball.x && Ball.x < Bar.x + Bar.width && Bar.y - 5 < Ball.y && Ball.y < Bar.y + 5)
        {
            //速度を変化
            BarX = (Ball.x - (Bar.x + Bar.width / 2))/8;

            Ball.xdirectio = BarX;
            Ball.ydirectio *= -1;
        }
        //ボールとブロックの当たり判定

        for ( i = 0; i < BLOCK_NUM_Y; i++)
        {
            for ( j = 0; j < BLOCK_NUM_X; j++)
            {
                if (Blocks[j][i].isVisible)
                {
                    isClear = true;
                    Xpos2 = Blocks[j][i].x;
                    Ypos2 = Blocks[j][i].y;
                    //当たり判定
                    if ((Xpos2 < Ball.x + BALL_RADIUS) && (Ball.x < Xpos2+BLOCK_WIDTH) &&(Ypos2 < Ball.y + BALL_RADIUS) && (Ball.y < Ypos2+BLOCK_HIGHT))
                    {
                        Blocks[j][i].isVisible = false;
                        BlockX = (Ball.x - (Xpos2 + Blocks[j][i].width / 2)) / 8;

                        Ball.xdirectio = BlockX;
                        Ball.ydirectio *= -1;
                    }

                }
            }
        }
        //クリア判定
        for ( i = 0; i < BLOCK_NUM_Y; i++)
        {
            for ( j = 0; j < BLOCK_NUM_Y; j++)
            {
                if (Blocks[j][i].isVisible)
                {
                    isClear = false;
                }
            }
        }

        //クリア判定とゲームオーバー

        if (isClear)
        {
            break;
        }

        if (Ball.y > 560)
        {
            break;
        }

        //バーの移動
        //右に移動
        if (CheckHitKey(KEY_INPUT_RIGHT))
        {
            Bar.x += 7;
            if (Bar.x > 615)
            {
                Bar.x = 615;
            }
        }

        //左に移動
        if (CheckHitKey(KEY_INPUT_LEFT))
        {
            Bar.x -= 7;
            if (Bar.x < 3)
            {
                Bar.x = 3;
            }
        }

        //ブロックの描画

        for ( i = 0; i < BLOCK_NUM_Y; i++)
        {
            for ( j = 0; j < BLOCK_NUM_X; j++)
            {
                if (Blocks[j][i].isVisible)
                {
                    DrawBox(Blocks[j][i].x, Blocks[j][i].y, Blocks[j][i].x + Blocks[j][i].width, Blocks[j][i].y + Blocks[j][i].hight, GetColor(255, 255, 255), TRUE);
                }
            }
        }


        //バーの描画
        DrawBox(Bar.x,Bar.y,Bar.x+Bar.width,Bar.y+Bar.hight,GetColor(128,128,128),TRUE);
        //ボールの描画
        DrawCircle(Ball.x, Ball.y, BALL_RADIUS, GetColor(0, 255, 255), TRUE);

    }

    //Dxライブラリ使用の終了
    DxLib_End();
    return 0;

}