#include "Segment.h"

Segment::Segment(Vecteur2D c1, Vecteur2D c2, string color)
{
	_pointList.push_back(&c1);
	_pointList.push_back(&c2);
	_color = color;
}

Segment::operator string()
{
	return "segment:" + string(*_pointList[0]) + "," + string(*_pointList[1]) + ";" + _color;
}