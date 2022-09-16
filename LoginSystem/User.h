#ifndef CUSER_H
#define CUSER_H
#include <string>

class CUser
{
public:
	CUser(std::string newusername, std::string newpassword)
	{
		username = newusername;
		password = newpassword;
	}
	std::string username;
	std::string password;

};
#endif
