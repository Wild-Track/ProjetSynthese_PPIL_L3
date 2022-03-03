#pragma once

#include <string>
#include <ostream>

using namespace std;

class Vecteur2D
{
public:
	double _x, _y;

	Vecteur2D(const double& x = 0, const double& y = 0);

	/**
	 * DONNEES : s respectant le format "(  nombre réel, nombre réel)"
	 *
	 * */
	//inline Vecteur2D(const char* s);
	Vecteur2D operator + (const Vecteur2D& u) const;
	Vecteur2D operator * (const double& a) const;
	/**
	 * - unaire (c'est-à- dire opposé d'un vecteur)
	 * */
	Vecteur2D operator - () const;

	operator string() const;

};
