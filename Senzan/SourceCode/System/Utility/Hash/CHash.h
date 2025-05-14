#pragma once
#include "Utility\\Hash\\Crc32Table\\HashTable.h"  // Hash�e�[�u��.

#define ENABLE_HASH_DEBUG (0) // 1: Hash�̃f�o�b�O�@�\��L��.
                              // 0: ����.

/****************************
*	�n�b�V���l�N���X.
*	�S���F���e ����.
*   �Q�lURL:https://norizn.hatenablog.com/entry/2020/10/18/145628#2
****/

class CHash
{
public:
    CHash(const char* str) 
        : m_digest(0)
#if ENABLE_HASH_DEBUG
        , m_debug_str("")
#endif
    {
        m_digest = GetDigest(str, std::string(str).length());

#if ENABLE_HASH_DEBUG
        m_debug_str = str;
#endif
    };

    // �n�b�V���l���擾.
    uint32_t GetDigest() const { return m_digest; }

    // �����񂩂�n�b�V���l���쐬���Ď擾.
    static constexpr uint32_t GetDigest(const char* str, const size_t length);

private:
    uint32_t    m_digest;          // �n�b�V���l.
  

#if ENABLE_HASH_DEBUG
public:
    // (�f�o�b�O�p) ��������擾.
    const char* GetDebugStr() const { return m_debug_str.c_str(); }

private:
    std::string m_debug_str;   // (�f�o�b�O�p) ������
#endif
};

// ��������n�b�V���l�ɕϊ�����B
// �g�p��: HASH_DIGEST("STAGE_FOREST")
// sizeof��null�I�[���܂ݕ�����+1�����̂�-1���ĕ������݂̂ɂ��Ă����B 
#define HASH_DIGEST(str) CHash::GetDigest(str, (sizeof(str)-1))

// MEMO : �������x+�x�����o�邽��.h�Ŏ���.
// �������hash�ɂ���.
constexpr uint32_t CHash::GetDigest(const char* str, const size_t length)
{
    uint32_t digest = 0xffffffff;
    for (size_t i = 0; i < length; i++)
    {
        digest = (digest << 8) ^ s_crc32_table[((digest >> 24) ^ str[i]) & 0xff];
    }

    return digest;
}