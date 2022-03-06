#pragma once

#include "Form.h"
#include "SaveParserCOR.h"
#include "Segment.h"

class SaveParserSegmentCOR : public SaveParserCOR
{
public:
	/**
	* g�re le format triangle pour les formes
	*/
	SaveParserSegmentCOR(SaveParserCOR* suivant);
	Segment* Parser(const string& s) const;
};

