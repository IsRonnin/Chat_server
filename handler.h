#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <cstring>
#include <string>
#include "vault.h"
#include "nlohmann/json.hpp"

using json = nlohmann::json;


#define buffSize 1024
using namespace std;

void handle_client(int client_socket);
json read_data(int client_socket);

bool regUser(vault& v, const json& data);
