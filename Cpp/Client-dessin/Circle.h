#pragma once

#include "Form.h"
#include "Vecteur2D.h"


class Circle : public Form
{
private:
	double _radius;

public:
	Circle(string id, Vecteur2D center, double radius, string color);

	void homothety(double ratio, const Vecteur2D& invariant);
	
	operator string() const;

	void accept(const FormVisitor* formVisitor);

};
