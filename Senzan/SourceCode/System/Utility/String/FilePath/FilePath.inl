#pragma once
#include "FilePath.h"

namespace MyFilePath {

    inline std::pair<std::string, std::string> SplitFileName(const std::string& Path, const char Splitter) 
    {
        // �Z�p���[�^�[�����̈ʒu��T��.
        auto Index = Path.find(Splitter);
        std::pair<std::string, std::string> SpliteFilePath;

        // �Z�p���[�^��������Ȃ��ꍇ�́A���̃p�X�Ƌ�̕������Ԃ�.
        if (Index == std::string::npos) {

            // �Z�p���[�^�ȑO�͌��̃p�X.
            SpliteFilePath.first = Path; 
            // �Z�p���[�^�ȍ~�͋�.
            SpliteFilePath.second = "";   

            return SpliteFilePath;
        }

        // �Z�p���[�^�ȑO���擾.
        SpliteFilePath.first = Path.substr(0, Index);

        // �Z�p���[�^�ȍ~���擾.
        SpliteFilePath.second = Path.substr(Index + 1, Path.length() - Index - 1);

        // ���������������Ԃ�.
        return SpliteFilePath;
    }

    inline std::string GetExtension(const std::string& path) {
        // ��납��u.�v��T��
        auto Index = path.rfind('.');

        // �g���q��������Ȃ��ꍇ.
        if (Index == std::string::npos) {
            // �󕶎����Ԃ�.
            return "";
        }

        // �g���q��Ԃ�
        return path.substr(Index + 1);
    }

    inline std::wstring GetExtension(const std::wstring& path) {
        // ��납��u.�v��T��
        auto Index = path.rfind(L'.');

        // �g���q��������Ȃ��ꍇ.
        if (Index == std::string::npos) {
            // �󕶎����Ԃ�.
            return L"";
        }

        // �g���q��Ԃ�
        return path.substr(Index + 1);
    }

    // ���f������̑��΃e�N�X�`���p�X���A�v�����猩���p�X���ɕϊ�,�擾����.
    inline std::string GetTexPath(const std::string& ModelPath, const char* TexPath) {
       
        // ���f���p�X�̍Ō�̃X���b�V���܂��̓o�b�N�X���b�V����T��.
        int pathIndex1 = static_cast<int>(ModelPath.rfind('/'));
        int pathIndex2 = static_cast<int>(ModelPath.rfind('\\'));
        int pathIndex = std::max(pathIndex1, pathIndex2);

        // ���f���p�X�̍Ōオ�X���b�V���łȂ��ꍇ.
        if (pathIndex == std::string::npos) {

            // �e�N�X�`���p�X��ǉ�.
            return ModelPath + TexPath;
        }

        // ���f���p�X����t�H���_�p�X���擾���A�e�N�X�`���p�X��ǉ�.
        auto folderPath = ModelPath.substr(0, pathIndex + 1);
        return folderPath + TexPath;
    }

    // �t�@�C���p�X�Ȃǂ�/��\\�ɕϊ�.
    void ReplaceSlashWithBackslash(std::string* Path)
    {
        // nullptr�`�F�b�N.
        if (Path == nullptr) { return; }

        for (char& c : *Path) {
            if (c == '/') {
                c = '\\';
            }
        }
    }
}
