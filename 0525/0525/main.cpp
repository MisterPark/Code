// 숙제
// 텍스트 알피지 구현해오기
//조건 
//1. 플레이어는 직업과 체력 공격력이란 데이터를 갖는다 (구조체 사용)
//X2. 게임을 시작하면 플레이어의 직업을 고른다 (전ㄱ사 법사 도적
//X3. 플레이어를 생성하면 플레이어의 정보는 상시 보여준다. 메뉴든 사냥터든 어디든
//X4. 메뉴에서 던전을 고를 수 있다 초급 중급 고급
//X5. 각 던전별 난이도에 따라 등장하는 몬스터를 생성한다
//X6. 난이도에 따라 몬스터의 종류와 능력치는 각각 다르다. 몬스터는 이름 공격력 체력을 갖는다.
//X7. 던전에서는 플레이어 정보 뿐만 아니라 몬스터의 정보도 같이 출력한다.
//X8. 던전에서의 메뉴는 1. 공격 2.도망이 있다
//X9. 공격을 선택하면 플레이어의 체력과 몬스터의 체력이 깎인다. 각각 데미지 만큼
//X10. 몬스터의 체력이 0이 되면 사냥 성공. 후 메뉴로 돌아가기
//X11. 플레이어의 체력이 0이 되면 사망 출력후 메뉴로 돌아가기 단 플레이어의 HP는 다시 최대 HP로 만들어져야한다.

#include <iostream>
#include <vector>
#include <Windows.h>
#include "GameData.h"
#include "Screen.h"
#include "ConsoleCursor.h"
#include "ObjcetManager.h"
#include "Input.h"

using namespace std;




//================================================
// 전역
//================================================
bool isShutdown = false;

Player * player;
NPC* npc;
TextBox* textBar;

//================================================
// 함수 선언부
//================================================

void Initialize();
void FrameControl();
void Render(); // 모든 오브젝트 그리고 출력

//================================================
// 메인 
//================================================
int main()
{
	Initialize();

	for (;!isShutdown;)
	{
		FrameControl();
		Input::Update();
		ObjectManager::Update();
		Render();
	}

	return 0;
}
//================================================
// 함수 정의부
//================================================
void Initialize()
{
	Input::GetInstance();
	Screen::GetInstance();
	ConsoleCursor::Initialize();
	ObjectManager::GetInstance();
	TextBox::GetInstance();

	// UI 테스트
	
	//textBar = (TextBox*)ObjcetManager::CreateObject(ObjectType::TEXT_BOX);
	//textBar->EnqueueText("미안하다 이거 보여주려고 어그로 끌었다.");

	player = (Player*)ObjectManager::CreateObject(ObjectType::PLAYER);
	npc = (NPC*)ObjectManager::CreateObject(ObjectType::NON_PLAYER_CHARACTER);

}

void FrameControl()
{
	Sleep(20);
}


void Render()
{
	Screen::Clear();
	ObjectManager::Render();
	ConsoleCursor::Move(0, 0);
	Screen::Print();
}





