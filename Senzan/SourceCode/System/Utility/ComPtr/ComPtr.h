#pragma once
#include <wrl\\client.h>
#include <utility> // std::swap ���g�p���邽�߂ɃC���N���[�h

template <typename T>
class MyComPtr {
public:
    // �f�t�H���g�R���X�g���N�^.
    MyComPtr() : m_ptr(nullptr) {}

    // �|�C���^���󂯎��R���X�g���N�^.
    explicit MyComPtr(T* ptr) : m_ptr(ptr) {
        AddRef();
    }

    // �R�s�[�R���X�g���N�^.
    MyComPtr(const MyComPtr& other) : m_ptr(other.m_ptr) {
        AddRef();
    }

    // ���[�u�R���X�g���N�^.
    MyComPtr(MyComPtr&& other) noexcept : m_ptr(other.m_ptr) {
        other.m_ptr = nullptr; // �ړ����𖳌��ɂ���.
    }

    // �R�s�[������Z�q.
    MyComPtr& operator=(const MyComPtr& other) {
        if (this != &other) {
            Reset(); // ���݂̃|�C���^�����.
            m_ptr = other.m_ptr;
            AddRef();
        }
        return *this;
    }

    // ���[�u������Z�q.
    MyComPtr& operator=(MyComPtr&& other) noexcept {
        if (this != &other) {
            Reset(); // ���݂̃|�C���^�����.
            m_ptr = other.m_ptr;
            other.m_ptr = nullptr; // �ړ����𖳌��ɂ���.
        }
        return *this;
    }

    // �f�X�g���N�^.
    ~MyComPtr() {
        Reset();
    }

    // �����|�C���^�̎擾.
    T* Get() const { return m_ptr; }

    // �|�C���^�̃f���t�@�����X.
    T& operator*() const { return *m_ptr; }

    // �|�C���^�ւ̃A�N�Z�X.
    T* operator->() const { return m_ptr; }

    // �V�����|�C���^��ݒ肷��.
    void Reset(T* ptr = nullptr) {
        if (m_ptr) {
            m_ptr->Release();
        }

        m_ptr = ptr;

        if (m_ptr) {
            m_ptr->AddRef();
        }
    }

    // �|�C���^����������.
    void Swap(MyComPtr& other) noexcept {
        std::swap(m_ptr, other.m_ptr);
    }

    // �����|�C���^�̃A�h���X���擾����.
    T** GetAddressOf() {
        Reset();
        return &m_ptr;
    }

    // ���݂̃|�C���^��������A���̃A�h���X��Ԃ�.
    T** ReleaseAndGetAddressOf() {
        T** address = &m_ptr;
        Reset();
        return address;
    }

private:
    // COM �I�u�W�F�N�g�̎Q�ƃJ�E���g�𑝉�������.
    void AddRef() {
        if (m_ptr) {
            m_ptr->AddRef();
        }
    }

    T* m_ptr; // COM �I�u�W�F�N�g�̃|�C���^.
};
