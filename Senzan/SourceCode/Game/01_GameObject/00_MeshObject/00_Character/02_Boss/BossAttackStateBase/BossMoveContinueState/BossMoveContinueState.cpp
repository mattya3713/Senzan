#include "BossMoveContinueState.h"
#include "Game/01_GameObject/00_MeshObject/00_Character/02_Boss/Boss.h"
#include "Game/01_GameObject/00_MeshObject/00_Character/02_Boss/BossMoveState/BossMoveState.h"

BossMoveContinueState::BossMoveContinueState(Boss* owner)
    : BossAttackStateBase(owner)
{
}

BossMoveContinueState::~BossMoveContinueState()
{
}

void BossMoveContinueState::Enter()
{
    m_Timer = 0.0f;
    m_EndTime = m_Duration;
    // ボスAPIを使用してステートマシンオーナー経由でアニメを変更する.
    // Boss::enBossAnimはprivateのため、使用可能であればenum番号でChangeAnimを呼ぶ.
    m_pOwner->ChangeAnim(Boss::enBossAnim::Run); // アニメーションをRunに変更.
}

void BossMoveContinueState::Update()
{
    float delta = m_pOwner->GetDelta();
    m_Timer += delta;

    // このステートの間、簡略化されたBossMoveStateの移動フェーズに従う.
    DirectX::XMVECTOR vBossPos = DirectX::XMLoadFloat3(&m_pOwner->GetPosition());
    DirectX::XMFLOAT3 playerPosF = m_pOwner->GetTargetPos();
    DirectX::XMVECTOR vTarget = DirectX::XMLoadFloat3(&playerPosF);

    DirectX::XMVECTOR vToPlayer = DirectX::XMVectorSubtract(vTarget, vBossPos);
    vToPlayer = DirectX::XMVectorSetY(vToPlayer, 0.0f);
    float distanceToPlayer = DirectX::XMVectorGetX(DirectX::XMVector3Length(vToPlayer));

    // ローカル定数ではなく調整可能なメンバを使用する.
    const float STRAFE_RANGE = 20.0f;

    // ストレイフの応答性を上げるため回転速度をやや増加する.
    m_RotationSpeed = 0.4; // 旧: 0.1.

    switch (m_Phase)
    {
    case MovePhase::Start:
        // このcontinueステート内で即座にRunに入る.
        m_pOwner->ChangeAnim(Boss::enBossAnim::Run);
        m_Phase = MovePhase::Run;
        break;
    case MovePhase::Run:
    {
        // 設定可能な前方移動速度を使用する.
        float approachSpeed = m_MoveSpeed;
        DirectX::XMVECTOR vMoveDir = DirectX::XMVector3Normalize(vToPlayer);
        DirectX::XMVECTOR vNewPos = DirectX::XMVectorAdd(vBossPos, DirectX::XMVectorScale(vMoveDir, approachSpeed * delta));

        DirectX::XMFLOAT3 newPosF;
        DirectX::XMStoreFloat3(&newPosF, vNewPos);
        m_pOwner->SetPosition(newPosF);
        vBossPos = vNewPos;

        if (distanceToPlayer <= STRAFE_RANGE)
        {
            m_Phase = MovePhase::Stop;
            m_pOwner->ChangeAnim(Boss::enBossAnim::RunToIdol);
        }
    }
    break;
    case MovePhase::Stop:
        if (m_pOwner->IsAnimEnd(Boss::enBossAnim::RunToIdol))
        {
            m_Phase = MovePhase::Strafe;
            DirectX::XMVECTOR vDirFromPlayer = DirectX::XMVectorSubtract(vBossPos, vTarget);
            m_BaseAngle = atan2f(DirectX::XMVectorGetX(vDirFromPlayer), DirectX::XMVectorGetZ(vDirFromPlayer));
            m_RotationAngle = 0.0f;
        }
        break;
    case MovePhase::Strafe:
    {
        m_RotationAngle += static_cast<float>(m_RotationSpeed) * delta * m_rotationDirection;
        const float MAX_SWAY = DirectX::XM_PIDIV4;
        if (fabsf(m_RotationAngle) > MAX_SWAY)
        {
            m_rotationDirection *= -1.0f;
            m_RotationAngle = std::clamp(m_RotationAngle, -MAX_SWAY, MAX_SWAY);
        }

        float finalAngle = m_BaseAngle + m_RotationAngle;
        DirectX::XMVECTOR vOffset = DirectX::XMVectorSet(
            sinf(finalAngle) * STRAFE_RANGE,
            0.0f,
            cosf(finalAngle) * STRAFE_RANGE,
            0.0f
        );
        DirectX::XMVECTOR vIdealPos = DirectX::XMVectorAdd(vTarget, vOffset);

        constexpr float TRACKING_DELAY = 0.7f;

        DirectX::XMVECTOR vCurrentPos = XMLoadFloat3(&m_pOwner->GetPosition());
        float lerpFactor = TRACKING_DELAY * delta;
        if (lerpFactor > 1.0f) lerpFactor = 1.0f;

        DirectX::XMVECTOR vNextPos = DirectX::XMVectorLerp(vCurrentPos, vIdealPos, lerpFactor);

        DirectX::XMFLOAT3 finalPosF;
        DirectX::XMStoreFloat3(&finalPosF, vNextPos);
        finalPosF.y = m_pOwner->GetPosition().y;
        m_pOwner->SetPosition(finalPosF);

        m_pOwner->SetAnimSpeed(3.0);
        if (m_rotationDirection > 0)
            m_pOwner->ChangeAnim(Boss::enBossAnim::LeftMove);
        else
            m_pOwner->ChangeAnim(Boss::enBossAnim::RightMove);
    }
    break;
    }

    // プレイヤーに毎フレーム向きを変える.
    DirectX::XMVECTOR vFinalBossPos = XMLoadFloat3(&m_pOwner->GetPosition());
    DirectX::XMVECTOR vLookAt = DirectX::XMVectorSubtract(vTarget, vFinalBossPos);
    float dx = DirectX::XMVectorGetX(vLookAt);
    float dz = DirectX::XMVectorGetZ(vLookAt);
    float angle = atan2f(dx, dz) + DirectX::XM_PI;
    m_pOwner->SetRotationY(angle);

    // 持続時間を超えたらこのcontinueステートを終了する.
    if (m_Timer >= m_Duration)
    {
        m_pOwner->GetStateMachine()->ChangeState(std::make_shared<BossMoveState>(m_pOwner));
        return;
    }
}

void BossMoveContinueState::LateUpdate()
{
}

void BossMoveContinueState::Draw()
{
}

void BossMoveContinueState::Exit()
{
}
