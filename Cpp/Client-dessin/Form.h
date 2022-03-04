#pragma once

#include <iostream>
#include <string>
#include <vector>
#include "Vecteur2D.h"

using namespace std;

class Form
{
protected:
	vector<Vecteur2D*> _pointList;

public:

	Vecteur2D& translationVector2D(Vecteur2D& v, const Vecteur2D& u) { v = v + u; return v; }
	Vecteur2D& rotationVector2D(Vecteur2D& v, const Vecteur2D& invariantPoint, const double& rad);
	Vecteur2D& homothetyVector2D(Vecteur2D& v, double ratio, const Vecteur2D& invariant);

	void translation(const Vecteur2D& u);
	void rotation(const Vecteur2D& invariantPoint, const double& rad);
	void homothety(double ratio, const Vecteur2D& invariant);

};
