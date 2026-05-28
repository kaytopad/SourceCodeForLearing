// main.cpp
// DxLib: 斬撃必殺技カメラ演出（広角FOVを SetupCamera_Perspective で制御）
// SPACE：必殺技開始
// WASD：移動（通常時のみ） / Q,E：回転（通常時のみ）
// ESC：終了

#include "DxLib.h"
#include <vector>
#include <cmath>

// -----------------------------
// 小ユーティリティ
// -----------------------------
static float Clamp01(float x)
{
    if (x < 0.0f) return 0.0f;
    if (x > 1.0f) return 1.0f;
    return x;
}

static float Lerp(float a, float b, float t)
{
    return a + (b - a) * t;
}

static VECTOR VLerp(const VECTOR& a, const VECTOR& b, float t)
{
    return VAdd(a, VScale(VSub(b, a), t));
}

static float EaseInOut(float t)
{
    t = Clamp01(t);
    return t * t * (3.0f - 2.0f * t); // smoothstep
}

static VECTOR RandomShake(float amp)
{
    if (amp <= 0.0f) return VGet(0, 0, 0);
    float rx = (GetRand(2000) - 1000) / 1000.0f;
    float ry = (GetRand(2000) - 1000) / 1000.0f;
    float rz = (GetRand(2000) - 1000) / 1000.0f;
    return VGet(rx * amp, ry * amp, rz * amp);
}

// -----------------------------
// FOV（画角）を安全に反映するヘルパー
// ここが今回の「広角にする」ポイント
// -----------------------------
static void ApplyFovDeg(float fovDeg)
{
    // 広すぎ/狭すぎ防止（授業ではここを調整課題にしてもOK）
    if (fovDeg < 10.0f)  fovDeg = 10.0f;
    if (fovDeg > 120.0f) fovDeg = 120.0f;

    // DxLibはラジアン指定
    float fovRad = fovDeg * DX_PI_F / 180.0f;

    // 遠近法の画角を設定（=広角/ズームを制御）
    SetupCamera_Perspective(fovRad);
}

// -----------------------------
// 演出用キーフレーム
// -----------------------------
struct CameraKeyFrame
{
    float  time = 0.0f;     // 演出開始からの秒
    VECTOR pos  = VGet(0, 0, 0);
    VECTOR target = VGet(0, 0, 0);
    float  fovDeg = 60.0f;  // ここは「度」管理にして授業で分かりやすく
    float  shakeAmp = 0.0f;
    float  flash = 0.0f;    // 0〜1
};

