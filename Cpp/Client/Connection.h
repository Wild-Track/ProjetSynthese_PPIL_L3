#pragma once


#include <iostream>
#include <winsock2.h>
#include <sstream>
#include <ws2tcpip.h>
#include "Error.h"

#pragma comment(lib,"ws2_32.lib")

#define L 200


using namespace std;


class Connection
{
private:
	int _winSwok;
	Socket _socket;

public:
	Connection(char *adress, int port);

	void sendMsg(char* msg);
	char *receiveMsg();

	int getWinSwok() { return _winSwok; };
	Socket getSocket() { return _socket; };

	virtual ~Connection();
};

