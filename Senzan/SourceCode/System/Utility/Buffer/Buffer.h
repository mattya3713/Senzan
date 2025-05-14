// Buffer.h �V�[�����܂�����instance���Ăяo�������Ƃ��Ɏg�p.

#pragma once

#include <vector>
#include <memory>
#include "Any.h"

class Buffer
{
public:
    Buffer() = default;
    ~Buffer() = default;

    // �o�b�t�@��ǉ�.
    void AddBuffer(Any buffer);

    // �o�b�t�@����.
    void ClearBuffer();

    // �o�b�t�@�擾.
    const Any& GetBuffer(size_t index) const;

private:
    std::vector<Any> m_pBuffer;
};