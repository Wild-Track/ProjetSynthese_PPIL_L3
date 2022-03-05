#include "Segment.h"
#include "FormVisitor.h"

Segment::Segment(Vecteur2D c1, Vecteur2D c2, string color): Form(color)
{
	_pointList.push_back(&c1);
	_pointList.push_back(&c2);
}

void Segment::accept(const FormVisitor* formVisitor)
{
	formVisitor->visite(this);
}

Segment::operator string() const
{
	return "type:segment,coord" + string(*_pointList[0]) + string(*_pointList[1]) + ((this->Form::getFormGroup() == NULL) ? ",color:" + this->Form::_color : "");
}