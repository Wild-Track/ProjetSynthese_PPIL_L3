#include "Circle.h"


Circle::Circle(Vecteur2D center, double radius, string color)
{
	_pointList.push_back(&center);
	_radius = radius;
	_color = color;
}

void Circle::homothety(double ratio, const Vecteur2D& invariant)
{
	Form::homothetyVector2D(*_pointList[0], ratio, invariant);
	_radius *= ratio;
}

Circle::operator string()
{
	return "Circle:" + string(*_pointList[0]) + ";" + to_string(_radius) + ";" + _color;
}