#include "Polygon.h"
#include "FormVisitor.h"

polygon::Polygon::Polygon(string id, vector<Vecteur2D*> listPoint, string color) : Form(id, color)
{
	copy(listPoint.begin(), listPoint.end(), back_inserter(_pointList));
}

polygon::Polygon::operator string() const
{
	string out = "type:polygon,id:" + _id + ",coord:";
	for (Vecteur2D* point : _pointList)
	{
		out += string(*point);
	}
	out += ",color:" + this->Form::_color;

	return out;
}

void polygon::Polygon::accept(const FormVisitor* formVisitor)
{
	formVisitor->visite(this);
}