#pragma once
#include "Math.h"

namespace MyMath {
    //-----------------
    // �N�����v : �l��͈͂Ɏ��߂�.

    // �ʏ�N�����v.
    template <typename T>
    static inline T Clamp(const T& Value, const T& Min, const T& Max) {
        return std::max(Min, std::min(Value, Max));
    }

    // ��Βl�N�����v.
    template <typename T>
    static inline T Clamp(const T& Value, const T& MaxAbs) {
        return std::max(MaxAbs * -1.f , std::min(Value, MaxAbs));
    }

    //-----------------
    // �l������(����)������.
    template<typename T>
    static inline void DecreaseToValue(T& Value, T Median, T Amount)
    {
        if (std::abs(Value - Median) <= Amount) 
        {
            Value = Median;
            return;
        }

        if (Value >= Median) 
        {
            Value -= Amount;
        }
        else 
        {
            Value += Amount;
        }
    }
}