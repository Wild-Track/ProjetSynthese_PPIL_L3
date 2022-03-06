#define _WINSOCK_DEPRECATED_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <winsock2.h>
#include <sstream>
#include <ws2tcpip.h>


#include "Connection.h"
#include "Cross.h"
#include "Segment.h"
#include "Triangle.h"
#include "Circle.h"
#include "FormGroup.h"
#include "Polygon.h"
#include "DrawJava.h"
#include "Savetxt.h"
#include "SaveParserCOR.h"
#include "SaveParser.h"
#include "SaveParserSegmentCOR.h"



Connection* Connection::_instance = NULL;

int main()
{

    //char serverAdress[LONGUEUR] = adress;
    //char msg[LONGUEUR], *msg2 = (char *)malloc(sizeof(char) * LONGUEUR);
    //short serverPort = port;

    //cout << "Entrez l'IP du serveur : " << endl;
    //cin >> serverAdress;
    //cout << "Entrez maintenant le port :" << endl;
    //cin >> serverPort;


  /*  Connection co = Connection(serverAdress, serverPort);

    cout << "Entrez un msg" << endl;
    cin >> msg;

    co.sendMsg(msg);

    co.receiveMsg(msg2);

    cout << msg2 << endl;
*/

    //

    //Cross* f1;
    //f1 = new Cross(Vecteur2D(1, 1), Vecteur2D(2, 2), Vecteur2D(2, 1), Vecteur2D(1, 2), "red");
    //f1->translation(Vecteur2D(1, 1));
    //cout << string(*f1);

    //Segment* s1;
    //s1 = new Segment(Vecteur2D(-1, -1), Vecteur2D(0, 0), "red");
    //s1->homothety(2, Vecteur2D(0, 0));

    //FormGroup a = FormGroup("name", "color");
    //a.addForm(*f1);

    //cout << string(a);


    Triangle* t1;
    t1 = new Triangle(Vecteur2D(1, 1), Vecteur2D(2, 2), Vecteur2D(2, 1), "red");

    //t1->accept(new DrawJava());
    t1->accept(new Savetxt());


    //ofstream file("txt.txt");

    //file.open("C:\\");
    //file << "fdsqfdsq" << "\n";
    //file.close();

    SaveParserCOR* a;
    a = new SaveParserSegmentCOR(NULL);
}
