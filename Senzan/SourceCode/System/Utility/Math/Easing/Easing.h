/****************************
* �C�[�W���O�֐����܂Ƃ߂��n.h.
* �S��:���e ����
****/
#pragma once

#include <cmath>
#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

namespace MyEasing {
    //-----------------
    // https://easings.net/ja
    // �`�[�g�V�[�g.

    enum class Type
    {
        Liner,
        InSine,
        OutSine,
        InOutSine,
        InQuad,
        OutQuad,
        InOutQuad,
        InCubic,
        OutCubic,
        InOutCubic,
        InQuart,
        OutQuart,
        InOutQuart,
        InQuint,
        OutQuint,
        InOutQuint,
        InExpo,
        OutExpo,
        InOutExpo,
        InCirc,
        OutCirc,
        InOutCirc,
        InBack,
        OutBack,
        InOutBack,
        InElastic,
        OutElastic,
        InOutElastic,
        InBounce,
        OutBounce,
        InOutBounce

    };

    /*******************************************
    * @brief  �Ή�����Easing�֐������s.
    * @param  Type     : Easing�̃^�C�v.
    * @param  Time     : �o�ߎ���(�t���[��).
    * @param  MaxTime  : �A�j���[�V�����ɂ����鎞��(�t���[��).
    * @param  Start    : �n�܂�̒l.
    * @param  End      : �I���̒l.
    * @return          : �X�V�����l.
    *******************************************/
    template<typename T>
    inline void UpdateEasing(Type Type, float Time, float MaxTime, T Start, T End, T& Out);
    /*******************************************
    * @brief  �Ή�����Easing�𕶎���Ƃ��ĕϊ�.
    * @return          : Easing�̖��O.
    *******************************************/
    inline const char* GetEasingTypeName(MyEasing::Type type);

    /*******************************************
    * @brief  ���������^��.
    * @param  Time     : �o�ߎ���(�t���[��).
    * @param  MaxTime  : �A�j���[�V�����ɂ����鎞��(�t���[��).
    * @param  Start    : �n�܂�̒l.
    * @param  End      : �I���̒l.
    * @param  Out       : ���܂����l.
    *******************************************/
    template<typename T>
    inline void Liner(float Time, float MaxTime, T Start, T End, T& Out);

    /*******************************************
    * @brief  �ŏ��͂������A�㔼�͑�����������.
    * @param  Time     : �o�ߎ���(�t���[��).
    * @param  MaxTime  : �A�j���[�V�����ɂ����鎞��(�t���[��).
    * @param  Start    : �n�܂�̒l.
    * @param  End      : �I���̒l.
    * @param  Out       : ���܂����l.
    *******************************************/
    template<typename T>
    inline void InSine(float Time, float MaxTime, T Start, T End, T& Out);

    /*******************************************
    * @brief  �ŏ��͑����A���X�Ɍ������I��肪�������ɂȂ�.
    * @param  Time     : �o�ߎ���(�t���[��).
    * @param  MaxTime  : �A�j���[�V�����ɂ����鎞��(�t���[��).
    * @param  Start    : �n�܂�̒l.
    * @param  End      : �I���̒l.
    * @param  Out       : ���܂����l.
    *******************************************/
    template<typename T>
    inline void OutSine(float Time, float MaxTime, T Start, T End, T& Out);

    /*******************************************
    * @brief  �n�߂ƏI��肪�������ŁA���Ԃ���������.
    * @param  Time     : �o�ߎ���(�t���[��).
    * @param  MaxTime  : �A�j���[�V�����ɂ����鎞��(�t���[��).
    * @param  Start    : �n�܂�̒l.
    * @param  End      : �I���̒l.
    * @param  Out       : ���܂����l.
    *******************************************/
    template<typename T>
    inline void InOutSine(float Time, float MaxTime, T Start, T End, T& Out);

    /*******************************************
    * @brief  �������Ȃ��瓮���A�ŏ��͒x���㔼�ŋ}���ɑ����Ȃ�.
    * @param  Time     : �o�ߎ���(�t���[��).
    * @param  MaxTime  : �A�j���[�V�����ɂ����鎞��(�t���[��).
    * @param  Start    : �n�܂�̒l.
    * @param  End      : �I���̒l.
    * @param  Out       : ���܂����l.
    *******************************************/
    template<typename T>
    inline void InQuad(float Time, float MaxTime, T Start, T End, T& Out);

    /*******************************************
    * @brief  �ŏ��͑����A�㔼�ŋ}���Ɍ�������.
    * @param  Time     : �o�ߎ���(�t���[��).
    * @param  MaxTime  : �A�j���[�V�����ɂ����鎞��(�t���[��).
    * @param  Start    : �n�܂�̒l.
    * @param  End      : �I���̒l.
    * @param  Out       : ���܂����l.
    *******************************************/
    template<typename T>
    inline void OutQuad(float Time, float MaxTime, T Start, T End, T& Out);

