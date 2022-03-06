#include "SaveParserCOR.h"

Form* SaveParserCOR::findParser(const string& s) const {
	Form* f = Parser(s); // on tente de résoudre le problème avec ce convertisseur
	if (f != NULL)
		return f; // On a trouvé
	else {
		if (_suivant != NULL)
			return _suivant->findParser(s); // On passe au suivant
		else
			return NULL; // échec car c'est le dernier de la liste
	}
}