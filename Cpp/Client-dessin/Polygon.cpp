#include "Polygon.h"
#include "FormVisitor.h"

using namespace polygon;

Polygon::Polygon(vector<Vecteur2D> listPoint, string color) : Form(color)
{
	copy(listPoint.begin(), listPoint.end(), _pointList);
}

Polygon::operator string() const
{
	string out = "type:polygon,coord:";
	for (Vecteur2D* point : _pointList)
	{
		out += string(*point);
	}
	out += ((this->Form::getFormGroup() == NULL) ? ",color:" + this->Form::_color : "");

	return out;
}

void Polygon::accept(const FormVisitor* formVisitor)
{
	formVisitor->visite(this);
}