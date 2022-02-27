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
	int _winSwok, _port;
	SOCKET _socket;
	char* _adress;

	static bool _lib_init;

public:
	Connection(char* adress, int port);
	void initConnection();
	void closeConnection();

	void sendMsg(char* msg);
	void receiveMsg(char *msg);

	int getWinSwok() { return _winSwok; };
	SOCKET getSocket() { return _socket; };
	static void setLibInit(bool b) { _lib_init = b; }

	virtual ~Connection();
};

