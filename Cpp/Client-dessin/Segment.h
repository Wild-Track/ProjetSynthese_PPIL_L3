#pragma once

#include "Form.h"


class Segment : public Form
{
private:
	string _color;

public:
	Segment(Vecteur2D c1, Vecteur2D c2, string color);

	operator string();
};
