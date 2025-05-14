#pragma once

#include <memory>
#include <typeinfo>
#include <stdexcept>
#include <vector>

// �^�����N���X.

class Any
{
private:
    struct Base
    {
        virtual ~Base() = default;
        virtual std::unique_ptr<Base> Clone() const = 0; // �N���[�����쐬���鏃�����z�֐�.
        virtual const std::type_info& Type() const = 0;  // �^�����擾���鏃�����z�֐�.
    };

    // �l�^��ێ�����z���_�[.
    template<typename T>
    struct Holder : Base
    {
        Holder(T value) : value(std::move(value)) {}
        std::unique_ptr<Base> Clone() const override
        {
            return std::make_unique<Holder<T>>(*this);
        }
        const std::type_info& Type() const override
        {
            return typeid(T);
        }

        // ���ۂ̒l.
        T value; 
    };

    // ���|��ێ�����z���_�[.
    template<typename T>
    struct PtrHolder : Base
    {
        PtrHolder(T* value) : value(value) {}
        std::unique_ptr<Base> Clone() const override
        {
            return std::make_unique<PtrHolder<T>>(value);
        }
        const std::type_info& Type() const override
        {
            return typeid(T*);
        }

        // ���|�ŕێ����ꂽ�l.
        T* value;
    };

    // std::unique_ptr<T> ��ێ�����z���_�[.
    template<typename T>
    struct UniquePtrHolder : Base
    {
        UniquePtrHolder(std::unique_ptr<T> value) : value(std::move(value)) {}
        std::unique_ptr<Base> Clone() const override
        {
            return std::make_unique<UniquePtrHolder<T>>(std::make_unique<T>(*value));
        }
        const std::type_info& Type() const override
        {
            return typeid(std::unique_ptr<T>);
        }

        // std::unique_ptr �ŕێ����ꂽ�l.
        std::unique_ptr<T> value; 
    };

    // std::vector<std::unique_ptr<T>> ��ێ�����z���_�[.
    template<typename T>
    struct VectorUniquePtrHolder : Base
    {
        VectorUniquePtrHolder(std::vector<std::unique_ptr<T>> value) : value(std::move(value)) {}

        std::unique_ptr<Base> Clone() const override
        {
            std::vector<std::unique_ptr<T>> clonedValue;
            clonedValue.reserve(value.size());
            for (const auto& ptr : value)
            {
                clonedValue.push_back(std::make_unique<T>(*ptr));
            }
            return std::make_unique<VectorUniquePtrHolder<T>>(std::move(clonedValue));
        }

        const std::type_info& Type() const override
        {
            return typeid(std::vector<std::unique_ptr<T>>);
        }

        // std::vector<std::unique_ptr<T>> �ŕێ����ꂽ�l.
        std::vector<std::unique_ptr<T>> value;
    };

public:
    Any() = default;

    // �l�^���󂯎��R���X�g���N�^.
    template<typename T>
    Any(T value) : ptr(std::make_unique<Holder<T>>(std::move(value))) {}

    // ���|���󂯎��R���X�g���N�^.
    template<typename T>
    Any(T* value) : ptr(std::make_unique<PtrHolder<T>>(value)) {}

    // std::unique_ptr<T> ���󂯎��R���X�g���N�^.
    template<typename T>
    Any(std::unique_ptr<T> value) : ptr(std::make_unique<UniquePtrHolder<T>>(std::move(value))) {}

    // std::vector<std::unique_ptr<T>> ���󂯎��R���X�g���N�^.
    template<typename T>
    Any(std::vector<std::unique_ptr<T>> value) : ptr(std::make_unique<VectorUniquePtrHolder<T>>(std::move(value))) {}

    // �R�s�[�R���X�g���N�^.
    Any(const Any& other) : ptr(other.ptr ? other.ptr->Clone() : nullptr) {}

    // �R�s�[������Z�q.
    Any& operator=(const Any& other)
    {
        if (this != &other)
        {
            ptr = other.ptr ? other.ptr->Clone() : nullptr;
        }
        return *this;
    }

    // ���[�u�R���X�g���N�^.
    Any(Any&&) noexcept = default;
    // ���[�u������Z�q.
    Any& operator=(Any&&) noexcept = default;

    // �l�^���擾���邽�߂̃��\�b�h.
    template<typename T>
    T& Get() const
    {
        if (typeid(T) != ptr->Type())
        {
            throw std::bad_cast();
        }
        return static_cast<Holder<T>*>(ptr.get())->value;
    }

    // ���|���擾���邽�߂̃��\�b�h.
    template<typename T>
    T* GetPtr() const
    {
        if (typeid(T*) != ptr->Type())
        {
            throw std::bad_cast();
        }
        return static_cast<PtrHolder<T>*>(ptr.get())->value;
    }

    // std::unique_ptr<T> ���擾���邽�߂̃��\�b�h.
    template<typename T>
    std::unique_ptr<T>& GetUniquePtr() const
    {
        if (typeid(std::unique_ptr<T>) != ptr->Type())
        {
            throw std::bad_cast();
        }
        return static_cast<UniquePtrHolder<T>*>(ptr.get())->value;
    }

    // std::vector<std::unique_ptr<T>> ���擾���邽�߂̃��\�b�h.
    template<typename T>
    std::vector<std::unique_ptr<T>>& GetVector() const
    {
        if (typeid(std::vector<std::unique_ptr<T>>) != ptr->Type())
        {
            throw std::bad_cast();
        }
        return static_cast<VectorUniquePtrHolder<T>*>(ptr.get())->value;
    }

    // �k���|�C���^���ǂ����𔻒肷�郁�\�b�h.
    bool IsNull() const { return !ptr; } 

private:
    std::unique_ptr<Base> ptr; // ���N���X�̃|�C���^��ێ�.
};