    /*******************************************
    * @brief  �ŏ��ƍŌ�ł�����肵�A���Ԃŋ}���ɓ���.
    * @param  Time     : �o�ߎ���(�t���[��).
    * @param  MaxTime  : �A�j���[�V�����ɂ����鎞��(�t���[��).
    * @param  Start    : �n�܂�̒l.
    * @param  End      : �I���̒l.
    * @param  Out       : ���܂����l.
    *******************************************/
    template<typename T>
    inline void InOutQuad(float Time, float MaxTime, T Start, T End, T& Out);

    /*******************************************
    * @brief  �ŏ��͔��ɂ������A�㔼�ŋ}���ɓ���.
    * @param  Time     : �o�ߎ���(�t���[��).
    * @param  MaxTime  : �A�j���[�V�����ɂ����鎞��(�t���[��).
    * @param  Start    : �n�܂�̒l.
    * @param  End      : �I���̒l.
    * @param  Out       : ���܂����l.
    *******************************************/
    template<typename T>
    inline void InCubic(float Time, float MaxTime, T Start, T End, T& Out);

    /*******************************************
    * @brief  �ŏ��ɋ}���ɓ����A�㔼�͂�����茸������.
    * @param  Time     : �o�ߎ���(�t���[��).
    * @param  MaxTime  : �A�j���[�V�����ɂ����鎞��(�t���[��).
    * @param  Start    : �n�܂�̒l.
    * @param  End      : �I���̒l.
    * @param  Out       : ���܂����l.
    *******************************************/
    template<typename T>
    inline void OutCubic(float Time, float MaxTime, T Start, T End, T& Out);

    /*******************************************
    * @brief  �n�߂ƏI���͂������ŁA���Ԃ͋}���ɓ���.
    * @param  Time     : �o�ߎ���(�t���[��).
    * @param  MaxTime  : �A�j���[�V�����ɂ����鎞��(�t���[��).
    * @param  Start    : �n�܂�̒l.
    * @param  End      : �I���̒l.
    * @param  Out       : ���܂����l.
    *******************************************/
    template<typename T>
    inline void InOutCubic(float Time, float MaxTime, T Start, T End, T& Out);

    /*******************************************
    * @brief  ���X�ɉ������A�I���ۂɋ}���ɓ���.
    * @param  Time     : �o�ߎ���(�t���[��).
    * @param  MaxTime  : �A�j���[�V�����ɂ����鎞��(�t���[��).
    * @param  Start    : �n�܂�̒l.
    * @param  End      : �I���̒l.
    * @param  Out       : ���܂����l.
    *******************************************/
    template<typename T>
    inline void InQuart(float Time, float MaxTime, T Start, T End, T& Out);

    /*******************************************
    * @brief  �ŏ��ɋ}���ɓ����A�㔼�͏��X�Ɍ�������.
    * @param  Time     : �o�ߎ���(�t���[��).
    * @param  MaxTime  : �A�j���[�V�����ɂ����鎞��(�t���[��).
    * @param  Start    : �n�܂�̒l.
    * @param  End      : �I���̒l.
    * @param  Out       : ���܂����l.
    *******************************************/
    template<typename T>
    inline void OutQuart(float Time, float MaxTime, T Start, T End, T& Out);

    /*******************************************
    * @brief  �ŏ��ƍŌオ�������ŁA���Ԃ����ɑ����Ȃ�.
    * @param  Time     : �o�ߎ���(�t���[��).
    * @param  MaxTime  : �A�j���[�V�����ɂ����鎞��(�t���[��).
    * @param  Start    : �n�܂�̒l.
    * @param  End      : �I���̒l.
    * @param  Out       : ���܂����l.
    *******************************************/
    template<typename T>
    inline void InOutQuart(float Time, float MaxTime, T Start, T End, T& Out);

    /*******************************************
    * @brief  �ŏ��͔��ɂ������A�㔼�ŋ}���ɉ�������.
    * @param  Time     : �o�ߎ���(�t���[��).
    * @param  MaxTime  : �A�j���[�V�����ɂ����鎞��(�t���[��).
    * @param  Start    : �n�܂�̒l.
    * @param  End      : �I���̒l.
    * @param  Out       : ���܂����l.
    *******************************************/
    template<typename T>
    inline void InQuint(float Time, float MaxTime, T Start, T End, T& Out);

