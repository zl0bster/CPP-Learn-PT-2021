#pragma once
#include <windows.h>
enum Colors{ EMPTY = 0, RED = RGB(0xff, 0, 0), GREEN = RGB(0, 0xff, 0), BLUE = RGB(0, 0, 0xff), YELLOW= RGB(0xff, 0xff,0)
};
//const size_t rows = 10, columns = 10;
//��������� �������, ��������������� ��������� �����������

//������ �������� (����������� ���� demo.exe ������ ����������) ��� � ����� �������, ��� ��� ��, ��� functions.exe
void StartDemo();

//������� ������������ ����������� �������
void SetDimensions(int rows, int columns);

//������� �����
//void SetColor(Colors color);

//��������� �������
void DrawBalls(int* p, int rows, int columns);

//���������� ��������
void FinishDemo();

//�����
void pause(int ms);

