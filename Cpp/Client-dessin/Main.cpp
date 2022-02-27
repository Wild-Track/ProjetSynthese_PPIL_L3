#define _WINSOCK_DEPRECATED_NO_WARNINGS

#include <iostream>
#include <winsock2.h>
#include <sstream>
#include <ws2tcpip.h>

#include "Connection.h"
#include "Form.h"
#include "Cross.h"

#pragma comment(lib,"ws2_32.lib")

#define L 200
#define adress "127.0.0.1"
#define port 6969

using namespace std;

int main()
{

    char serverAdress[L] = adress;
    char msg[L], *msg2 = (char *)malloc(sizeof(char) * L);
    short serverPort = port;

    //cout << "Entrez l'IP du serveur : " << endl;
    //cin >> serverAdress;
    //cout << "Entrez maintenant le port :" << endl;
    //cin >> serverPort;


    Connection co = Connection(serverAdress, serverPort);

    cout << "Entrez un msg" << endl;
    cin >> msg;

    co.sendMsg(msg);

    co.receiveMsg(msg2);

    cout << msg2 << endl;


    //

    Form* f1;
    f1 = new Cross(40, 40, 100, 100);
}
