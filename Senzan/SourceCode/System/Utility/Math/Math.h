/****************************
*	�y�����Ɏ��͂�����n�̌v�Z.h.
*   �S��:���e ����
****/
#pragma once
#include <cmath>

namespace MyMath {
    //-----------------
    // �N�����v : �l��͈͂Ɏ��߂�.
    template <typename T>
    T Clamp(const T& Value, const T& Min, const T& Max);

    // ��Βl�N�����v.
    template <typename T>
    T Clamp(const T& Value, const T& MaxAbs);

    //-----------------
    // �l������(����)������.
    template<typename T>
    void DecreaseToValue(T& Value, T Median, T Amount);
}

#include "Math.inl" // �C�����C���������܂ރt�@�C�����C���N���[�h.