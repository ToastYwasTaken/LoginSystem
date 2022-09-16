#ifndef USERDATA_H
#define USERDATA_H
#include <list>
#include <iostream>
#include <fstream>
#include "User.h"

class CUserData
{
public:
	CUserData(){};
	std::list<CUserData> userDataList = {};
	void AddUser(CUser user);
	void CreateDir();
	bool HasValidDir();
private:
	const char* directory = "C:/Users/Franz Surface6Pro/OneDrive/Documents/Important_Own_Programs/c++/LoginSystem";
};
#endif

