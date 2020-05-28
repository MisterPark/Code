#pragma once
#include "GameObject.h"


class Character : public GameObject
{
protected:
	virtual void Initialize();
	virtual void Render();
	virtual void Update();

};

