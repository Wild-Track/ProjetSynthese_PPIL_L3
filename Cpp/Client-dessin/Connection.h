#pragma once


#include <iostream>
#include <winsock2.h>
#include <sstream>
#include <ws2tcpip.h>
#include "Error.h"

#pragma comment(lib,"ws2_32.lib")



class Connection
{
private:
	int _port;
	string _adress;
	static Connection* _instance;

	static bool _lib_init;
	Connection(string adress, int port);

public:

	static Connection* getInstance(string adress, int port);




	SOCKET* createSocket();
	void closeSocket(SOCKET* sock);

	void sendMsg(string msg, SOCKET* sock);
	void receiveMsg(string& msg, SOCKET* sock);

	virtual ~Connection();
};

