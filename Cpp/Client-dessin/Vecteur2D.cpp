#include "Vecteur2D.h"


inline const Vecteur2D operator *(const double& a, const Vecteur2D& u) { return u * a; }

//------------ implémentation des fonctions inline ----------------------

Vecteur2D::Vecteur2D(const double& x, const double& y)
{
	_x = x;
	_y = y;
}

Vecteur2D Vecteur2D::operator + (const Vecteur2D& u) const
{
	return Vecteur2D(_x + u._x, _y + u._y);
}

Vecteur2D Vecteur2D::operator * (const double& a) const
{
	return Vecteur2D(_x * a, _y * a);
}

Vecteur2D Vecteur2D::operator - () const
{
	return Vecteur2D(-_x, -_y);
}

Vecteur2D::operator string() const
{
	return "(" + to_string(int(rint(_x))) + "," + to_string(int(rint(_y))) + ")";
}

ostream& operator << (ostream& os, const Vecteur2D& u)
{
	os << (string)u;
	return os;
}
