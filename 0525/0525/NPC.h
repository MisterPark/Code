#pragma once
#include "GameObject.h"
class NPC :
	public GameObject
{
	virtual void Initialize();
	virtual void Render();
	virtual void Update();
	virtual void Event();

	char npcShape[3][4] =
	{
		{' ','<','>',' '},
		{'!','[',']','!'},
		{' ','!','!',' '},
	};
};

