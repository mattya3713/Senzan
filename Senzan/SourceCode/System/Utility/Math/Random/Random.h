#pragma once
#include <random>
namespace MyRand
{
    inline int GetRandomPercentage(int Min,int Max)
    {
        static bool isInitialized = false;
        static std::random_device dev{};
        static std::mt19937 rnd{ dev() };
        static std::uniform_int_distribution dis{ Min, Max };

        if (isInitialized == false)
        {
            rnd.seed(static_cast<unsigned>(
                std::chrono::steady_clock::now().time_since_epoch().count()));
            isInitialized = true;
        }
        return dis(rnd);
    }

    inline float GetRandomPercentage(float Min, float Max)
    {
        static bool isInitialized = false;
        static std::random_device dev{};
        static std::mt19937 rnd{ dev() };
        static std::uniform_real_distribution<float> dis{ Min, Max };

        if (isInitialized == false)
        {
            rnd.seed(static_cast<unsigned>(
                std::chrono::steady_clock::now().time_since_epoch().count()));
            isInitialized = true;
        }
        return dis(rnd);
    }

    // �w�肵���l�������_���ŕԂ�.
    inline int GetRandomValue(const std::vector<int> values) {

        // ����������̃V�[�h�Ƃ��ė����f�o�C�X���g��.
        std::random_device rd;
        std::mt19937 gen(rd());

        // �����_���ȃC���f�b�N���쐬.
        std::uniform_int_distribution<> distrib(0, static_cast<int>(values.size()) - 1);

        return values[distrib(gen)];
    }
}