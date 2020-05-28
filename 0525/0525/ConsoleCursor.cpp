#include "ConsoleCursor.h"
#include <Windows.h>

HANDLE hConsole;

void ConsoleCursor::Initialize()
{
	CONSOLE_CURSOR_INFO cci;

	cci.bVisible = false;
	cci.dwSize = 1;

	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorInfo(hConsole, &cci);
}

void ConsoleCursor::Move(int x, int y)
{
	COORD coord;
	coord.X = x;
	coord.Y = y;

	SetConsoleCursorPosition(hConsole, coord);
}
