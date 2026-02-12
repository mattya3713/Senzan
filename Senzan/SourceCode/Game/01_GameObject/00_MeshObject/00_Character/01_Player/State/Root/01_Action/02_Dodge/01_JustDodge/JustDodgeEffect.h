#pragma once
#include <DirectXMath.h>
#include <string>

// 軽量エフェクトコントローラー: プレイヤーからボスへ移動するEffekseerエフェクトを再生する.
// エフェクトを開始位置から目標位置まで指定時間かけて移動させる.
class JustDodgeEffect
{
public:
    JustDodgeEffect();
    ~JustDodgeEffect();

    // エフェクトを開始する: effectNameはEffectResourceで検索され再生される.
    // startPos/worldStart と targetPos/worldTarget はワールド空間の座標.
    // duration: 移動にかける時間 (秒). デフォルト1秒.
    void Start(const std::string& effectName, const DirectX::XMFLOAT3& worldStart, const DirectX::XMFLOAT3& worldTarget, float scale = 1.0f, float duration = 1.0f);

    // フレームごとの更新: deltaTime を渡して位置を更新する.
    void Update(float deltaTime);

    // エフェクトハンドルを即座に停止して解放する.

    void Draw();

    bool IsPlaying() const noexcept { return m_Handle != -1; }

    // 移動完了したか (duration 経過後).
    bool IsFinished() const noexcept { return m_IsFinished; }

private:
    int m_Handle = -1;
    std::string m_EffectName;
    DirectX::XMFLOAT3 m_StartPos;
    DirectX::XMFLOAT3 m_TargetPos;
    DirectX::XMFLOAT3 m_CurrentPos;
    float m_Scale = 1.0f;
    float m_Duration = 1.0f;      // 移動時間 (秒).
    float m_ElapsedTime = 0.0f;   // 経過時間 (秒).
    bool m_IsFinished = false;    // 移動完了フラグ.
};
