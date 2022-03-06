#include "Triangle.h"
#include "FormVisitor.h"

Triangle::Triangle(string id, Vecteur2D c1, Vecteur2D c2, Vecteur2D c3, string color) : Form(id, color)
{
	_pointList.push_back(&c1);
	_pointList.push_back(&c2);
	_pointList.push_back(&c3);
}

void Triangle::accept(const FormVisitor* formVisitor)
{
	formVisitor->visite(this);
}

Triangle::operator string() const 
{
	return "type:triangle,id:" + _id + ",coord:" + string(*_pointList[0]) + string(*_pointList[1]) + string(*_pointList[2]) + ((this->Form::getFormGroup() == NULL) ? ",color:" + this->Form::_color : "");
}
