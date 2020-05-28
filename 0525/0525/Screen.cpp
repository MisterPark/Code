#include "Screen.h"
#include <iostream>

static Screen screen;

Screen* Screen::GetInstance()
{
	return &screen;
}

void Screen::Initialize()
{
	Clear();
}

void Screen::Clear()
{
	int i, j;
	for (i = 0; i < ConsoleH; i++)
	{
		for (j = 0; j < ConsoleW; j++)
		{
			if (j == ConsoleW - 1)
			{
				screen.buffer[i][j] = '\n';
			}

			screen.buffer[i][j] = ' ';
		}
	}
	screen.buffer[i-1][j-1] = 0;
}

void Screen::Print()
{
	printf("%s", screen.buffer);
}

