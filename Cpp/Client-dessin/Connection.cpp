#define _WINSOCK_DEPRECATED_NO_WARNINGS
#include "Connection.h"

#include <string>
#include <iostream>
#include <winsock2.h>
#include <sstream>
#include <ws2tcpip.h>
#include "Error.h"

#pragma comment(lib,"ws2_32.lib")

constexpr int LENGHT = 200;

using namespace std;

Connection::Connection(string adress, int port)
{
    _adress = adress;
    _port = port;

    try
    {
        // Initialisation de la DLLWinSwok une seule fois dans le programme 
        WSADATA wsaData;

        int winSwok = WSAStartup(MAKEWORD(2, 0), &wsaData);

        if (winSwok) throw Error("L'initialisation à échoué");
    }
    catch (Error error)
    {
        cerr << error << endl;
    }

}

Connection* Connection::getInstance(string adress = "", int port = 0)
{
    if (_instance == NULL)
    {
        _instance = new Connection(adress, port);
    }
    return _instance;
}

SOCKET* Connection::createSocket()
{
    // Création du socket
    int familyAdress = AF_INET;    // IPv4
    int typeSocket = SOCK_STREAM;  // Mode TCP
    int protocole = IPPROTO_TCP;   // Protocole, on peut mettre 0 et la fct choisit le protocole en fct des 2 1ers paramètres

    SOCKET* sock = (SOCKET*)malloc(sizeof(SOCKET));
    *sock = socket(familyAdress, typeSocket, protocole);

    if (*sock == INVALID_SOCKET)
    {
        ostringstream oss;
        oss << "La création du socket à échoué : " << WSAGetLastError() << endl;

        throw Error(oss.str().c_str());
    }

    // Initialisation du socket


    SOCKADDR_IN sockAdress;  // Contient les information du serveur
    sockAdress.sin_family = AF_INET;
    sockAdress.sin_addr.s_addr = inet_addr(_adress.c_str());
    sockAdress.sin_port = htons(_port);  // Assure que le port est bien inscrit dans le format du réseau
                                         // Little/Big endian


    // Connexion au serveur
    int winSwok = connect(*sock, (SOCKADDR*)&sockAdress, sizeof(sockAdress));

    if (winSwok == SOCKET_ERROR) throw Error("La connexion à échoué : ");

    return sock;
}

void Connection::closeSocket(SOCKET* sock)
{
    int winSwok = shutdown(*sock, SD_BOTH);

    if (SOCKET_ERROR == 0) throw Error("La coupure de connexion à échoué");

    winSwok = closesocket(*sock);
    if (winSwok) throw Error("La fermeture du socket à echoué");

    free(sock);
}

void Connection::sendMsg(string msg, SOCKET* sock)
{
    try
    {
        msg += "\r\n";
        int l = msg.length();

        int winSwok = send(*sock, msg.c_str(), l, 0);

        if (winSwok == SOCKET_ERROR) throw Error("Echec de l'envoi de la requete ");

    }
    catch (Error error)
    {
        cerr << error << endl;
    }
}

void Connection::receiveMsg(string& response, SOCKET* sock)
{
    try 
    {
        char res[LENGHT];
        int winSwok = recv(*sock, res, LENGHT, 0);

        if (winSwok == SOCKET_ERROR) throw Error("La reception à échoué");

        char* p = strchr(res, '\n');
        *p = '\0';

        response = res;

        closeSocket(sock);

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
        WSACleanup();
    }
    catch (Error error)
    {
        cerr << error << endl;
    }
}