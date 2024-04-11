#pragma once
#include <chrono>
#include <thread> 
#include <SFML/Graphics.hpp>
class 计时计数限制运行速度类
{
	std::chrono::high_resolution_clock::time_point 函数上次时间=std::chrono::high_resolution_clock::now();;
	std::chrono::high_resolution_clock::time_point 函数当前时间;
	std::chrono::high_resolution_clock::time_point 函数判断时间;


	std::chrono::high_resolution_clock::time_point 计时起始时间;
	std::chrono::high_resolution_clock::time_point 计时结束时间;
	std::chrono::high_resolution_clock::time_point 计时暂停时间;
	std::chrono::high_resolution_clock::time_point 计时继续时间;

	std::chrono::high_resolution_clock::time_point 时间偏移;

public:
	int 目标次数;
	const std::chrono::milliseconds 时间间隔{1000};
	int old计数=0;
	int 计数=0;


	void 开始计时() {
		计时起始时间 = std::chrono::high_resolution_clock::now();
	}
	void 结束计时() {
		计时结束时间 = std::chrono::high_resolution_clock::now();
	}
	void 暂停计时() {
		计时暂停时间 = std::chrono::high_resolution_clock::now();
	}
	void 继续计时() {
		计时继续时间 = std::chrono::high_resolution_clock::now();
		计时起始时间 += (计时继续时间 - 计时暂停时间);
	}
	int 每段时间运行次数() {
		计数++;
		if (函数判断时间 > std::chrono::high_resolution_clock::now() + 时间间隔)
		{
			函数判断时间 += +时间间隔;
			old计数 = 计数;
			计数 = 0;
		}
		return old计数;
	}
	int 控制每段时间运行次数() {
		计数++;
		if (函数判断时间 > std::chrono::high_resolution_clock::now() + 时间间隔)
		{
			函数判断时间 += +时间间隔;
			old计数 = 计数;
			计数 = 0;
		}
		return old计数;
	}
	std::chrono::duration<double> 结束计时并返回时间() {
		计时结束时间 = std::chrono::high_resolution_clock::now();
		return 计时结束时间 - 计时起始时间;
	}
	void 返回至上一次调用时间(std::string 提示)
	{
		函数上次时间 = 函数当前时间;
		函数当前时间 = std::chrono::high_resolution_clock::now();
		std::cout << 提示 << 函数当前时间 - 函数上次时间;
	}
};
class 判断鼠标在网格位置 {
public:
	sf::Vector2i 网格位置;
	bool 是否超出网格网格 = false;
	判断鼠标在网格位置(sf::Vector2i 鼠标位置, sf::Vector2f 网格左上角起始位置, sf::Vector2i 网格宽度) {
		sf::Vector2f 选择位置;
		选择位置.x = 鼠标位置.x - 网格左上角起始位置.x;
		选择位置.y = 鼠标位置.y - 网格左上角起始位置.y;

		网格位置.x = 选择位置.x / 网格宽度.x;
		网格位置.y = 选择位置.y / 网格宽度.y;
	}
	判断鼠标在网格位置(sf::Vector2i 鼠标位置, sf::Vector2f 网格左上角起始位置, sf::Vector2i 网格宽度,sf::Vector2i 网格大小) {
		sf::Vector2f 选择位置;
		选择位置.x = 鼠标位置.x - 网格左上角起始位置.x;
		选择位置.y = 鼠标位置.y - 网格左上角起始位置.y;
		if (选择位置.x < 0 or 选择位置.y < 0)
		{
			是否超出网格网格 = true;
		}
		
		网格位置.x = 选择位置.x / 网格宽度.x;
		网格位置.y = 选择位置.y / 网格宽度.y;

		if (网格位置.x > 网格大小.x - 1 or 网格位置.y > 网格大小.y - 1)
		{
			是否超出网格网格 = true;
		}
		
		//std::cout << "网格位置x:" << 网格位置.x << "\t网格位置y:" << 网格位置.y << "\n";
	}
};
class 判断选项 {

public:
	判断选项() {
	}
};
// 定义设置控制台光标位置的函数
void gotoxy(int x, int y) {
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}