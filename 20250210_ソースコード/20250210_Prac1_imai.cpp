/*
プレイヤーと敵の当たり判定を実装してください。プレイヤーはキーボードの矢印キーで移動でき、敵はプレイヤーの方向に向かってゆっくりと移動します。プレイヤーと敵が接触したら「当たり！」と画面に表示してください。
仕様
プレイヤーの操作
矢印キー（← ↑ → ↓）で上下左右に移動できる。
移動速度は 5 ピクセルとする。
敵の移動
敵はプレイヤーの位置を追いかけるように移動する。
移動速度は 2 ピクセルとする。
当たり判定
AABB（軸に揃った境界ボックス） による当たり判定を実装する。
プレイヤーと敵が接触した場合、画面上に 「当たり！」 と表示する。
描画
プレイヤーを 緑色の四角 (DrawBox で描画)
敵を 赤色の四角 (DrawBox で描画)
ゲームのフレームレート
60FPSで動作するようにする。
ヒント
当たり判定には**AABB（Axis-Aligned Bounding Box）**を使用すると良い。
CheckHitKey(KEY_INPUT_UP) などを使ってプレイヤーを動かせる。
敵をプレイヤーの方向に向かわせるために、座標の比較を利用する。
*/
#include "DxLib.h"
//FPS設定（60FPS）

//高精度でのフレーム管理
const double TARGET_FPS = 60.0;
const double FRAME_TIME = 1000000.0 / TARGET_FPS;

////前のフレーム変数
//double prevTime = GetCurrentTime();
//// デルタタイムタイム（経過時間）を計算
//double currentTime = GetCurrentTime();
//double deltaTime = currentTime - prevTime;

//基本クラス（プレイヤーや敵の共通部分）
class GameObject {
//座標とサイズ
protected:
    int x, y, width, height;
//コンストラクタ
public:
    GameObject(int x,int y,int width,int height):x(x),y(y),width(width),height(height){}
//更新処理（継承先で実装する）
    virtual void update() = 0;
//描画処理（オブジェクトの矩形を描画）
    virtual void draw(int color) {
        DrawBox(x, y, x + width, y + height, color, TRUE);
    }
//当たり判定(AABB方式)
    bool isColliding(const GameObject& other) {
        return (x < other.x + other.width &&
            x + width > other.x &&
            y < other.y + other.height &&
            y + height > other.y);
    }
//ゲッター（オブジェクトの座標を取得）
    int getX() const { return x; }
    int getY() const { return y; }
};
//プレイヤークラス
class Player :public GameObject {
//コンストラクタ
public:
    Player(int x, int y, int width, int height)
        : GameObject(x, y, width, height) {
    }
//プレイヤーの移動処理（テンキーで処理）
    void update() override {
        int speed = 5;
        if (CheckHitKey(KEY_INPUT_UP))    y -= speed;
        if (CheckHitKey(KEY_INPUT_DOWN))  y += speed;
        if (CheckHitKey(KEY_INPUT_LEFT))  x -= speed;
        if (CheckHitKey(KEY_INPUT_RIGHT)) x += speed;
    }

};
//敵クラス
class Enemy :public GameObject {
private:
//追いかける対象（プレイヤー）
    Player* target;
//敵の移動速度
    int speed;
//コンストラクタ（プレイヤーの情報を受け取る）
public:
    Enemy(int x, int y, int width, int height, Player* target)
        : GameObject(x, y, width, height), target(target), speed(2) {
    }
//プレイヤーを追尾する処理
    void update() override {
        if (target->getX() > x) x += speed;
        if (target->getX() < x) x -= speed;
        if (target->getY() > y) y += speed;
        if (target->getY() < y) y -= speed;
    }
};


//メインクラス
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {
    // DxLib初期化
    ChangeWindowMode(TRUE);
    if (DxLib_Init() == -1) return -1;
    SetDrawScreen(DX_SCREEN_BACK);
    // プレイヤーと敵の生成
    Player player(100, 100, 50, 50);
    Enemy enemy(400, 300, 50, 50, &player);

    //高精度タイマーでフレーム管理
    double prevTime = GetNowHiPerformanceCount();
    //ゲームループ
    while (ProcessMessage == 0) 
    {
        //現在の時間を取得
        double nowTime = GetNowHiPerformanceCount();
        //60FPSになるように調整
        if (nowTime - prevTime < FRAME_TIME) 
        {
            continue;
        }
        prevTime = nowTime;

        //更新処理
        player.update();
        enemy.update();
        //描画処理
        ClearDrawScreen();
        player.draw(GetColor(0, 255, 0));
        enemy.draw(GetColor(255, 0, 0));
        //当たり判定チェック
        if (player.isColliding(enemy)) {
            DrawString(200, 50, "当たり！", GetColor(255, 0, 0));
        }
        //画面更新
        ScreenFlip();
    }

    //Dxlib終了
    Dxlib_End();
    return 0;

}
