#pragma once

#include "Form.h"
#include "Vecteur2D.h"



class Cross: public Form
{
private:
	vector<Vecteur2D*> _pointList;
	string _color;

public:
	Cross(Vecteur2D downLeft, Vecteur2D upRight, Vecteur2D downRight, Vecteur2D upLeft, string color);

	void translation(const Vecteur2D& u);
	void rotation(const Vecteur2D& invariantPoint, const double& rad);
	void homotetie(double ratio, const Vecteur2D& invariant);

	operator string();
};

