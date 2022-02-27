#include <sstream>
#include "Erreur.h"
#include "Fraction.h"

/**
lance une exception de type Erreur si b == 0
*/
Fraction::Fraction(const int& a, const int& b)
{
	if (b == 0) throw Erreur("tentative de création d'une fraction de dénominateur nul");

	if (b > 0)
	{
		num = a; den = (unsigned int)b;
	}
	else
	{
		num = -a; den = (unsigned int)(-b);
	}
}

int Fraction::getNum() const
{
	return num;
}

unsigned int Fraction::getDen() const
{
	return den;
}

Fraction::operator string () const
{
	ostringstream oss;
	oss << num << "/" << den;
	return oss.str();
}

ostream& operator << (ostream& os, const Fraction& f)
{
	return os << (string)f;
}
