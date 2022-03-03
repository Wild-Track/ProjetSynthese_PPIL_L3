#pragma once

#include "Form.h"


class Segment : public Form
{
private:
	vector<Vecteur2D*> _pointList;
	string _color;

public:
	Segment(Vecteur2D& c1, Vecteur2D& c2, string color);

	void translation(const Vecteur2D& u);
	void rotation(const Vecteur2D& invariantPoint, const double& rad);
	void homotetie(double ratio, const Vecteur2D& invariant);

	operator string();
};
