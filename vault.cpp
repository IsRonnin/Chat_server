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



