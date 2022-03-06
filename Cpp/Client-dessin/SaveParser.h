#pragma once
#include <string>
class Form;

using namespace std;

class SaveParser {
public:
	/**
	@param s : donnée du problème à résoudre
	@return la form ou NULL
	*/
	virtual Form* findParser(const string& s) const = 0;
};