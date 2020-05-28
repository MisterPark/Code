#pragma once

#define ConsoleW 120
#define ConsoleH 30


struct Screen
{
	static Screen* GetInstance();
	static void Initialize();
	static void Clear();
	static void Print();


	char buffer[ConsoleH][ConsoleW] = { 0, };
};

