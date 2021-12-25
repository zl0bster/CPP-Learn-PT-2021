#include <Windows.h>

//------------------------------------------------------------------------------
// ��������� �������� � ��� ������� - ������ system("cls") 
//------------------------------------------------------------------------------
void setCursorPosition(int x, int y)
{
	static HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	static bool init = false;
	if (!init) {				// �������� ������
		CONSOLE_CURSOR_INFO structCursorInfo;
		GetConsoleCursorInfo(hConsole, &structCursorInfo);
		structCursorInfo.bVisible = FALSE;
		SetConsoleCursorInfo(hConsole, &structCursorInfo);
		init = true;
	}
	COORD position = { x, y }; // ������������� � ������ �������
	SetConsoleCursorPosition(hConsole, position);
}
//------------------------------------------------------------------------------
