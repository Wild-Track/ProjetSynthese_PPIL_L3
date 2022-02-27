#pragma once
#include <string>

using namespace std;

class Fraction;

class FractionParser
{
public:

	/**
	@param s : fraction à parser en string
	@return la fraction ou NULL en cas déchec
	*/
	virtual Fraction* FractionParse(const string& s);
};

