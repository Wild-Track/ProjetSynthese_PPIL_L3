#pragma once

#include "Form.h"
#include "SaveParserCOR.h"
#include "Triangle.h"

//! @brief Parser pour la forme triangle
class SaveParserTriangleCOR : public SaveParserCOR
{
public:
	/**
	* gère le format triangle pour les formes
	*/
	SaveParserTriangleCOR(SaveParserCOR* suivant);
	Form* Parser(const string& s) const;
};

