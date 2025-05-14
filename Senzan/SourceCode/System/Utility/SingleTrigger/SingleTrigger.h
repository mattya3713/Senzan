#pragma once

#include <functional>

/****************************
*	��񂾂�������ʂ��N���X.
*   �S��:���e����.
****/


class SingleTrigger
{
private:
    bool _triggered;

public:
    SingleTrigger() : _triggered(false) {}

    // Action.
    template<typename Once, typename ResetFunc>
    void CheckAndTrigger(Once OnceFunc, ResetFunc Reset)
    {
        if (!_triggered)
        {
            // �����𖞂������Ƃ��Ɏ��s���鏈��.
            _triggered = true;
            OnceFunc();
        }
        else if (_triggered == true && Reset())
        {
            // ���������Z�b�g���ꂽ��A�ēx���s�\�ɂ���.
            _triggered = false;
        }
    }
};