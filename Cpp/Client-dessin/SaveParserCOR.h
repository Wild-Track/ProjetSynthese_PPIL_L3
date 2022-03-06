#pragma once
#include "SaveParser.h"

//! @brief Classe qui fait le lien entre les different parser (liste chainer)
class SaveParserCOR : public SaveParser {
	SaveParserCOR* _suivant; //! pointe sur le suivant

protected:
	SaveParserCOR(SaveParserCOR* suivant) : _suivant(suivant) {};
	//! @brief fonction virtual qui sera implementer par tous les parser 
	//! @param s ligne a parser 
	//! @return retourne une forme ou NULL
	virtual Form* Parser(const string& s) const = 0;

public:
	Form* findParser(const string& s) const;
};