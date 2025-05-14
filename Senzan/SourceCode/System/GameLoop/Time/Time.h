#pragma once
#include <chrono>

/************************
*   �^�C���N���X.
************************/
class CTime
{
public:
	~CTime();

	// �C���X�^���X���擾.
	static CTime* GetInstance();

	// �t���[���Ԃ̌o�ߎ��Ԃ��X�V.
	static void Update();

	// FPS���ێ����邽�߂̏���.
	static void MaintainFPS();

	// �f���^�^�C�����擾.
	static const float GetDeltaTime();
private:
	CTime();

	// ������R�s�[���폜.
	CTime(const CTime& rhs)					= delete;
	CTime& operator = (const CTime& rhs)	= delete;
private:
	// �O�t���[���̎���.
	std::chrono::time_point<std::chrono::high_resolution_clock> m_PreviousTime;

	float m_TargetFrameTime;// �ڕW�t���[������(�b).
	float m_DeltaTime;		// �t���[���Ԃ̎��ԍ�.
};
