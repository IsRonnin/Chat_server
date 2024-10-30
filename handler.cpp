#include "handler.h"

void handle_client(const int client_socket){
	json request = read_data(client_socket);

	close(client_socket);
}

json read_data(const int client_socket) {
	string recivied_data;
	char buffer[buffSize];
	int bytes_read = 0;
	if ((bytes_read = read(client_socket, buffer, buffSize)) > 0) {
		recivied_data.append(buffer, bytes_read);
		memset(buffer, 0, buffSize);
	}
	return json::parse(recivied_data);
}

void send_answer(const int client_socket, const json& data) {
	std::string json_str = data.dump();
	send(sock, json_str.c_str(), json_str.size(), 0);
}


bool regUser(vault& v, const json& data){
	string login = data.at("login"), password = data.at("password"), name = data.at("name");
	if (v.getUserByLogin(login) != nullptr) return false;
	v.addUser(login, password, name);
	return true;
}