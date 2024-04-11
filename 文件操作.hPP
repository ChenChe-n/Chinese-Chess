#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
class 文件操作{
public:
    std::vector<std::string> 分割字符串并去除空格(const std::string& 字符串) {
        std::vector<std::string> 结果;
        std::stringstream 流(字符串);
        std::string 词;
        while (流 >> 词) {
            // 去除词中的空格
            词.erase(std::remove_if(词.begin(), 词.end(), [](char c) { return std::isspace(c); }), 词.end());
            结果.push_back(词);
        }
        return 结果;
    }

    std::vector<std::vector <std::string>> 读取文件按单词分行保存到字符串(std::string 文件名) {
        std::vector<std::vector <std::string>> 输出;
        std::vector<std::vector <std::string>> 错误 = { {"error"} };
        // 打开文件
        std::ifstream 文件(文件名);
        // 检查文件是否成功打开
        if (!文件.is_open()) {
            std::cerr << "无法打开文件" << std::endl;
            return 错误;
        }

        std::string 行数据;
        // 逐行读取文件中的内容并按单词分开
        while (std::getline(文件, 行数据)) {
            // 打印读取的字符串
            //std::cout << line << std::endl;
            输出.push_back(分割字符串并去除空格(行数据));
        }

        // 关闭文件
        文件.close();

        return 输出;
    }
};