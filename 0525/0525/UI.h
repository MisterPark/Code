#pragma once
#include "GameObject.h"
#include "Queue.h"

using namespace std;


enum UI_TYPE
{
	
};

struct UI : public GameObject
{
	virtual void Initialize();
	virtual void Render();
	virtual void Update();
	virtual void Event();
	
};
