#pragma once

#include <iostream>
#include <string>
#include <vector>
#include "Vecteur2D.h"

using namespace std;

class Form
{
public:


	Vecteur2D& translationVector2D(Vecteur2D& v, const Vecteur2D& u) { v = v + u; return v; }
	Vecteur2D& rotationVector2D(Vecteur2D& v, const Vecteur2D& invariantPoint, const double& rad);
	Vecteur2D& homotetieVector2D(Vecteur2D& v, double ratio, const Vecteur2D& invariant);

	void translation(vector<Vecteur2D*> pointList, const Vecteur2D& u);
	void rotation(vector<Vecteur2D*> pointList, const Vecteur2D& invariantPoint, const double& rad);
	void homotetie(vector<Vecteur2D*> pointList, double ratio, const Vecteur2D& invariant);

};
