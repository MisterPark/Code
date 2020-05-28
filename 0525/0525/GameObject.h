#pragma once

struct GameObject
{
	virtual void Initialize() = 0;
	virtual void Render() = 0;
	virtual void Update() = 0;
	virtual void Event() = 0;

	void DrawSprite();
	void DrawSprite(char* src, int x, int y, int w, int h);

	int x = 0;
	int y = 0;
	char* shape = nullptr;
	int w = 0;
	int h = 0;
	bool isEnable = false;
	bool isVisible = false;
};

