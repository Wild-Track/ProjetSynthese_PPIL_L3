#define _WINSOCK_DEPRECATED_NO_WARNINGS
#include "Connection.h"

#include <string.h>
#include <iostream>
#include <winsock2.h>
#include <sstream>
#include <ws2tcpip.h>
#include "Error.h"

#pragma comment(lib,"ws2_32.lib")

#define L 200

using namespace std;

Connection::Connection(char* adress, int port)
{
    _winSwok = 0;
    _socket = 0;
    _adress = adress;
    _port = port;

    try
    {
        // Initialisation de la DLLWinSwok une seule fois dans le programme 
        if (_lib_init == false)
        {
            WSADATA wsaData;

            _winSwok = WSAStartup(MAKEWORD(2, 0), &wsaData);

            if (_winSwok) throw Error("L'initialisation � �chou�");

            _lib_init = true;
        }
    }
    catch (Error error)
    {
        cerr << error << endl;
    }

}

void Connection::initConnection()
{
    // Cr�ation du socket
    int familyAdress = AF_INET;    // IPv4
    int typeSocket = SOCK_STREAM;  // Mode TCP
    int protocole = IPPROTO_TCP;   // Protocole, on peut mettre 0 et la fct choisit le protocole en fct des 2 1ers param�tres

    _socket = socket(familyAdress, typeSocket, protocole);

    if (_socket == INVALID_SOCKET)
    {
        ostringstream oss;
        oss << "La cr�ation du socket � �chou� : " << WSAGetLastError() << endl;

        throw Error(oss.str().c_str());
    }

    // Initialisation du socket


    SOCKADDR_IN sockAdress;  // Contient les information du serveur
    sockAdress.sin_family = AF_INET;
    sockAdress.sin_addr.s_addr = inet_addr(_adress);
    sockAdress.sin_port = htons(_port);  // Assure que le port est bien inscrit dans le format du r�seau
                                        // Little/Big endian


    // Connexion au serveur
    _winSwok = connect(_socket, (SOCKADDR*)&sockAdress, sizeof(sockAdress));

    if (_winSwok == SOCKET_ERROR) throw Error("La connexion � �chou� : ");

    cout << "Yeah connexion au serveur r�ussi" << endl;
}

void Connection::closeConnection()
{
    _winSwok = shutdown(this->getSocket(), SD_BOTH);

    if (SOCKET_ERROR == 0) throw Error("La coupure de connexion � �chou�");

    _winSwok = closesocket(this->getSocket());
    if (_winSwok) throw Error("La fermeture du socket � echou�");
}

void Connection::sendMsg(char* msg)
{
    try
    {
        initConnection();

        strcat_s(msg, (size_t)L, "\r\n");
        int l = strlen(msg);

        _winSwok = send(this->getSocket(), msg, l, 0);

        if (_winSwok == SOCKET_ERROR) throw Error("Echec de l'envoi de la requete ");

    }
    catch (Error error)
    {
        cerr << error << endl;
    }
}

void Connection::receiveMsg(char *response)
{
    try 
    {
        _winSwok = recv(this->getSocket(), response, L, 0);

        if (_winSwok == SOCKET_ERROR) throw Error("La reception � �chou�");

        char* p = strchr(response, '\n');
        *p = '\0';

        closeConnection();

    }
    catch (Error error)
    {
        cerr << error << endl;
    }
}

Connection::~Connection()
{
    try
    {
        _winSwok = shutdown(this->getSocket(), SD_BOTH);

        if (_winSwok == SOCKET_ERROR) throw Error("La coupure de connexion � �chou�");

        _winSwok = closesocket(this->getSocket());
        if (_winSwok) throw Error("La fermeture du socket � echou�");

        WSACleanup();

    }
    catch (Error error)
    {
        cerr << error << endl;
    }
}

// Mise en place du bool�en servant � charger la lib avec WSAStartup qu'une seule fois
bool Connection::_lib_init = false;