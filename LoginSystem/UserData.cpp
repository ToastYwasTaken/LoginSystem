#include "UserData.h"
#include <filesystem>
#include <codecvt>
#include <sys/types.h>
#include<sys/stat.h>

void CUserData::AddUser(CUser user)
{
	std::ofstream outfile("test.txt");
	outfile << user.username << " - " << user.password << std::endl;
	outfile.close();
	std::cout << "Created new user " << user.username << "|" << user.password << std::endl;
}

void CUserData::CreateDir()
{
	std::cout << "Trying to create new directory: " << directory << std::endl;
	std::wstring_convert<std::codecvt_utf8_utf16<wchar_t>, wchar_t> converter;
	const std::wstring newDirAsWstring = converter.from_bytes(directory);
	const wchar_t* newDirAsWchar = newDirAsWstring.c_str();
	_wmkdir(newDirAsWchar);
	std::cout << "Created new directory: " << directory << std::endl;
}

bool CUserData::HasValidDir() 
{
	struct stat info;
	stat(directory, &info);
	return info.st_mode & S_IFDIR;
}
