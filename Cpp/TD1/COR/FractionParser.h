#pragma once
#include <string>

using namespace std;

class Fraction;

class FractionParser
{
public:

	/**
	@param s : fraction � parser en string
	@return la fraction ou NULL en cas d�chec
	*/
	virtual Fraction* FractionParse(const string& s);
};

