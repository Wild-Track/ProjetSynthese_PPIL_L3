#include "Segment.h"

Segment::Segment(Vecteur2D c1, Vecteur2D c2, string color): Form(color)
{
	_pointList.push_back(&c1);
	_pointList.push_back(&c2);
}

Segment::operator string() const
{
	return "segment:" + string(*_pointList[0]) + "," + string(*_pointList[1]) + ((this->Form::getFormGroup() == NULL) ? ";" + this->Form::_color : "") + "/";
}