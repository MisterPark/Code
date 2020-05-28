#pragma once
#include "GameObject.h"

enum Job
{
	None = 0,
	Warrior,
	Wizard,
	Thief,
};

struct Player : public GameObject
{
	
	virtual void Initialize();
	virtual void Render();
	virtual void Update();
	virtual void Event();

	
	
	Job job = Job::None;
	int level = 0;
	int hp = 0;
	int maxHp = 0;
	int offense = 0;
	int defense = 0;

	char playerShape[3][4] =
	{
		{' ','(',')',' '},
		{'!','(',')','!'},
		{' ','!','!',' '},
	};
};

