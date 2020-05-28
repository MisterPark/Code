// ����
// �ؽ�Ʈ ������ �����ؿ���
//���� 
//1. �÷��̾�� ������ ü�� ���ݷ��̶� �����͸� ���´� (����ü ���)
//X2. ������ �����ϸ� �÷��̾��� ������ ���� (������ ���� ����
//X3. �÷��̾ �����ϸ� �÷��̾��� ������ ��� �����ش�. �޴��� ����͵� ����
//X4. �޴����� ������ �� �� �ִ� �ʱ� �߱� ���
//X5. �� ������ ���̵��� ���� �����ϴ� ���͸� �����Ѵ�
//X6. ���̵��� ���� ������ ������ �ɷ�ġ�� ���� �ٸ���. ���ʹ� �̸� ���ݷ� ü���� ���´�.
//X7. ���������� �÷��̾� ���� �Ӹ� �ƴ϶� ������ ������ ���� ����Ѵ�.
//X8. ���������� �޴��� 1. ���� 2.������ �ִ�
//X9. ������ �����ϸ� �÷��̾��� ü�°� ������ ü���� ���δ�. ���� ������ ��ŭ
//X10. ������ ü���� 0�� �Ǹ� ��� ����. �� �޴��� ���ư���
//X11. �÷��̾��� ü���� 0�� �Ǹ� ��� ����� �޴��� ���ư��� �� �÷��̾��� HP�� �ٽ� �ִ� HP�� ����������Ѵ�.

#include <iostream>
#include <vector>
#include <Windows.h>
#include "GameData.h"
#include "Screen.h"
#include "ConsoleCursor.h"
#include "ObjcetManager.h"

using namespace std;




//================================================
// ����
//================================================
Screen* screen = Screen::GetInstance();
bool isShutdown = false;

Player * player;
NPC* npc;
TextBox* textBar;

//================================================
// �Լ� �����
//================================================

void Initialize();
void FrameControl();
void Input();
void Render(); // ��� ������Ʈ �׸��� ���



//================================================
// ���� 
//================================================
int main()
{
	Initialize();

	for (;!isShutdown;)
	{
		FrameControl();
		Input();
		ObjectManager::Update();
		Render();
	}

	return 0;
}
//================================================
// �Լ� ���Ǻ�
//================================================
void Initialize()
{
	Screen::GetInstance();
	ConsoleCursor::Initialize();
	ObjectManager::GetInstance();

	// UI �׽�Ʈ
	
	//textBar = (TextBox*)ObjcetManager::CreateObject(ObjectType::TEXT_BOX);
	//textBar->EnqueueText("�̾��ϴ� �̰� �����ַ��� ��׷� ������.");

	player = (Player*)ObjectManager::CreateObject(ObjectType::PLAYER);
	npc = (NPC*)ObjectManager::CreateObject(ObjectType::NON_PLAYER_CHARACTER);

}

void FrameControl()
{
	Sleep(20);
}

void Input()
{
	if (GetAsyncKeyState(VK_ESCAPE) & 0x0001)
	{
		isShutdown = true;
	}
}

void Render()
{
	Screen::Clear();
	ObjectManager::Render();
	ConsoleCursor::Move(0, 0);
	Screen::Print();
}





