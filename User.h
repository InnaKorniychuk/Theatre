#pragma once
#include <string>

//class that holds information about current logging user, as either ADMIN or GUEST

class User
{
public:
	User();//creates default user(GUEST type)
	void SetName(std::string name);//sets name for guest user
	bool AdminCheck(std::string password);//returns 1 if password is correct admin password
	std::string GetUsername();//returns current guest user name(returns "admin" in case of admin user)
	void MakeAdmin();//sets username "admin" and isAdmin=1
	bool IfAdmin();//returns 1 if current user is "admin"
private:
	void PasswordFail();//invoked if password check fails and makes you GUEST
	std::string username = "guest";
	std::string psswrd = "1234";
	bool isAdmin = 0;
};

