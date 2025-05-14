
#include "Buffer.h"

// �o�b�t�@��ǉ�.
void Buffer::AddBuffer(Any buffer)
{
    m_pBuffer.push_back(std::move(buffer));
}

// �o�b�t�@����.
void Buffer::ClearBuffer()
{
    m_pBuffer.clear();
}

// �o�b�t�@�擾.
const Any& Buffer::GetBuffer(size_t index) const
{
    return m_pBuffer.at(index);
}