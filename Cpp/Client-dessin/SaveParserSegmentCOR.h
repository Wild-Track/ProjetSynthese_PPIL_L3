#pragma once

#include "Form.h"
#include "SaveParserCOR.h"
#include "Segment.h"

//! @brief Parser la forme : segment
class SaveParserSegmentCOR : public SaveParserCOR
{
public:
	/**
	* gère le format triangle pour les formes
	*/
	SaveParserSegmentCOR(SaveParserCOR* suivant);
	Segment* Parser(const string& s) const;
};

