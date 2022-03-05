#pragma once

#include "Form.h"


class Triangle : public Form
{
public:
	Triangle(Vecteur2D c1, Vecteur2D c2, Vecteur2D c3, string color);

	operator string() const;

	void accept(const FormVisitor* formVisitor);
};
