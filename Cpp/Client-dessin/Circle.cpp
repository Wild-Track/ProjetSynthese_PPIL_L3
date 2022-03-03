#include "Circle.h"


void Circle::translation(const Vecteur2D& u)
{
	Form::translationVector2D(*_center, u);
}

void Circle::rotation(const Vecteur2D& invariantPoint, const double& rad)
{
	Form::rotationVector2D(*_center, invariantPoint, rad);
}

void Circle::homotetie(double ratio, const Vecteur2D& invariant)
{
	Form::homotetieVector2D(*_center, ratio, invariant);
	_radius *= ratio;
}

Circle::operator string()
{
	return "Circle:" + string(*_center) + ";" + to_string(_radius) + ";" + _color;
}