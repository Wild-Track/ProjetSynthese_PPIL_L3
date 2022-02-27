#define _WINSOCK_DEPRECATED_NO_WARNINGS
#include "Connection.h"

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
    try
    {
        int WinSwok;
        WSADATA wsaData;

        // Initialisation de la DLL WinSwok
        WinSwok = WSAStartup(MAKEWORD(2, 0), &wsaData);

        if (WinSwok) throw Error("L'initialisation à échoué");

        // Création du socket
        SOCKET sock;
        int familyAdress = AF_INET;    // IPv4
        int typeSocket = SOCK_STREAM;  // Mode TCP
        int protocole = IPPROTO_TCP;   // Protocole, on peut mettre 0 et la fct choisit le protocole en fct des 2 1ers paramètres

        sock = socket(familyAdress, typeSocket, protocole);

        if (sock == INVALID_SOCKET)
        {
            ostringstream oss;
            oss << "La création du socket à échoué : " << WSAGetLastError() << endl;

            throw Error(oss.str().c_str());
        }

        // Initialisation du socket


        SOCKADDR_IN sockAdress;  // Contient les information du serveur
        sockAdress.sin_family = AF_INET;
        sockAdress.sin_addr.s_addr = inet_addr(adress);
        sockAdress.sin_port = htons(port);  // Assure que le port est bien inscrit dans le format du réseau
                                            // Little/Big endian


        // Connexion au serveur

        WinSwok = connect(sock, (SOCKADDR*)&sockAdress, sizeof(sockAdress));

        if (WinSwok == SOCKET_ERROR) throw Error("La connexion à échoué : ");

        cout << "Yeah connexion au serveur réussi" << endl;
    } catch (Error error)
    {
        cerr << error << endl;
    }

}

void Connection::sendMsg(char* msg)
{
    try 
    {
        strcat(msg, "\r\n");
        int l = strlen(msg);

        int WinSwok = send(this->getSocket(), msg, l, 0);

        if (WinSwok == SOCKET_ERROR) throw Error("Echec de l'envoi de la requete ");

        char response[L];
        WinSwok = recv(this->getSocket(), response, l, 0);

        if (WinSwok == SOCKET_ERROR) throw Error("La reception à échoué");

        char* p = strchr(response, '\n');
        *p = '\0';

        cout << response << endl;
    } catch (Error error)
    {
        cerr << error << endl;
    }


}

char* Connection::receiveMsg()
{
    return nullptr;
}

Connection::~Connection()
{
    try
    {
        int WinSwok = shutdown(this->getSocket(), SD_BOTH);

        if (WinSwok == SOCKET_ERROR) throw Error("La coupure de connexion à échoué");

        WinSwok = closesocket(this->getSocket());
        if (WinSwok) throw Error("La fermeture du socket à echoué");

        WSACleanup();

    }
    catch (Error error)
    {
        cerr << error << endl;
    }
}