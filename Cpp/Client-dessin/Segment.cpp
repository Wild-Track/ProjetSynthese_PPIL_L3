#include "Segment.h"

Segment::Segment(Vecteur2D& c1, Vecteur2D& c2, string color)
{
	_pointList.push_back(&c1);
	_pointList.push_back(&c2);
	_color = color;
}

void Segment::translation(const Vecteur2D& u)
{
	Form::translation(_pointList, u);
}

void Segment::rotation(const Vecteur2D& invariantPoint, const double& rad)
{
	Form::rotation(_pointList, invariantPoint, rad);
}

void Segment::homotetie(double ratio, const Vecteur2D& invariant)
{
	Form::homotetie(_pointList, ratio, invariant);
}

Segment::operator string()
{
	return "segment:" + string(*_pointList[0]) + "," + string(*_pointList[1]) + ";" + _color;
}