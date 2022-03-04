#include "Form.h"
#include <math.h>

Vecteur2D& Form::rotationVector2D(Vecteur2D& v, const Vecteur2D& invariantPoint, const double& angle)
{
	double fsin = sin(angle);
	double fcos = cos(angle);

	//!
	//! Soustraction du point invarient sur le point (le point invarient devient donc l'origine
	//! Puis la rotation du point peut se faire
	//! Et rajout du point invarient au coordonnées
	//! 
	v._x -= invariantPoint._x;
	v._y -= invariantPoint._y;

	double newX = v._x * fcos - v._y * fsin;
	double newY = v._y * fcos + v._x * fsin;

	v._x = newX + invariantPoint._x;
	v._y = newY + invariantPoint._y;

	return v;
}

Vecteur2D& Form::homothetyVector2D(Vecteur2D& v, double ratio, const Vecteur2D& invariant)
{
	v._x = ((v._x - invariant._x) * ratio) + invariant._x;
	v._y = ((v._y - invariant._y) * ratio) + invariant._y;

	return v;
}


void Form::translation(const Vecteur2D& u)
{
	for (Vecteur2D* vector2D : _pointList)
	{
		translationVector2D(*vector2D, u);
	}
}

void Form::rotation(const Vecteur2D& invariantPoint, const double& rad)
{
	for (auto* vector2D : _pointList)
	{
		rotationVector2D(*vector2D, invariantPoint, rad);
	}
}

void Form::homothety(double ratio, const Vecteur2D& invariant)
{
	for (auto vector2D : _pointList)
	{
		homothetyVector2D(*vector2D, ratio, invariant);
	}
}