// -----------------------------
// 必殺技カメラ（タイムライン再生）
// -----------------------------
class SpecialSlashCamera
{
public:
    void Start(const VECTOR& playerPos, const VECTOR& playerForward)
    {
        m_active = true;
        m_time = 0.0f;

        // ヒットストップ
        m_hitStopActive = false;
        m_hitStopRemain = 0.0f;
        m_hitStopStart = 0.70f;
        m_hitStopDuration = 0.08f;

        // ブレンド復帰（演出終了後に通常カメラへ滑らかに戻す）
        m_blendBackActive = false;
        m_blendBackT = 0.0f;
        m_blendBackTime = 0.35f;

        // 基準：演出開始時の位置・向き
        VECTOR f = playerForward;
        if (VSize(f) < 0.0001f) f = VGet(0, 0, 1);
        f = VNorm(f);

        VECTOR u = VGet(0, 1, 0);
        VECTOR r = VNorm(VCross(u, f));

        // --- タイムライン（授業で一番いじる場所） ---
        // 溜め（狭め）→ 見せ → 一閃（広角）→ ヒットストップ → 余韻（通常へ）
        m_keys.clear();

        // 0.00 溜め：寄り + ズーム（狭FOV）
        {
            CameraKeyFrame k;
            k.time = 0.00f;
            k.pos = VAdd(playerPos, VAdd(VScale(f, -1.2f), VAdd(VScale(u, 1.2f), VScale(r, 0.3f))));
            k.target = VAdd(playerPos, VScale(u, 1.0f));
            k.fovDeg = 50.0f;      // ← ズーム寄り（狭）
            k.shakeAmp = 0.0f;
            k.flash = 0.0f;
            m_keys.push_back(k);
        }

        // 0.20 見せ：肩越し（少し回り込み）
        {
            CameraKeyFrame k;
            k.time = 0.20f;
            k.pos = VAdd(playerPos, VAdd(VScale(f, -1.0f), VAdd(VScale(u, 1.4f), VScale(r, 1.1f))));
            k.target = VAdd(playerPos, VScale(u, 1.1f));
            k.fovDeg = 52.0f;      // まだ狭め
            k.shakeAmp = 0.0f;
            k.flash = 0.0f;
            m_keys.push_back(k);
        }

        // 0.60 一閃直前：少し引いて斬撃が入る
        {
            CameraKeyFrame k;
            k.time = 0.60f;
            k.pos = VAdd(playerPos, VAdd(VScale(f, -2.3f), VAdd(VScale(u, 1.6f), VScale(r, 0.2f))));
            k.target = VAdd(playerPos, VAdd(VScale(f, 1.0f), VScale(u, 1.0f)));
            k.fovDeg = 62.0f;      // ここから少し広げる（速度感）
            k.shakeAmp = 0.05f;
            k.flash = 0.0f;
            m_keys.push_back(k);
        }

        // 0.70 ピーク：一瞬だけ広角 + 強シェイク + フラッシュ
        {
            CameraKeyFrame k;
            k.time = 0.70f;
            k.pos = m_keys.back().pos;      // 位置はほぼ固定で“決める”
            k.target = m_keys.back().target;
            k.fovDeg = 80.0f;               // ← 広角（迫力）
            k.shakeAmp = 0.18f;
            k.flash = 1.0f;
            m_keys.push_back(k);
        }

        // 1.60 余韻：少し低めから見上げ、通常へ戻す
        {
            CameraKeyFrame k;
            k.time = 1.60f;
            k.pos = VAdd(playerPos, VAdd(VScale(f, -3.5f), VScale(u, 1.2f)));
            k.target = VAdd(playerPos, VScale(u, 1.0f));
            k.fovDeg = 60.0f;      // ← 通常に戻す
            k.shakeAmp = 0.0f;
            k.flash = 0.0f;
            m_keys.push_back(k);
        }

        m_endTime = m_keys.back().time;
    }

    void Update(float dt)
    {
        if (!m_active) return;

        // ヒットストップ開始判定
        if (!m_hitStopActive && m_time >= m_hitStopStart)
        {
            m_hitStopActive = true;
            m_hitStopRemain = m_hitStopDuration;
        }

        // ヒットストップ中は演出時間を進めない
        if (m_hitStopActive)
        {
            m_hitStopRemain -= dt;
            if (m_hitStopRemain <= 0.0f)
            {
                m_hitStopActive = false;
            }
        }
        else
        {
            m_time += dt;
        }

        // 演出終了 → ブレンド復帰
        if (!m_blendBackActive && m_time >= m_endTime)
        {
            m_blendBackActive = true;
            m_blendBackT = 0.0f;
        }

        if (m_blendBackActive)
        {
            m_blendBackT += dt;
            if (m_blendBackT >= m_blendBackTime)
            {
                m_active = false;
            }
        }
    }

    bool IsActive() const { return m_active; }
    bool IsHitStop() const { return m_hitStopActive; }

    // 0→演出カメラ / 1→通常カメラ（復帰ブレンド用）
    float GetBlendBackAlpha() const
    {
        if (!m_blendBackActive) return 0.0f;
        float a = Clamp01(m_blendBackT / m_blendBackTime);
        return EaseInOut(a);
    }

