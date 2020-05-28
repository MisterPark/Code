#include "FileManager.h"
#include <direct.h>
#include <string>


FileManager* fm = nullptr;


FileManager::FileManager()
{
}

FileManager::~FileManager()
{
}

const char * FileManager::GetTypeString(FileAccessType type)
{
	switch (type)
	{
	case RB:
		return "rb";
	case WB:
		return "wb";
	case AB:
		return "ab";
	case RT:
		return "rt";
	case WT:
		return "wt";
	case AT:
		return "at";
	default:
		return "";
	}
	return nullptr;
}

FileManager * FileManager::GetInstance()
{
	if (fm == nullptr)
	{
		fm = new FileManager;
	}
	return fm;
}

bool FileManager::MakeDirectory(const char * directory)
{
	
	return false;
}

errno_t FileManager::OpenFile(const char * directory, const char * fileName, FileAccessType type)
{
	FileManager::CloseFile();
	FileManager::MakeDirectory(directory);

	std::string fullName = directory;
	fullName += fileName;

	errno_t err = fopen_s(&fm->fp, fullName.c_str(), fm->GetTypeString(type));

	return err;
}

void FileManager::CloseFile()
{
	if (fm->fp != nullptr)
	{
		fclose(fm->fp);
		fm->fp = nullptr;
	}
}
