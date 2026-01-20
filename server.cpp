#include <iostream>
#include <thread.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <unistd.h>

class websocket
{
private:
	int socket;
	struct sockaddr_in *server_addr;

public:
	websocket() : socket(::socket(PF_INET, SOCK_DGRAM);) {
		server_addr->sin_family = AF_INET;
		server_addr->sin_addr.s_addr = htonl(INADDR_LOOPBACK);
		server_addr->sin_port = 0;
	}
	
	websocket(uint16_t p) : socket(::socket(PF_INET, SOCK_DGRAM);) {
		this->port(p);
		server_addr->sin_family = AF_INET;
		server_addr->sin_addr.s_addr = htonl(INADDR_LOOPBACK);
	}

	int port(uint16_t p) {
		if (p < 1024) {
			std::cout << "Invalid port number." << std::endl;
			return -1;
		}
		this->server_addr->sin_port = htons(p);
		return 0;
	}

	uint16_t get_port() { return this->server_addr.sin_port; }

	int web_connect() {
		if (this->server_addr->sin_port == 0) { 
			std::cout << "Connection port not set! Use port() method." << std::endl;
			return -1; 
		}
		::disconnectx(this->socket, SAE_ASSOCID_ANY, SAE_CONNID_ANY);
		if (::connect(this->socket, this->(const struct sockaddr*)server_addr, sizeof(*server_addr)) == -1) {
			std::cout << "Connection could not be established." << std::endl;
		}
		return 0;
	}
	
	ssize_t web_recv(char *buf, size_t length, int flags) {
	}
}

