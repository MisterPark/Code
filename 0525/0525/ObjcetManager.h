#pragma once
#include <vector>
#include "GameObject.h"
#include "Player.h"
#include "Monster.h"
#include "UI.h"
#include "TextBox.h"
#include "NPC.h"
#include "Queue.h"

using namespace std;

enum class ObjectType : char
{
	PLAYER,
	MONSTER,
	NON_PLAYER_CHARACTER,
	TEXT_BOX,

};

class ObjectManager
{
private:
	ObjectManager();
	~ObjectManager();

public:
	static ObjectManager* GetInstance();
	static void Update();
	static void Render();

	static GameObject* CreateObject(ObjectType type);
	static void DeleteObject(GameObject* target);
	static bool FindObject(GameObject* target);
	static void EnqueueObject(GameObject* target);

	static GameObject* GetNearbyObject(GameObject* ref);

private:
	vector<GameObject*> list;
	Queue<GameObject*> waitingQueue;
};

