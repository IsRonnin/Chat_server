#pragma once
#include<memory>
#include<vector>
#include"Message.h"
#include"User.h"

using namespace std;

class vault{
	vector<shared_ptr<User>> _users;
	vector<shared_ptr<Message>> _messages;
public:
	const shared_ptr<User> getUserByLogin(const string& login) const;

	void addUser(const string& login, const string& password, const string& name);
	void addMessage(shared_ptr<User> to, shared_ptr<User> from, string& text);

	bool signIn(const string& login, const string& password);
	bool signUp(const string& login, const string& password, const string& name);

	void changeUserName();
	void changeUserPassword();
	
		
}
