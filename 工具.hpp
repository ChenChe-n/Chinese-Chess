#pragma once
#include <chrono>
#include <thread> 
#include <SFML/Graphics.hpp>
class ��ʱ�������������ٶ���
{
	std::chrono::high_resolution_clock::time_point �����ϴ�ʱ��=std::chrono::high_resolution_clock::now();;
	std::chrono::high_resolution_clock::time_point ������ǰʱ��;
	std::chrono::high_resolution_clock::time_point �����ж�ʱ��;


	std::chrono::high_resolution_clock::time_point ��ʱ��ʼʱ��;
	std::chrono::high_resolution_clock::time_point ��ʱ����ʱ��;
	std::chrono::high_resolution_clock::time_point ��ʱ��ͣʱ��;
	std::chrono::high_resolution_clock::time_point ��ʱ����ʱ��;

	std::chrono::high_resolution_clock::time_point ʱ��ƫ��;

public:
	int Ŀ�����;
	const std::chrono::milliseconds ʱ����{1000};
	int old����=0;
	int ����=0;


	void ��ʼ��ʱ() {
		��ʱ��ʼʱ�� = std::chrono::high_resolution_clock::now();
	}
	void ������ʱ() {
		��ʱ����ʱ�� = std::chrono::high_resolution_clock::now();
	}
	void ��ͣ��ʱ() {
		��ʱ��ͣʱ�� = std::chrono::high_resolution_clock::now();
	}
	void ������ʱ() {
		��ʱ����ʱ�� = std::chrono::high_resolution_clock::now();
		��ʱ��ʼʱ�� += (��ʱ����ʱ�� - ��ʱ��ͣʱ��);
	}
	int ÿ��ʱ�����д���() {
		����++;
		if (�����ж�ʱ�� > std::chrono::high_resolution_clock::now() + ʱ����)
		{
			�����ж�ʱ�� += +ʱ����;
			old���� = ����;
			���� = 0;
		}
		return old����;
	}
	int ����ÿ��ʱ�����д���() {
		����++;
		if (�����ж�ʱ�� > std::chrono::high_resolution_clock::now() + ʱ����)
		{
			�����ж�ʱ�� += +ʱ����;
			old���� = ����;
			���� = 0;
		}
		return old����;
	}
	std::chrono::duration<double> ������ʱ������ʱ��() {
		��ʱ����ʱ�� = std::chrono::high_resolution_clock::now();
		return ��ʱ����ʱ�� - ��ʱ��ʼʱ��;
	}
	void ��������һ�ε���ʱ��(std::string ��ʾ)
	{
		�����ϴ�ʱ�� = ������ǰʱ��;
		������ǰʱ�� = std::chrono::high_resolution_clock::now();
		std::cout << ��ʾ << ������ǰʱ�� - �����ϴ�ʱ��;
	}
};
class �ж����������λ�� {
public:
	sf::Vector2i ����λ��;
	bool �Ƿ񳬳��������� = false;
	�ж����������λ��(sf::Vector2i ���λ��, sf::Vector2f �������Ͻ���ʼλ��, sf::Vector2i ������) {
		sf::Vector2f ѡ��λ��;
		ѡ��λ��.x = ���λ��.x - �������Ͻ���ʼλ��.x;
		ѡ��λ��.y = ���λ��.y - �������Ͻ���ʼλ��.y;

		����λ��.x = ѡ��λ��.x / ������.x;
		����λ��.y = ѡ��λ��.y / ������.y;
	}
	�ж����������λ��(sf::Vector2i ���λ��, sf::Vector2f �������Ͻ���ʼλ��, sf::Vector2i ������,sf::Vector2i �����С) {
		sf::Vector2f ѡ��λ��;
		ѡ��λ��.x = ���λ��.x - �������Ͻ���ʼλ��.x;
		ѡ��λ��.y = ���λ��.y - �������Ͻ���ʼλ��.y;
		if (ѡ��λ��.x < 0 or ѡ��λ��.y < 0)
		{
			�Ƿ񳬳��������� = true;
		}
		
		����λ��.x = ѡ��λ��.x / ������.x;
		����λ��.y = ѡ��λ��.y / ������.y;

		if (����λ��.x > �����С.x - 1 or ����λ��.y > �����С.y - 1)
		{
			�Ƿ񳬳��������� = true;
		}
		
		//std::cout << "����λ��x:" << ����λ��.x << "\t����λ��y:" << ����λ��.y << "\n";
	}
};
class �ж�ѡ�� {

public:
	�ж�ѡ��() {
	}
};
// �������ÿ���̨���λ�õĺ���
void gotoxy(int x, int y) {
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}