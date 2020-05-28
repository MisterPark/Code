#include "TextBox.h"
#include <iostream>
#include <Windows.h>
#include "GameData.h"
#include "Input.h"
#include "ObjcetManager.h"

TextBox* textBox = nullptr;

TextBox::TextBox()
{
	Initialize();
	ObjectManager::EnqueueObject(this);
}

TextBox::~TextBox()
{
}

void TextBox::Initialize()
{
	this->shape = (char*)chatFrame;
	this->w = 120;
	this->h = 10;
	this->y = 20;
	this->isEnable = false;
	this->isVisible = false;
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


	// 출력대기를 모두 출력했다면.
	if (strcmp(text, wait) == 0)
	{
		if (Input::GetKey(VK_SPACE))
		{
			char* str = nullptr;
			if (textQ.Dequeue(&str))
			{
				SetText(str);
			}
			else
			{
				memset(text, 0, 100);
				memset(wait, 0, 100);
				Hide();
			}
		}
		
		
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

TextBox* TextBox::GetInstance()
{
	if (textBox == nullptr)
	{
		textBox = new TextBox();
	}
	return textBox;
}

void TextBox::Show()
{
	textBox->isVisible = true;
	textBox->isEnable = true;
}

void TextBox::Show(const char* _text)
{
	textBox->isVisible = true;
	textBox->isEnable = true;
	textBox->SetText(_text);
}

void TextBox::Hide()
{
	textBox->isVisible = false;
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
