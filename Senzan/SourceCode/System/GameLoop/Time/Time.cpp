#include "Time.h"
#include <thread>

constexpr float TAEGET_FPS = 60.0f;//�ڕW�t���[��.

CTime::CTime()
    : m_PreviousTime    ()
    , m_TargetFrameTime ()
    , m_DeltaTime       ()
{
    m_TargetFrameTime   = 1.0f / TAEGET_FPS; // �ڕW�t���[�����v�Z.
    m_PreviousTime      = std::chrono::high_resolution_clock::now();//�������擾.
}

CTime::~CTime()
{
}

// �C���X�^���X���擾.
CTime* CTime::GetInstance()
{
    static CTime instance;
    return &instance;
}

// �t���[���Ԃ̌o�ߎ��Ԃ��X�V.
void CTime::Update()
{
    // �C���X�^���X���擾.
    CTime* pI = GetInstance();

    // ���݂̎��Ԃ��擾.
    auto currentTime = std::chrono::high_resolution_clock::now();

    // �O�񂩂�̌o�ߎ��Ԃ��v�Z.
    std::chrono::duration<float> elapsed = currentTime - pI->m_PreviousTime;

    // �o�ߎ��Ԃ�b�P�ʂŕێ�.
    pI->m_DeltaTime = elapsed.count();

    // ���̃t���[���̂��߂ɍX�V.
    pI->m_PreviousTime = currentTime;
}

// FPS���ێ����邽�߂̏���.
void CTime::MaintainFPS()
{
    // �C���X�^���X���擾.
    CTime* pI = GetInstance();

    if (pI->m_DeltaTime < pI->m_TargetFrameTime) {
        pI->m_DeltaTime = pI->m_TargetFrameTime;
       /* std::this_thread::sleep_for(
            std::chrono::duration<float>(pI->m_TargetFrameTime - pI->m_DeltaTime));*/
    }
}

// �f���^�^�C�����擾.
const float CTime::GetDeltaTime()
{
    return GetInstance()->m_DeltaTime;
}
