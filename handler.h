#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <cstring>
#include <string>
#include "vault.h"

#define buffSize 1024
using namespace std;

void handle_client(int client_socket);

bool regUser(const vault& v, const vector<string>& data);

vector<string> to_vec(const char c[buffSize]);

vector<string> to_vec(const char c[buffSize], unsigned int count);