    // 現在時刻のカメラを評価
    void Evaluate(VECTOR& outPos, VECTOR& outTarget, float& outFovDeg, float& outShakeAmp, float& outFlash) const
    {
        if (m_keys.size() < 2)
        {
            outPos = VGet(0, 0, 0);
            outTarget = VGet(0, 0, 1);
            outFovDeg = 60.0f;
            outShakeAmp = 0.0f;
            outFlash = 0.0f;
            return;
        }

        float t = m_time;

        // 範囲外
        if (t <= m_keys.front().time)
        {
            const auto& k = m_keys.front();
            outPos = k.pos; outTarget = k.target; outFovDeg = k.fovDeg;
            outShakeAmp = k.shakeAmp; outFlash = k.flash;
            return;
        }
        if (t >= m_keys.back().time)
        {
            const auto& k = m_keys.back();
            outPos = k.pos; outTarget = k.target; outFovDeg = k.fovDeg;
            outShakeAmp = k.shakeAmp; outFlash = k.flash;
            return;
        }

        // 今がどの区間か
        int i = 0;
        while (i + 1 < (int)m_keys.size() && t > m_keys[i + 1].time) ++i;

        const auto& k0 = m_keys[i];
        const auto& k1 = m_keys[i + 1];

        float local = (t - k0.time) / (k1.time - k0.time);
        local = Clamp01(local);

        // ピーク区間（0.60→0.70）は“カット感”を強める（ほぼ切替）
        if (k0.time >= 0.60f && k1.time <= 0.70f)
        {
            local = (local < 0.6f) ? 0.0f : 1.0f;
        }
        else
        {
            local = EaseInOut(local);
        }

        outPos = VLerp(k0.pos, k1.pos, local);
        outTarget = VLerp(k0.target, k1.target, local);
        outFovDeg = Lerp(k0.fovDeg, k1.fovDeg, local);
        outShakeAmp = Lerp(k0.shakeAmp, k1.shakeAmp, local);
        outFlash = Lerp(k0.flash, k1.flash, local);

        // フラッシュはピーク後すぐ減衰
        if (t > 0.70f)
        {
            float decay = Clamp01((t - 0.70f) / 0.12f);
            outFlash *= (1.0f - decay);
        }
    }

private:
    bool m_active = false;
    float m_time = 0.0f;
    float m_endTime = 0.0f;

    std::vector<CameraKeyFrame> m_keys;

    // ヒットストップ
    float m_hitStopStart = 0.70f;
    float m_hitStopDuration = 0.08f;
    bool  m_hitStopActive = false;
    float m_hitStopRemain = 0.0f;

    // ブレンド復帰
    bool  m_blendBackActive = false;
    float m_blendBackT = 0.0f;
    float m_blendBackTime = 0.35f;
};

// -----------------------------
// 通常カメラ（簡易TPS風）
// -----------------------------
static void EvaluateNormalCamera(const VECTOR& playerPos, const VECTOR& playerForward,
                                 VECTOR& outPos, VECTOR& outTarget, float& outFovDeg)
{
    VECTOR f = playerForward;
    if (VSize(f) < 0.0001f) f = VGet(0, 0, 1);
    f = VNorm(f);

    VECTOR u = VGet(0, 1, 0);

    // 後ろ上
    outPos = VAdd(playerPos, VAdd(VScale(f, -6.0f), VScale(u, 3.0f)));
    outTarget = VAdd(playerPos, VScale(u, 1.2f));
    outFovDeg = 60.0f; // 通常は60度
}

// -----------------------------
// 画面フラッシュ（2Dオーバーレイ）
// -----------------------------
static void DrawFlashOverlay(float intensity01)
{
    intensity01 = Clamp01(intensity01);
    if (intensity01 <= 0.001f) return;

    int w, h;
    GetDrawScreenSize(&w, &h);

    int alpha = (int)(intensity01 * 255.0f);
    SetDrawBlendMode(DX_BLENDMODE_ALPHA, alpha);
    DrawBox(0, 0, w, h, GetColor(255, 255, 255), TRUE);
    SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
}

