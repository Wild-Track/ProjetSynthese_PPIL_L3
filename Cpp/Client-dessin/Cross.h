#pragma once

#include "Form.h"
#include "Vecteur2D.h"



class Cross: public Form
{
private:
	string _color;

public:
	Cross(Vecteur2D downLeft, Vecteur2D upRight, Vecteur2D downRight, Vecteur2D upLeft, string color);

	operator string();
};

