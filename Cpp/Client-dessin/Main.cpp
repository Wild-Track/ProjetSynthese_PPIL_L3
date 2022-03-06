#define _WINSOCK_DEPRECATED_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <winsock2.h>
#include <sstream>
#include <ws2tcpip.h>
#include <sstream>
#include <fstream>
#include <time.h>


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
#include "SaveParserTriangleCOR.h"



Connection* Connection::_instance = NULL;

int main()
{
    cout << "Création d'un croix : id : cross1, corrdonées : (1, 1)(2, 2)(2, 1)(1, 2), couleur : red" << endl;
    Cross* c1;
    c1 = new Cross("cross1", Vecteur2D(100, 100), Vecteur2D(200, 200), Vecteur2D(200, 100), Vecteur2D(100, 200), "red");
    cout << "forme sous forme string : " << string(*c1) << endl;

    cout << "translation de la croix" << endl;
    c1->translation(Vecteur2D(1, 1));
    cout << string(*c1) << endl;

    cout << "homothetie de la croix" << endl;
    c1->homothety(2, Vecteur2D(0, 0));
    cout << string(*c1) << endl;

    cout << "rotation de la croix" << endl;
    c1->rotation(Vecteur2D(100, 100), 3.14156 / 2);
    cout << string(*c1) << endl;

    cout << endl << "Création d'un groupe et ajout de la croix" << endl;
    FormGroup group = FormGroup("idgroup", "name", "color");
    group.addForm(*c1);

    cout << "group sous forme string : " << string(group) << endl;

    cout << endl << "création d'un triangle ayant pour id t1 et coordonnées (1,1) (2,2) (2,1) et couleur red" << endl;
    Triangle* t1;
    t1 = new Triangle("t1", Vecteur2D(100, 100), Vecteur2D(200, 200), Vecteur2D(200, 100), "red");

    cout << "envoie au serv du triangle" << endl;
    t1->accept(new DrawJava());

    cout << "Le serveur va recevoir : " << string(*t1) << endl;

    cout << "Sauvegarde du triangle dans un fichier txt dans le répertoire Save" << endl;
    t1->accept(new Savetxt());

    
    string wait;

    cout << endl << endl << "Appuyez sur q puis entrer pour quitter le programme" << endl;
    cin >> wait;


    // Mise en place de COR finit, il faut remplir les parser
    // 
    // 
    // 
    //SaveParserCOR* parserSegment, *parserTriangle;
    //parserSegment = new SaveParserSegmentCOR(NULL);
    //parserTriangle = new SaveParserTriangleCOR(parserSegment);

    //ifstream fichier("../Save/Triangle14-18-21.txt", ios::in);
    //if (fichier) {
    //    string ligne;
    //    getline(fichier, ligne);
    //    Form* form = parserTriangle->findParser(ligne);
    //    if (form == NULL)
    //    {
    //        cerr << "Impossible de parser !" << endl;
    //    }
    //}
    //else
    //    cerr << "Impossible d'ouvrir le fichier !" << endl;
}
