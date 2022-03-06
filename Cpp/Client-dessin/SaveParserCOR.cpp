#include "SaveParserCOR.h"

Form* SaveParserCOR::findParser(const string& s) const {
	Form* f = Parser(s); // on tente de r�soudre le probl�me avec ce convertisseur
	if (f != NULL)
		return f; // On a trouv�
	else {
		if (_suivant != NULL)
			return _suivant->findParser(s); // On passe au suivant
		else
			return NULL; // �chec car c'est le dernier de la liste
	}
}