#pragma once
#include <string>
class Form;

using namespace std;

//! @brief Debut du DP Chain of responsability
class SaveParser {
public:
	/**
	@brief s'occupe de gerer les differents parser
	@param s : donnee du probleme à resoudre
	@return la form ou NULL
	*/
	virtual Form* findParser(const string& s) const = 0;
};