// -----------------------------
// 簡易ワールド（床/プレイヤー/敵/斬撃線）
// -----------------------------
static void DrawWorld(const VECTOR& playerPos, const VECTOR& enemyPos, bool drawSlashLine, float slashAlpha)
{
    DrawCube3D(VGet(-50, -0.5f, -50), VGet(50, 0.0f, 50), GetColor(80, 80, 80), GetColor(40, 40, 40), TRUE);

    // プレイヤー（青）
    DrawCube3D(VAdd(playerPos, VGet(-0.5f, 0.0f, -0.5f)), VAdd(playerPos, VGet(0.5f, 1.8f, 0.5f)),
               GetColor(80, 160, 255), GetColor(80, 160, 255), TRUE);

    // 敵（赤）
    DrawCube3D(VAdd(enemyPos, VGet(-0.6f, 0.0f, -0.6f)), VAdd(enemyPos, VGet(0.6f, 2.0f, 0.6f)),
               GetColor(255, 90, 90), GetColor(255, 90, 90), TRUE);

    // 斬撃（線）
    if (drawSlashLine)
    {
        slashAlpha = Clamp01(slashAlpha);
        int a = (int)(slashAlpha * 255.0f);
        SetDrawBlendMode(DX_BLENDMODE_ALPHA, a);

        VECTOR start = VAdd(playerPos, VGet(0, 1.2f, 0));
        VECTOR end   = VAdd(enemyPos,  VGet(0, 1.2f, 0));
        DrawLine3D(start, end, GetColor(255, 255, 255));

        SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
    }
}

