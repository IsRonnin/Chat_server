#include "handler.h"

void handle_client(int client_socket){
	char buffer[buffSize];
	
	int bytes_read = read(client_socket, buffer, buffSize);
    	if (bytes_read > 0) {
        	char command = buffer[0];
		
    	
	}

	close(client_socket);
}

bool regUser(const vault& v,const vector<string>& data){
	v.addUser(login, password, name);
	return false;
}

vector<string> to_vec(const char c[buffSize]){
	string s(c);
	vector<string> splitted;

	while (s.find(":") != s.npos) {
		splitted.push_back(s.substr(0, s.find(":")));
		s.erase(0, s.find(":") + 1);
	}
	if (s.length() > 0) splitted.push_back(s);
	return splitted;
}

vector<string> to_vec(const char c[buffSize], unsigned int count) {
	string s(c);
	vector<string> splitted;

	while (s.find(":") != s.npos && count > 0) {
		splitted.push_back(s.substr(0, s.find(":")));
		s.erase(0, s.find(":") + 1);
		count -= 1;
	}

	if (s.length() > 0) splitted.push_back(s);

	return splitted;
}
