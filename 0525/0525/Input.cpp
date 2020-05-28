#include "Input.h"
#include <Windows.h>

Input* input;

Input::Input()
{

}

Input::~Input()
{
	delete input;
}

Input* Input::GetInstance()
{
	if (input == nullptr)
	{
		input = new Input();
	}
	

	return input;
}

void Input::Update()
{
	for (int i = 0; i < 256; i++)
	{
		if (GetAsyncKeyState(i))
		{
			input->keys[i] = true;
			continue;
		}

		input->keys[i] = false;
	}
	
}

void Input::Clear()
{
}

bool Input::GetKey(int vKey)
{
	return input->keys[vKey];
}
