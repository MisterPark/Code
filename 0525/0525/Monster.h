#pragma once
#include "GameObject.h"


struct Monster : public GameObject
{
	virtual void Initialize();
	virtual void Render();
	virtual void Update();
	virtual void Event();


	char name[32] = { 0, };
	int hp = 0;
	int maxHp = 0;
	int offense = 0;
	int defense = 0;
};

