#pragma once
#include <string>
class Form;

using namespace std;

class SaveParser {
public:
	/**
	@param s : donn�e du probl�me � r�soudre
	@return la form ou NULL
	*/
	virtual Form* findParser(const string& s) const = 0;
};