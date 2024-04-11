#pragma once
#include "文件操作.hpp"
#include <string>
#include <vector>
#include <iostream>

class 配置数据类 {
public:
    文件操作 文件;
    int 窗口大小x=400; int 窗口大小y=300;
    int 错误代码=0;
    bool 程序运行状态 = true;
    bool 游戏重开 = true;
    int 贴图大小=90;
    float 棋盘位置x=0;
    float 棋盘位置y=0;
    double 缩放倍数 = 1;
    int 显示单元格大小 = 90;
    int 棋盘显示方=1;//1正常,-1反转颜色
private:
    int stringToInt(const std::string& str) {
        try {
            return std::stoi(str);
        }
        catch (const std::invalid_argument& e) {
            std::cerr << "转换失败: 输入字符串 \"" << str << "\" 不是一个有效的整数" << std::endl;
            错误代码 = 1;
            throw;
        }
        catch (const std::out_of_range& e) {
            std::cerr << "转换失败: 输入字符串 \"" << str << "\" 超出了整数的表示范围" << std::endl;
            错误代码 = 2;
            throw;
        }
    }
    int 显示数据(std::vector<std::vector <std::string>>*数据) {
        for (std::vector <std::string> 行数据 : *数据) {
            for (std::string str : 行数据) {
                std::cout << "\t" << str ;
            }
            std::cout << std::endl;
        }
        return 0;
    }
public:
    int 加载配置数据(std::string str) {
        std::vector<std::vector <std::string>>配置文件 = 文件.读取文件按单词分行保存到字符串(str);
        显示数据(&配置文件);
        for (std::vector <std::string> 行数据:配置文件)
        {
            if (行数据[0] == "设置窗口大小xy") {
                if (行数据.size()>=3)
                {
                    窗口大小x = stringToInt(行数据[1]);
                    窗口大小y = stringToInt(行数据[2]);
                }
                else
                {
                    std::cerr << "设置窗口大小xy  参数不足" << std::endl;
                    错误代码 = 3;
                }
            }
            if (行数据[0] == "设置贴图大小") {
                if (行数据.size() >= 2)
                {
                    贴图大小 = stringToInt(行数据[1]);
                }
                else
                {
                    std::cerr << "设置贴图大小  参数不足" << std::endl;
                    错误代码 = 3;
                }
            }
            if (行数据[0] == "设置棋盘位置xy") {
                if (行数据.size() >= 3)
                {
                    棋盘位置x = stringToInt(行数据[1]) / 1000.0;
                    棋盘位置y = stringToInt(行数据[2]) / 1000.0;
                }
                else
                {
                    std::cerr << "设置棋盘位置xy  参数不足" << std::endl;
                    错误代码 = 3;
                }
            }
            if (行数据[0] == "设置棋盘显示方") {
                if (行数据.size() >= 2)
                {
                    棋盘显示方 = stringToInt(行数据[1]);
                }
                else
                {
                    std::cerr << "设置棋盘显示方  参数不足" << std::endl;
                    错误代码 = 3;
                }
            }
        }
            
        return 0;
    }
};
