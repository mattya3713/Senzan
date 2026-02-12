#pragma once

#include "..//BossAttackStateBase.h".

class BossIdolState;
class Boss;

class BossLaserState final : public BossAttackStateBase
{
public:
    enum class enLaser : unsigned char
    {
        None,
        Charge,
        Fire,
        Cool,
        Trans
    };

public:
    BossLaserState(Boss* owner);
    ~BossLaserState() override;

    void Enter() override;
    void Update() override;
    void LateUpdate() override;
    void Draw() override;
    void Exit() override;

    std::pair<Boss::enBossAnim, float> GetParryAnimPair() override;

    void DrawImGui() override;
    void LoadSettings() override;
    void SaveSettings() const override;
    std::filesystem::path GetSettingsFileName() const override { return std::filesystem::path("BossLaserState.json"); }

private:
    enLaser m_State;

    // 溜めタイミング.
    float m_ChargeDuration;
    float m_ChargeElapsed;

    // 発射タイミング.
    float m_FireDuration;
    float m_FireElapsed;

    // レーザーパラメータ.
    float m_LaserDamage;
    float m_LaserRadius;
    float m_LaserRange;

    // エフェクト再生済みフラグ.

    std::shared_ptr<BossIdolState> m_pIdol;
};
