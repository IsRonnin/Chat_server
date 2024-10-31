#include "vault.h"

const std::shared_ptr<User> vault::getUserByLogin(const std::string& login) const
{
	for (const std::shared_ptr<User>& i : this->_users) {
		if (i->getLogin() == login) return i;
	}
	return nullptr;
}

void vault::addUser(const std::string& login, const std::string& password, const std::string& name)
{
	this->_users.emplace_back(std::make_shared<User>(login, password, name));
}

void vault::addMessage(std::shared_ptr<User> to, std::shared_ptr<User> from, std::string& text)
{
	this->_messages.emplace_back(std::make_shared<Message>(to, from, text));
	to->addNewMessage(this->_messages.back());
}

bool vault::signIn(const string& login, const string& password) {
	shared_ptr<User> user = getUserByLogin(login);
	if (user == nullptr) return false;
	if (user->getPassword() != password) return false;
	return true;
}
bool vault::signUp(const string& login, const string& password, const string& name) {
	if (getUserByLogin(login) != nullptr) return false;
	addUser(login, password, name);
	return true;
}

void vault::changeUserName(const string& login, const& string newName);
void vault::changeUserPassword();

