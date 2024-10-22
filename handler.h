#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <cstring>
#include <string>
#include <vault>
#define buffSize 1024
using namespace std;

void handle_client(int client_socket);

bool regUser(const string& data);

vector<string> to_vec(const char c[buffSize]);

vector<string> to_vec(const char c[buffSize], unsigned int count);
