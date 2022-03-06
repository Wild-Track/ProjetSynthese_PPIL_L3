#include <sstream>
#include <string.h>
#include "Cross.h"
#include "FormVisitor.h"


Cross::Cross(string id, Vecteur2D downLeft, Vecteur2D upRight, Vecteur2D downRight, Vecteur2D upLeft, string color) : Form(id, color)
{
	_pointList.push_back(&downLeft);
	_pointList.push_back(&upRight);
	_pointList.push_back(&downRight);
	_pointList.push_back(&upLeft);
}

void Cross::accept(const FormVisitor* formVisitor) 
{
	formVisitor->visite(this);
}

Cross::operator string() const
{
	return "type:cross,id:" + _id + ",coord:" + string(*_pointList[0]) + string(*_pointList[1]) + string(*_pointList[2]) + string(*_pointList[3]) + ((this->Form::getFormGroup() == NULL) ? ",color:" + this->Form::_color : "");
}