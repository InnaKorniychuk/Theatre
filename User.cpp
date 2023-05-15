#include "User.h"

User::User() {

}

void User::SetName(std::string name) {
	username = name;
}

bool User::AdminCheck(std::string password) {
	if (password == psswrd) {
		isAdmin = true;
		return true;
	}
	else {
		this->PasswordFail();
		return false;
	}
}

void User::PasswordFail() {
	this->SetName("guest");
}

std::string User::GetUsername() {
	return username;
}

void User::MakeAdmin() {
	SetName("admin");
	isAdmin = true;
}

bool User::IfAdmin() {
	return isAdmin;
}
