#pragma once

#include "Form.h"
#include "Vecteur2D.h"



class Circle : public Form
{
private:
	double _radius;
	string _color;

public:
	Circle(Vecteur2D center, double radius, string color);
	
	operator string();
};
