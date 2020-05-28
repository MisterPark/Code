#pragma once

enum class KeyCode : int
{
	None =0,

};

class Input
{
private:
	Input();
	~Input();

public:
	static Input* GetInstance();
	static void Update();
	static void Clear();
	static bool GetKey(int vKey);


private:
	bool keys[256] = { 0, };

};

