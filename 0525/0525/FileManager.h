#pragma once
#include <iostream>

enum FileAccessType
{
	RB = 0,
	WB,
	AB,
	RT,
	WT,
	AT,
};

class FileManager
{
private:
	FileManager();
	~FileManager();

	const char* GetTypeString(FileAccessType type);
public:

	static FileManager* GetInstance();

	static bool MakeDirectory(const char* directory);
	static errno_t OpenFile(const char* directory, const char* fileName, FileAccessType type);
	static void CloseFile();

private:
	FILE* fp = nullptr;

};

