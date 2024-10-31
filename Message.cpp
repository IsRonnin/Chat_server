#include "Message.h"


const shared_ptr<User> Message::getTo() const {
	return this->_to;
}

const shared_ptr<User> Message::getFrom() const {
	return this->_from;
}

const string& Message::getText() const {
	return this->_text;
}

const string& Message::getTime() const {
	return this->_time;
}

const string Message::Data_time() {
	char buffer[80];
	std::time_t timestamp = time(NULL);
	std::strftime(buffer, 80, "%H:%M:%S", localtime(&timestamp));
	std::string result = buffer;
	return result;
}

json Message::get_json() {
	json data = {
		{"from", this->_from->getName()},
		{"to", this->_to->getName()},
		{"time", this->_time},
		{"text", this->_text}
	};
	return data;
}