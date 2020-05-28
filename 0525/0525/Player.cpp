#include "Player.h"
#include "GameData.h"
#include <Windows.h>
#include "ObjcetManager.h"
#include "Input.h"

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
	if (Input::GetKey(VK_UP))
	{
		this->y--;
	}
	if (Input::GetKey(VK_DOWN))
	{
		this->y++;
	}
	if (Input::GetKey(VK_RIGHT))
	{
		this->x++;
	}
	if (Input::GetKey(VK_LEFT))
	{
		this->x--;
	}
	if (Input::GetKey(VK_SPACE))
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

