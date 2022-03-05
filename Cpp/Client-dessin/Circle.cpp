#include "Circle.h"
#include "FormVisitor.h"


Circle::Circle(Vecteur2D center, double radius, string color) : Form(color)
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
	return "Circle:" + string(*_pointList[0]) + ";" + to_string(_radius) + ((this->Form::getFormGroup() == NULL) ? ";" + this->Form::_color : "");
}

void Circle::accept(const FormVisitor* formVisitor)
{
	formVisitor->visite(this);
}
