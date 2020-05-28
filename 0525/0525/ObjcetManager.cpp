#include "ObjcetManager.h"
#include "Input.h"

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
	// list를 순회하는 중에 push를 하게되면 iter가 터져버린다.
	// 그래서 waiting Queue에 생성할 Object를 넣어놓고
	// 다음 프레임에서 Update 호출시 waiting Queue에서 빼서
	// list에 push 한다.
	GameObject* go = nullptr;
	while (manager->waitingQueue.Dequeue(&go))
	{
		manager->list.push_back(go);
	}

	// 순회하며 Update
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
	case ObjectType::PLAYER:
		go = new Player();
		break;
	case ObjectType::MONSTER:
		go = new Monster();
		break;
	case ObjectType::NON_PLAYER_CHARACTER:
		go = new NPC();
		break;
	case ObjectType::TEXT_BOX:
		return TextBox::GetInstance();
	default:
		return nullptr;
	}

	go->Initialize();

	ObjectManager::EnqueueObject(go);

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

bool ObjectManager::FindObject(GameObject* target)
{
	auto iter = manager->list.begin();
	auto end = manager->list.end();
	for (; iter != end; ++iter)
	{
		if ((*iter) == target)
		{
			return true;
		}
	}
	return false;
}

void ObjectManager::EnqueueObject(GameObject* target)
{
	if (ObjectManager::FindObject(target)) return;

	manager->waitingQueue.Enqueue(target);

}

GameObject * ObjectManager::GetNearbyObject(GameObject * ref)
{

	if (!ObjectManager::FindObject(ref)) return nullptr;

	
	GameObject* target = nullptr;
	int offset = 2;
	auto iter = manager->list.begin();
	auto end = manager->list.end();

	for (; iter != end; ++iter)
	{
		int x = (*iter)->x;
		int y = (*iter)->y;

		if ((*iter) == ref) continue;
		if (ref->x > x + offset) continue;
		if (ref->x < x - offset) continue;
		if (ref->y > y + offset) continue;
		if (ref->y < y - offset) continue;

		target = (*iter);
		break;
	}

	return target;
}