// -----------------------------
// メイン
// -----------------------------
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
    SetOutApplicationLogValidFlag(FALSE);
    ChangeWindowMode(TRUE);
    SetGraphMode(1280, 720, 32);
    SetUseZBuffer3D(TRUE);
    SetWriteZBuffer3D(TRUE);

    if (DxLib_Init() == -1) return -1;
    SetDrawScreen(DX_SCREEN_BACK);

    // 3D設定
    SetCameraNearFar(0.1f, 200.0f);

    // プレイヤー状態（簡易）
    VECTOR playerPos = VGet(0, 0, 0);
    float  playerYaw = 0.0f;

    auto GetPlayerForward = [&]() -> VECTOR
    {
        float sx = sinf(playerYaw);
        float cz = cosf(playerYaw);
        return VNorm(VGet(sx, 0, cz));
    };

    // 敵
    VECTOR enemyPos = VGet(0, 0, 12);

    // 必殺技カメラ
    SpecialSlashCamera specialCam;

    // 斬撃線
    bool  slashVisible = false;
    float slashAlpha = 0.0f;

    // 時間
    int prevMs = GetNowCount();

    while (ProcessMessage() == 0 && CheckHitKey(KEY_INPUT_ESCAPE) == 0)
    {
        int nowMs = GetNowCount();
        float dt = (nowMs - prevMs) / 1000.0f;
        prevMs = nowMs;

        // dt暴れ対策
        if (dt > 0.05f) dt = 0.05f;

        bool isSpecial = specialCam.IsActive();

        // 必殺技開始
        if (!isSpecial && CheckHitKey(KEY_INPUT_SPACE))
        {
            specialCam.Start(playerPos, GetPlayerForward());
            slashVisible = false;
            slashAlpha = 0.0f;
        }

        // ヒットストップ中はワールド更新を止める
        bool worldFreeze = isSpecial && specialCam.IsHitStop();

        // 通常時のみプレイヤー操作
        if (!isSpecial)
        {
            const float moveSpeed = 6.0f;
            const float rotSpeed  = 2.2f;

            if (CheckHitKey(KEY_INPUT_Q)) playerYaw -= rotSpeed * dt;
            if (CheckHitKey(KEY_INPUT_E)) playerYaw += rotSpeed * dt;

            VECTOR f = GetPlayerForward();
            VECTOR u = VGet(0, 1, 0);
            VECTOR r = VNorm(VCross(u, f));

            VECTOR move = VGet(0, 0, 0);
            if (CheckHitKey(KEY_INPUT_W)) move = VAdd(move, f);
            if (CheckHitKey(KEY_INPUT_S)) move = VSub(move, f);
            if (CheckHitKey(KEY_INPUT_D)) move = VAdd(move, r);
            if (CheckHitKey(KEY_INPUT_A)) move = VSub(move, r);

            if (VSize(move) > 0.0001f)
            {
                move = VNorm(move);
                playerPos = VAdd(playerPos, VScale(move, moveSpeed * dt));
            }
        }

        // 必殺技カメラ更新
        if (isSpecial)
        {
            specialCam.Update(dt);

            // 斬撃線：ピークのフラッシュをトリガーに出す（例題として簡単化）
            VECTOR spPos, spTgt;
            float spFovDeg, spShake, spFlash;
            specialCam.Evaluate(spPos, spTgt, spFovDeg, spShake, spFlash);

            if (spFlash > 0.2f)
            {
                slashVisible = true;
                slashAlpha = 1.0f;
            }
            else
            {
                slashAlpha -= dt * 1.8f;
                if (slashAlpha <= 0.0f)
                {
                    slashAlpha = 0.0f;
                    slashVisible = false;
                }
            }
        }

        // 敵の更新（例：左右に揺れる）※ヒットストップ中は止める
        if (!worldFreeze)
        {
            enemyPos.x = sinf(GetNowCount() / 700.0f) * 2.0f;
        }

        // -----------------------------
        // カメラ計算（通常 or 必殺技）
        // -----------------------------
        VECTOR normalPos, normalTarget;
        float  normalFovDeg;
        EvaluateNormalCamera(playerPos, GetPlayerForward(), normalPos, normalTarget, normalFovDeg);

        VECTOR camPos = normalPos;
        VECTOR camTarget = normalTarget;
        float  camFovDeg = normalFovDeg;
        float  flash = 0.0f;

        if (specialCam.IsActive())
        {
            VECTOR spPos, spTgt;
            float spFovDeg, spShake, spFlash;
            specialCam.Evaluate(spPos, spTgt, spFovDeg, spShake, spFlash);

            // シェイク
            spPos = VAdd(spPos, RandomShake(spShake));

            // 演出終了後は通常へブレンド復帰
            float a = specialCam.GetBlendBackAlpha();
            if (a > 0.0f)
            {
                camPos = VLerp(spPos, normalPos, a);
                camTarget = VLerp(spTgt, normalTarget, a);
                camFovDeg = Lerp(spFovDeg, normalFovDeg, a);
            }
            else
            {
                camPos = spPos;
                camTarget = spTgt;
                camFovDeg = spFovDeg;
            }

            flash = spFlash;
        }

        // ★ここが「広角を反映する」本体
        ApplyFovDeg(camFovDeg);

        // カメラ位置・注視点を反映
        SetCameraPositionAndTarget_UpVecY(camPos, camTarget);

        // -----------------------------
        // 描画
        // -----------------------------
        ClearDrawScreen();

        DrawWorld(playerPos, enemyPos, slashVisible, slashAlpha);

        DrawFormatString(20, 20, GetColor(255, 255, 255),
            "SPACE: Special Slash / WASD Move / Q,E Rotate / ESC Exit");
        DrawFormatString(20, 45, GetColor(200, 200, 200),
            "FOV(deg): %.1f  (Charge: ~50 / Peak Wide: 80 / Normal: 60)", camFovDeg);

        if (specialCam.IsActive())
        {
            DrawString(20, 70, "Special Camera: ACTIVE", GetColor(255, 220, 80));
        }

        // フラッシュ（最後に重ねる）
        DrawFlashOverlay(flash);

        ScreenFlip();
    }

    DxLib_End();
    return 0;
}
