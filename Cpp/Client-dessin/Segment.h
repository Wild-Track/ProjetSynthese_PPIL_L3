#pragma once

#include "Form.h"


class Segment : public Form
{
public:
	Segment(Vecteur2D c1, Vecteur2D c2, string color);

	operator string() const;
};
