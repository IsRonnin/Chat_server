#pragma once

#include<queue>
#include<string>
#include<memory>
#include"Message.h"
using namespace std;

string sha256(const string& input);

class User
{
	string _login;
	string _password;	
	string _name;
	queue<shared_ptr<Message>> waiting;

public:
	User(const string& login, const string& password, const string& name) : _login(login), _password(sha256(password)), _name(name) {};
	void set_name(const string& new_name);
	void set_password(const string& new_password);

	string const& getLogin();
	string const& getName();
	string const& getPassword();
	
	bool const& checkNew();
	string const& getMessage();
};
