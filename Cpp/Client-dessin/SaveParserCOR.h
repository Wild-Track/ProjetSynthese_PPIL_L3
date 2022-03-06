#pragma once
#include "SaveParser.h"

class SaveParserCOR : public SaveParser {
	SaveParserCOR* _suivant; // pointe sur le suivant

protected:
	SaveParserCOR(SaveParserCOR* suivant) : _suivant(suivant) {};
	virtual Form* Parser(const string& s) const = 0;

public:
	Form* findParser(const string& s) const;
};