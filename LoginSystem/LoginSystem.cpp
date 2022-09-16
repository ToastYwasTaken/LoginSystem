
#include <iostream>
#include <Windows.h>
#include <fstream>
#include <cstring>
#include "UserData.h"

namespace Input
{
	std::string inputUsername;
	std::string inputPassword;
}

CUserData userData;	
bool pressed1, pressed2, pressedESC;

#pragma region ForwardDeclarations
//LogIn
void LogIn();
bool isValidLoginData();
//new User
void CreateUser();
bool isValidPassword(std::string const& str);
bool isValidUsername(std::string const& str);
#pragma endregion

int main()
{
		bool pressed1;
		std::string inputUsername;

		do
		{
			pressed1 = GetKeyState(VK_F1) & 0x8000;
			if (pressed1) {
				std::cout << "\nPressed 'F1' enter username: ";
				std::cin >> inputUsername;
			}
		} while (!pressed1);
	//if (!userData.HasValidDir()) {
	//userData.CreateDir();
	//}
	//std::cout << "Welcome to the Login-Service\nLogin [1]\nRegister [2]\nPress 'Esc' any time to return/quit\n";
	//do
	//{
	//	pressed1 = GetKeyState('1') & 0x8000;
	//	if (pressed1) {
	//		std::cout << "Pressed '1' enter username: \n";
	//		std::cin >> Input::inputUsername;
	//	}
	//} while (!pressed1);
	//do
	//{
	//	pressed1 = GetKeyState('1') & 0x8000;
	//	pressed2 = GetKeyState('2') & 0x8000;
	//	pressedESC = GetKeyState(VK_ESCAPE) & 0x8000;
	//	if (pressed1) { LogIn(); return 0; }
	//	else if (pressed2) { CreateUser(); return 0; }
	//	else if (pressedESC) { std::cout << "exiting program..."; return 0; }
	//} while (!(pressed1 && pressed2)); //check if input valid
	std::cin;
	return 0;
}
/// <summary>
/// Check if username already exists
/// </summary>
/// <returns></returns>
bool isValidUsername(std::string const& str)
{
	int charCount = 0;
	auto stringToCheck = str.begin();
	while (stringToCheck != str.end()) {
		if (!std::isalnum) {
			std::cout << "username invalid, please only use alphanumeric characters, no special characters." << std::endl;
			return false;
		}
		else charCount++; stringToCheck++;
	}
	if (charCount > 15) {
		std::cout << "username invalid, should'nt be longer than 15 characters" << std::endl;
		return false;
	}
	return true;
}

/// <summary>
/// Checks the password for validity / has to fulfill security criteria
/// MUST contain at least: 1 upper char, 1 lower char, 1 number
/// </summary>
/// <param name="str"></param>
/// <returns>true if valid</returns>
bool isValidPassword(std::string const& str)
{
	int digitCount = 0, lowerCount = 0, upperCount = 0;
	auto stringToCheck = str.begin();
	while (stringToCheck != str.end()) {
		if (!std::isalnum) {
			std::cout << "password invalid, please only use alphanumeric characters, no special characters." << std::endl;
			return false;
		}
		if (std::isdigit(*stringToCheck)) {
			digitCount++;
		}
		else if (std::isupper(*stringToCheck)) {
			upperCount++;
		}
		else if (std::islower(*stringToCheck)) {
			lowerCount++;
		}
		stringToCheck++;
	}
	if (digitCount < 1) {
		std::cout << "password invalid, use at least 1 digit in your password." << std::endl;
		return false;
	}
	else if (lowerCount < 1) {
		std::cout << "password invalid, use at least 1 lower case character in your password." << std::endl;
		return false;
	}
	else if (upperCount < 1) {
		std::cout << "password invalid, use at least 1 upper case character in your password." << std::endl;
		return false;
	}
	else if ((digitCount + lowerCount + upperCount) < 7) {
		std::cout << "password invalid, must be longer than 6 digits" << std::endl;
		return false;
	}
	else if (str.empty() && stringToCheck != str.end()) {
		std::cout << "password invalid." << std::endl;
		return false;
	}else
	return !str.empty() && stringToCheck == str.end();
}

/// <summary>
/// Check if the Login Username and Password are correct
/// </summary>
/// <returns></returns>
bool isValidLoginData()
{
	return false;
}

/// <summary>
/// Trying to log in existing user
/// </summary>
void LogIn()
{

	FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE));
	std::cout << "Please enter your credentials: \n\n";
	do
	{
		std::cout << "Username: ";
		std::cin >> Input::inputUsername;
		std::cout << "Password: ";
		std::cin >> Input::inputPassword;
		if (isValidLoginData())
		{
			std::cout << "Login successful!";
			return;
		}
	} while (!isValidLoginData);
}

/// <summary>
/// Creating new user in data base
/// </summary>
void CreateUser()
{
	FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE));
	std::cout << "Creating new user, enter your desired credentials: \n\n";
	do
	{
		do
		{
			std::cout << "Enter username: ";
			std::cin.clear();
			std::cin >> Input::inputUsername;
		} while (!isValidUsername(Input::inputUsername));  //check if username valid
		do
		{
			std::cout << "Enter password: ";
			std::cin.clear();
			std::cin >> Input::inputPassword;

		} while (!isValidPassword(Input::inputPassword));  //check if password valid
		if (isValidUsername(Input::inputUsername) && isValidPassword(Input::inputPassword))
		{
			userData.AddUser(CUser(Input::inputUsername, Input::inputPassword));
		}
	} while (!(isValidUsername(Input::inputUsername) && isValidPassword(Input::inputPassword)));
}

