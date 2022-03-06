#pragma once


#include <iostream>
#include <winsock2.h>
#include <sstream>
#include <ws2tcpip.h>
#include "Error.h"

#pragma comment(lib,"ws2_32.lib")


//! @brief Class connection qui gere la connexion avec le serveur Java
//! C'est classe utilise le DP singleton pour le chargement de la librairie windows
class Connection
{
private:
	int _port;
	string _adress;
	static Connection* _instance;

	static bool _lib_init;
	Connection(string adress, int port);

public:
	
	//! @brief Permet de reccuperer l'instance unique de connection
	//! @param adress addresse IP du serveur
	//! @param port son port
	static Connection* getInstance(string adress, int port);


	SOCKET* createSocket();
	void closeSocket(SOCKET* sock);


	//! @brief Envoie un message au serveur
	//! @param msg la requete a envoyer
	//! @param sock le socket a utiliser
	void sendMsg(string msg, SOCKET* sock);

	//! @brief Recoit un message au serveur
	//! @param msg la requete a recevoir
	//! @param sock le socket a utiliser
	void receiveMsg(string& msg, SOCKET* sock);

	virtual ~Connection();
};

