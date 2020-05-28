#include "NPC.h"
#include "ObjcetManager.h"
#include "TextBox.h"

void NPC::Initialize()
{
	this->shape = (char*)npcShape;
	this->w = 4;
	this->h = 3;
	this->x = 30;
	this->y = 15;
	this->isEnable = true;
	this->isVisible = true;
}

void NPC::Render()
{
	DrawSprite();
}

void NPC::Update()
{
}

void NPC::Event()
{
	TextBox* textBox;
	textBox = (TextBox*)ObjectManager::CreateObject(ObjectType::TEXT_BOX);
	textBox->EnqueueText("미안하다 이거 보여주려고 어그로 끌었다.");

}
