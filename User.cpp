#include "User.h"

string const& User::getName() {
	return this->_name;
}
string const& User::getPassword() {
	return this->_password;
}
string const& User::getLogin() {
	return this->_login;
}

int User::checkNew() {
	return this->waiting.size();
}

shared_ptr<Message> User::getMessage() {
	shared_ptr<Message> message = this->waiting.front();
	this->waiting.pop();
	return message;
}

void User::set_name(const string& new_name) {
	this->_name = new_name;
}

void User::set_password(const string& new_password) {
	this->_password = new_password;
}
