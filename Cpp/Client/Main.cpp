#define _WINSOCK_DEPRECATED_NO_WARNINGS

#include <iostream>
#include <winsock2.h>
#include <sstream>
#include <ws2tcpip.h>

#include "Connection.h"

#pragma comment(lib,"ws2_32.lib")

#define L 200

using namespace std;

int main()
{
    char serverAdress[L];
    char msg[L];
    short serverPort;

    cout << "Entrez l'IP du serveur : " << endl;
    cin >> serverAdress;
    cout << "Entrez maintenant le port :" << endl;
    cin >> serverPort;

    Connection co = Connection(serverAdress, serverPort);

    cout << "Entrez un msg" << endl;
    cin >> msg;

    co.sendMsg(msg);
}
