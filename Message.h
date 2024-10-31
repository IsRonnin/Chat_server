#pragma once

#include "User.h"
#include<ctime>
#include<memory>
#include<string>
#include "nlohmann/json.hpp"

using json = nlohmann::json;
using namespace std;

class User;

class Message
{
	const std::shared_ptr<User> _to;
	const std::shared_ptr<User> _from;
	const string _text;
	const string _time;

public:
	Message(shared_ptr<User> to, shared_ptr<User> from, const string& text):
	_to(to), _from(from), _text(text), _time(Data_time()) {};
	
	const shared_ptr<User> getTo() const;
	const shared_ptr<User> getFrom() const;
	const string& getText() const;
	const string& getTime() const;
	const string Data_time();
	json get_json();

};
