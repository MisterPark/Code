#include "ObjcetManager.h"


ObjectManager* manager = nullptr;

ObjectManager::ObjectManager()
{
}

ObjectManager::~ObjectManager()
{
}

ObjectManager * ObjectManager::GetInstance()
{
	if (manager == nullptr)
	{
		manager = new ObjectManager();
	}
	return manager;
}

void ObjectManager::Update()
{
	for (auto iter = manager->list.begin(); iter != manager->list.end(); ++iter)
	{
		(*iter)->Update();
	}
}

void ObjectManager::Render()
{
	for (auto iter = manager->list.begin(); iter != manager->list.end(); ++iter)
	{
		(*iter)->Render();
	}
}

GameObject * ObjectManager::CreateObject(ObjectType type)
{
	GameObject* go = nullptr;

	switch (type)
	{
	case PLAYER:
		go = new Player();
		break;
	case MONSTER:
		go = new Monster();
		break;
	case NON_PLAYER_CHARACTER:
		go = new NPC();
		break;
	case TEXT_BOX:
		go = new TextBox();
		break;
	default:
		return nullptr;
	}

	go->Initialize();

	manager->list.push_back(go);

	return go;
}

void ObjectManager::DeleteObject(GameObject * target)
{
	auto iter = manager->list.begin();
	for (; iter != manager->list.end(); ++iter)
	{
		if ((*iter) == target)
		{
			manager->list.erase(iter);
			break;
		}
	}

	delete target;
}

GameObject * ObjectManager::GetNearbyObject(GameObject * ref)
{
	vector<GameObject*> list = manager->list;
	
	bool isInvalidObject = false;

	auto iter = list.begin();
	for (; iter != list.end(); ++iter)
	{
		if ((*iter) != ref) continue;

		isInvalidObject = true;
		break;
	}

	if (!isInvalidObject) return nullptr;

	GameObject* target = nullptr;
	int offset = 2;

	iter = list.begin();
	for (; iter != list.end(); ++iter)
	{
		int x = (*iter)->x;
		int y = (*iter)->y;

		if ((*iter) == ref) continue;
		if (ref->x < x + offset) continue;
		if (ref->x > x - offset) continue;
		if (ref->y < y + offset) continue;
		if (ref->y > y - offset) continue;

		target = (*iter);
		return target;
	}

	return nullptr;
}
