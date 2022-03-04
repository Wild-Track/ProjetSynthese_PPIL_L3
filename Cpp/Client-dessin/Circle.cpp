#include "Circle.h"


Circle::Circle(Vecteur2D center, double radius, string color)
{
	_pointList.push_back(&center);
	_radius = radius;
	_color = color;
}

Circle::operator string()
{
	return "Circle:" + string(*_pointList[0]) + ";" + to_string(_radius) + ";" + _color;
}