    /*******************************************
    * @brief  �ŏ��ɋ}���ɓ����A�㔼�͔��ɂ������ɂȂ�.
    * @param  Time     : �o�ߎ���(�t���[��).
    * @param  MaxTime  : �A�j���[�V�����ɂ����鎞��(�t���[��).
    * @param  Start    : �n�܂�̒l.
    * @param  End      : �I���̒l.
    * @param  Out       : ���܂����l.
    *******************************************/
    template<typename T>
    inline void OutQuint(float Time, float MaxTime, T Start, T End, T& Out);

    /*******************************************
    * @brief  �n�߂ƏI���͂������ŁA���Ԃ͋}���ɓ���.
    * @param  Time     : �o�ߎ���(�t���[��).
    * @param  MaxTime  : �A�j���[�V�����ɂ����鎞��(�t���[��).
    * @param  Start    : �n�܂�̒l.
    * @param  End      : �I���̒l.
    * @param  Out       : ���܂����l.
    *******************************************/
    template<typename T>
    inline void InOutQuint(float Time, float MaxTime, T Start, T End, T& Out);

    /*******************************************
    * @brief  �ŏ��͂قƂ�Ǔ������A�㔼�ŋ}���ɓ����n�߂�.
    * @param  Time     : �o�ߎ���(�t���[��).
    * @param  MaxTime  : �A�j���[�V�����ɂ����鎞��(�t���[��).
    * @param  Start    : �n�܂�̒l.
    * @param  End      : �I���̒l.
    * @param  Out       : ���܂����l.
    *******************************************/
    template<typename T>
    inline void InExpo(float Time, float MaxTime, T Start, T End, T& Out);

    /*******************************************
    * @brief  �ŏ��ɋ}���ɓ����A�㔼�͋}���Ɍ�������.
    * @param  Time     : �o�ߎ���(�t���[��).
    * @param  MaxTime  : �A�j���[�V�����ɂ����鎞��(�t���[��).
    * @param  Start    : �n�܂�̒l.
    * @param  End      : �I���̒l.
    * @param  Out       : ���܂����l.
    *******************************************/
    template<typename T>
    inline void OutExpo(float Time, float MaxTime, T Start, T End, T& Out);

    /*******************************************
    * @brief  �n�߂ƏI��肪�������ŁA���Ԃ͋}���ɓ���.
    * @param  Time     : �o�ߎ���(�t���[��).
    * @param  MaxTime  : �A�j���[�V�����ɂ����鎞��(�t���[��).
    * @param  Start    : �n�܂�̒l.
    * @param  End      : �I���̒l.
    * @param  Out       : ���܂����l.
    *******************************************/
    template<typename T>
    inline void InOutExpo(float Time, float MaxTime, T Start, T End, T& Out);

    /*******************************************
    * @brief  �ŏ��͂�����蓮���A�㔼�͋}���ɉ������A�Ō�Ɍ�������.
    * @param  Time     : �o�ߎ���(�t���[��).
    * @param  MaxTime  : �A�j���[�V�����ɂ����鎞��(�t���[��).
    * @param  Start    : �n�܂�̒l.
    * @param  End      : �I���̒l.
    * @param  Out       : ���܂����l.
    *******************************************/
    template<typename T>
    inline void InCirc(float Time, float MaxTime, T Start, T End, T& Out);

    /*******************************************
    * @brief  �ŏ��ɋ}���ɓ����A�㔼�ł�����蓮��.
    * @param  Time     : �o�ߎ���(�t���[��).
    * @param  MaxTime  : �A�j���[�V�����ɂ����鎞��(�t���[��).
    * @param  Start    : �n�܂�̒l.
    * @param  End      : �I���̒l.
    * @param  Out       : ���܂����l.
    *******************************************/
    template<typename T>
    inline void OutCirc(float Time, float MaxTime, T Start, T End, T& Out);

    /*******************************************
    * @brief  �n�߂͂������A�㔼�͋}���ɉ������A�Ō�ɍĂь�������.
    * @param  Time     : �o�ߎ���(�t���[��).
    * @param  MaxTime  : �A�j���[�V�����ɂ����鎞��(�t���[��).
    * @param  Start    : �n�܂�̒l.
    * @param  End      : �I���̒l.
    * @param  Out       : ���܂����l.
    *******************************************/
    template<typename T>
    inline void InOutCirc(float Time, float MaxTime, T Start, T End, T& Out);

    /*******************************************
    * @brief  �n�߂ɓ��������Ȃ��A�㔼�ŋ}���ɓ����n�߂�A�Ăь�������.
    * @param  Time     : �o�ߎ���(�t���[��).
    * @param  MaxTime  : �A�j���[�V�����ɂ����鎞��(�t���[��).
    * @param  Start    : �n�܂�̒l.
    * @param  End      : �I���̒l.
    * @param  Out       : ���܂����l.
    *******************************************/
    template<typename T>
    inline void InBack(float Time, float MaxTime, T Start, T End, T& Out);

