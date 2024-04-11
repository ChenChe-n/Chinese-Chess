#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <windows.h>
#include "配置数据.hpp"
class 图像纹理类
{
public:
	std::string 图片目录 = "img/";
	std::string 贴图路径;
	sf::Texture 棋子;
	sf::Texture 棋盘;
	sf::Texture 棋格;
	int 设置图像纹理类(配置数据类 & 配置) {
		贴图路径.append(图片目录); 贴图路径.append("贴图"); 贴图路径.append(std::to_string(配置.贴图大小)); 贴图路径.append(".png");
		if (!棋子.loadFromFile(贴图路径)) {
			std::cout << 贴图路径 << std::endl;
			std::cout << "棋子贴图没有加载"<< std::endl;
		}
		贴图路径.clear();

		贴图路径.append(图片目录); 贴图路径.append("棋盘"); 贴图路径.append(std::to_string(配置.贴图大小)); 贴图路径.append(".png");
		if (!棋盘.loadFromFile(贴图路径)){
			std::cout << 贴图路径 << std::endl;
			std::cout << "棋盘贴图没有加载" << std::endl;
		}
		贴图路径.clear();

		贴图路径.append(图片目录); 贴图路径.append("棋格"); 贴图路径.append(std::to_string(配置.贴图大小)); 贴图路径.append(".png");
		if (!棋格.loadFromFile(贴图路径)){
			std::cout << 贴图路径 << std::endl;
			std::cout << "棋格贴图没有加载" << std::endl;
		}
		贴图路径.clear();
		return 0;
	}
};
class 精灵类
{
private:

public:
	sf::Sprite 精灵;
	精灵类() {
	};
	void 设置纹理(sf::Texture& 贴图) {
		精灵.setTexture(贴图);
	}
	void 设置区域纹理并单独保存(sf::Texture &贴图, sf::IntRect 贴图区域){
		精灵.setTexture(贴图);
		精灵.setTextureRect(贴图区域);
	}
	void 重新设置纹理大小() {

	}
	void 设置精灵位置(float x, float y) {
		精灵.setPosition(x,y);
	}
	void 设置精灵比例(float 显示比例) {
		精灵.setScale(显示比例, 显示比例);
	}
	void 设置精灵比例(float 显示X比例, float 显示Y比例) {
		精灵.setScale(显示X比例, 显示Y比例);
	}
};
class 显示类
{
public:
	图像纹理类 图像纹理;
	精灵类 棋子[2][7];
	精灵类 棋盘网格线;
	精灵类 背景;
	精灵类 选择框[2];
	精灵类 移动提示点;
	精灵类 吃棋提示点;
	显示类(配置数据类& 配置) {
		图像纹理.设置图像纹理类(配置);
		//加载棋子
		for (size_t y = 0; y < 2; y++)
		{
			for (size_t x = 0; x < 7; x++)
			{
				棋子[y][x].设置区域纹理并单独保存(图像纹理.棋子, sf::IntRect(配置.贴图大小 * x, 配置.贴图大小 * y, 配置.贴图大小, 配置.贴图大小));
				棋子[y][x].精灵.setScale(配置.缩放倍数, 配置.缩放倍数);
				//棋子[y][x].设置纹理(图像纹理.棋子);
				//棋子[y][x].设置纹理区域(sf::IntRect(配置.贴图大小 * x, 配置.贴图大小 * y, 配置.贴图大小, 配置.贴图大小));
				//棋子[y][x].设置精灵位置(x * 配置.贴图大小, y * 配置.贴图大小);
			}
		}
		选择框[0].设置区域纹理并单独保存(图像纹理.棋子, sf::IntRect(配置.贴图大小 * 0, 配置.贴图大小 * 2, 配置.贴图大小, 配置.贴图大小));
		选择框[0].精灵.setScale(配置.缩放倍数, 配置.缩放倍数);
		选择框[1].设置区域纹理并单独保存(图像纹理.棋子, sf::IntRect(配置.贴图大小 * 1, 配置.贴图大小 * 2, 配置.贴图大小, 配置.贴图大小));
		选择框[1].精灵.setScale(配置.缩放倍数, 配置.缩放倍数);

		棋盘网格线.设置纹理(图像纹理.棋格);
		棋盘网格线.设置精灵位置((配置.棋盘位置x-1)*配置.显示单元格大小 + 配置.显示单元格大小 / 2, (配置.棋盘位置y - 1) * 配置.显示单元格大小 + 配置.显示单元格大小 / 2);
		棋盘网格线.设置精灵比例(配置.缩放倍数, 配置.缩放倍数);

		背景.设置纹理(图像纹理.棋盘);
		sf::Vector2u 大小=图像纹理.棋盘.getSize();
		sf::Vector2f 显示大小 = { float(配置.窗口大小x) / 大小.x,float(配置.窗口大小y)/ 大小.y };
		背景.精灵.setScale(显示大小.x, 显示大小.y);

		移动提示点.设置区域纹理并单独保存(图像纹理.棋子, sf::IntRect(配置.贴图大小 * 2, 配置.贴图大小 * 2, 配置.贴图大小, 配置.贴图大小));
		移动提示点.精灵.setScale(配置.缩放倍数, 配置.缩放倍数);
		吃棋提示点.设置区域纹理并单独保存(图像纹理.棋子, sf::IntRect(配置.贴图大小 * 3, 配置.贴图大小 * 2, 配置.贴图大小, 配置.贴图大小));
		吃棋提示点.精灵.setScale(配置.缩放倍数, 配置.缩放倍数);
	}
private:

};