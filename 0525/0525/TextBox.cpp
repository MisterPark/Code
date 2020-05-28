#include "TextBox.h"
#include <iostream>
#include <Windows.h>
#include "GameData.h"

void TextBox::Initialize()
{
	this->shape = (char*)chatFrame;
	this->w = 120;
	this->h = 10;
	this->y = 20;
	this->isEnable = true;
	this->isVisible = true;
}

void TextBox::Render()
{
	if (!isVisible) return;

	DrawSprite();
	DrawSprite(text, x + 2, y + 2, strlen(text), h);
}

void TextBox::Update()
{
	if (!isEnable) return;
	char* str = nullptr;
	if (GetAsyncKeyState(VK_SPACE) & 0x0001)
	{
		if (textQ.Dequeue(&str))
		{
			SetText(str);
		}
	}

	// 출력대기를 모두 출력했다면.
	if (strcmp(text, wait) == 0)
	{
		write = 0;
		return;
	}

	// 출력대기를 한글자씩 옮겨라
	memcpy(text, wait, write);
	count++;
	if (count >= delay)
	{
		write++;
		count = 0;
	}
}

void TextBox::Event()
{
}

void TextBox::EnqueueText(const char * _text)
{
	textQ.Enqueue((char*)_text);
}

void TextBox::SetText(const char * _text)
{
	memset(wait, 0, 100);
	unsigned int len = min(strlen(_text), 95);
	memcpy(wait, _text, len);
}

void TextBox::SetType(UI_TYPE type)
{
}
