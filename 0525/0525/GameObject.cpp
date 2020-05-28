#include "GameObject.h"
#include "Screen.h"



void GameObject::DrawSprite()
{
	Screen* screen = Screen::GetInstance();

	if (!isVisible) return;
	if (shape == nullptr) return;

	for (int row = 0, i = y; row < h; row++, i++)
	{
		if (i < 0) continue;
		if (i >= ConsoleH) continue;
		for (int col = 0, j = x; col < w; col++, j++)
		{
			if (j < 0) continue;
			if (j >= ConsoleW) continue;
			if (shape[row * w + col] == ' ') continue;
			screen->buffer[i][j] = shape[row * w + col];
		}
	}
}

void GameObject::DrawSprite(char* src, int x, int y, int w, int h)
{
	Screen* screen = Screen::GetInstance();

	if (src == nullptr) return;

	for (int row = 0, i = y; row < h; row++, i++)
	{
		for (int col = 0, j = x; col < w; col++, j++)
		{
			screen->buffer[i][j] = src[row * w + col];
		}
	}
}
