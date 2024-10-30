#include "handler.h"

void handle_client(int client_socket){
	json request = read_data(client_socket);
	

	close(client_socket);
}

json read_data(int client_socket) {
	string recivied_data;
	char buffer[buffSize];
	int bytes_read = 0;
	if ((bytes_read = read(client_socket, buffer, buffSize)) > 0) {
		recivied_data.append(buffer, bytes_read);
		char command = buffer[0];
	}
	return json::parse(recivied_data);
}

bool regUser(const vault& v,const vector<string>& data){
	v.addUser(login, password, name);
	return false;
}