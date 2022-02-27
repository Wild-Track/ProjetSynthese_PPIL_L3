#pragma once
#include <string>
#include <iostream>
using namespace std;


class Fraction
{
	int num;
	unsigned int den;
public:
	/**
	lance une exception de type Erreur si b == 0
	*/
	Fraction(const int& a, const int& b);
	int getNum() const;
	unsigned int getDen() const;
	operator string () const;
};

ostream& operator << (ostream& os, const Fraction& f);