    /*******************************************
    * @brief  �n�߂͋}���ɓ����A�㔼�œ�������������.
    * @param  Time     : �o�ߎ���(�t���[��).
    * @param  MaxTime  : �A�j���[�V�����ɂ����鎞��(�t���[��).
    * @param  Start    : �n�܂�̒l.
    * @param  End      : �I���̒l.
    * @param  Out       : ���܂����l.
    *******************************************/
    template<typename T>
    inline void OutBack(float Time, float MaxTime, T Start, T End, T& Out);

    /*******************************************
    * @brief  �n�߂ƏI��肪�������ŁA���Ԃ��}���ɉ������A�Ō�ɍĂь�������.
    * @param  Time     : �o�ߎ���(�t���[��).
    * @param  MaxTime  : �A�j���[�V�����ɂ����鎞��(�t���[��).
    * @param  Start    : �n�܂�̒l.
    * @param  End      : �I���̒l.
    * @param  Out       : ���܂����l.
    *******************************************/
    template<typename T>
    inline void InOutBack(float Time, float MaxTime, T Start, T End, T& Out);

    /*******************************************
    * @brief  �ŏ��͏��������A�㔼�Œe�ނ悤�ȓ����ɂȂ�.
    * @param  Time     : �o�ߎ���(�t���[��).
    * @param  MaxTime  : �A�j���[�V�����ɂ����鎞��(�t���[��).
    * @param  Start    : �n�܂�̒l.
    * @param  End      : �I���̒l.
    * @param  Out       : ���܂����l.
    *******************************************/
    template<typename T>
    inline void InElastic(float Time, float MaxTime, T Start, T End, T& Out);

    /*******************************************
    * @brief  �ŏ��͋}���ɓ����A�㔼�Œe�ނ悤�ȓ����ɂȂ�.
    * @param  Time     : �o�ߎ���(�t���[��).
    * @param  MaxTime  : �A�j���[�V�����ɂ����鎞��(�t���[��).
    * @param  Start    : �n�܂�̒l.
    * @param  End      : �I���̒l.
    * @param  Out       : ���܂����l.
    *******************************************/
    template<typename T>
    inline void OutElastic(float Time, float MaxTime, T Start, T End, T& Out);

    /*******************************************
    * @brief  �n�߂͂������ŁA���ԂŒe�ނ悤�ȓ����ɂȂ�A�Ō�ɍĂт�����茸������.
    * @param  Time     : �o�ߎ���(�t���[��).
    * @param  MaxTime  : �A�j���[�V�����ɂ����鎞��(�t���[��).
    * @param  Start    : �n�܂�̒l.
    * @param  End      : �I���̒l.
    * @param  Out       : ���܂����l.
    *******************************************/
    template<typename T>
    inline void InOutElastic(float Time, float MaxTime, T Start, T End, T& Out);

    /*******************************************
    * @brief  �ŏ��͂قƂ�Ǔ������A�㔼�Œ��˂�悤�ȓ����ɂȂ�.
    * @param  Time     : �o�ߎ���(�t���[��).
    * @param  MaxTime  : �A�j���[�V�����ɂ����鎞��(�t���[��).
    * @param  Start    : �n�܂�̒l.
    * @param  End      : �I���̒l.
    * @param  Out       : ���܂����l.
    *******************************************/
    template<typename T>
    inline void InBounce(float Time, float MaxTime, T Start, T End, T& Out);

    /*******************************************
    * @brief  �ŏ��ɋ}���ɓ����A�㔼�Œ��˂�悤�ȓ����ɂȂ�.
    * @param  Time     : �o�ߎ���(�t���[��).
    * @param  MaxTime  : �A�j���[�V�����ɂ����鎞��(�t���[��).
    * @param  Start    : �n�܂�̒l.
    * @param  End      : �I���̒l.
    * @param  Out       : ���܂����l.
    *******************************************/
    template<typename T>
    inline void OutBounce(float Time, float MaxTime, T Start, T End, T& Out);

    /*******************************************
    * @brief  �n�߂ƏI��肪�������ŁA���Ԃ����˂�悤�ȓ����ɂȂ�.
    * @param  Time     : �o�ߎ���(�t���[��).
    * @param  MaxTime  : �A�j���[�V�����ɂ����鎞��(�t���[��).
    * @param  Start    : �n�܂�̒l.
    * @param  End      : �I���̒l.
    * @param  Out       : ���܂����l.
    *******************************************/
    template<typename T>
    inline void InOutBounce(float Time, float MaxTime, T Start, T End, T& Out);

}
#include "Easing.inl" 