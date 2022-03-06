#include "Circle.h"
#include "FormVisitor.h"


Circle::Circle(string id, Vecteur2D center, double radius, string color) : Form(id, color)
{
	_pointList.push_back(&center);
	_radius = radius;
}

void Circle::homothety(double ratio, const Vecteur2D& invariant)
{
	Form::homothetyVector2D(*_pointList[0], ratio, invariant);
	_radius = abs(_radius * ratio);
}

Circle::operator string() const
{
	return "type:circle,id:" + _id + ",coord:" + string(*_pointList[0]) + ",radius:" + to_string(_radius) + ",color:" + this->Form::_color;
}

void Circle::accept(const FormVisitor* formVisitor)
{
	formVisitor->visite(this);
}
