#pragma once

#include <iostream>
#include <string>
#include <vector>
#include "Vecteur2D.h"

using namespace std;

class FormGroup;

class Form
{
protected:
	vector<Vecteur2D*> _pointList;
	FormGroup* _group;
	string _color;

public:

	Form(string color) { _group = NULL; _color = color; };

	Vecteur2D& translationVector2D(Vecteur2D& v, const Vecteur2D& u) { v = v + u; return v; }
	Vecteur2D& rotationVector2D(Vecteur2D& v, const Vecteur2D& invariantPoint, const double& rad);
	Vecteur2D& homothetyVector2D(Vecteur2D& v, double ratio, const Vecteur2D& invariant);

	virtual void translation(const Vecteur2D& u);
	virtual void rotation(const Vecteur2D& invariantPoint, const double& rad);
	virtual void homothety(double ratio, const Vecteur2D& invariant);

	FormGroup* getFormGroup() const { return _group; }
	Form& setFormGroup(FormGroup* group) { _group = group; return *this; }

	virtual operator string() const = 0;
};
