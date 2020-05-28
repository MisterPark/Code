#include "Player.h"
#include "GameData.h"
#include <Windows.h>
#include "ObjcetManager.h"

void Player::Initialize()
{
	this->shape = (char*)playerShape;
	this->w = 4;
	this->h = 3;
	this->x = 3;
	this->y = 3;
	this->isEnable = true;
	this->isVisible = true;
}

void Player::Render()
{
	DrawSprite();
}

void Player::Update()
{
	if (GetAsyncKeyState(VK_UP) & 0x8001)
	{
		this->y--;
	}
	if (GetAsyncKeyState(VK_DOWN) & 0x8001)
	{
		this->y++;
	}
	if (GetAsyncKeyState(VK_RIGHT) & 0x8001)
	{
		this->x++;
	}
	if (GetAsyncKeyState(VK_LEFT) & 0x8001)
	{
		this->x--;
	}
	if (GetAsyncKeyState(VK_SPACE) & 0x0001)
	{
		GameObject* target = ObjectManager::GetNearbyObject(this);
		if (target != nullptr)
		{
			target->Event();
		}
	}
}

void Player::Event()
{
}

