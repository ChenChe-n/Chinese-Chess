#pragma once
#include "�ļ�����.hpp"
#include <string>
#include <vector>
#include <iostream>

class ���������� {
public:
    �ļ����� �ļ�;
    int ���ڴ�Сx=400; int ���ڴ�Сy=300;
    int �������=0;
    bool ��������״̬ = true;
    bool ��Ϸ�ؿ� = true;
    int ��ͼ��С=90;
    float ����λ��x=0;
    float ����λ��y=0;
    double ���ű��� = 1;
    int ��ʾ��Ԫ���С = 90;
    int ������ʾ��=1;//1����,-1��ת��ɫ
private:
    int stringToInt(const std::string& str) {
        try {
            return std::stoi(str);
        }
        catch (const std::invalid_argument& e) {
            std::cerr << "ת��ʧ��: �����ַ��� \"" << str << "\" ����һ����Ч������" << std::endl;
            ������� = 1;
            throw;
        }
        catch (const std::out_of_range& e) {
            std::cerr << "ת��ʧ��: �����ַ��� \"" << str << "\" �����������ı�ʾ��Χ" << std::endl;
            ������� = 2;
            throw;
        }
    }
    int ��ʾ����(std::vector<std::vector <std::string>>*����) {
        for (std::vector <std::string> ������ : *����) {
            for (std::string str : ������) {
                std::cout << "\t" << str ;
            }
            std::cout << std::endl;
        }
        return 0;
    }
public:
    int ������������(std::string str) {
        std::vector<std::vector <std::string>>�����ļ� = �ļ�.��ȡ�ļ������ʷ��б��浽�ַ���(str);
        ��ʾ����(&�����ļ�);
        for (std::vector <std::string> ������:�����ļ�)
        {
            if (������[0] == "���ô��ڴ�Сxy") {
                if (������.size()>=3)
                {
                    ���ڴ�Сx = stringToInt(������[1]);
                    ���ڴ�Сy = stringToInt(������[2]);
                }
                else
                {
                    std::cerr << "���ô��ڴ�Сxy  ��������" << std::endl;
                    ������� = 3;
                }
            }
            if (������[0] == "������ͼ��С") {
                if (������.size() >= 2)
                {
                    ��ͼ��С = stringToInt(������[1]);
                }
                else
                {
                    std::cerr << "������ͼ��С  ��������" << std::endl;
                    ������� = 3;
                }
            }
            if (������[0] == "��������λ��xy") {
                if (������.size() >= 3)
                {
                    ����λ��x = stringToInt(������[1]) / 1000.0;
                    ����λ��y = stringToInt(������[2]) / 1000.0;
                }
                else
                {
                    std::cerr << "��������λ��xy  ��������" << std::endl;
                    ������� = 3;
                }
            }
            if (������[0] == "����������ʾ��") {
                if (������.size() >= 2)
                {
                    ������ʾ�� = stringToInt(������[1]);
                }
                else
                {
                    std::cerr << "����������ʾ��  ��������" << std::endl;
                    ������� = 3;
                }
            }
        }
            
        return 0;
    }
};
