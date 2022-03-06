#pragma once

#include "Form.h"

//! @brief Classe triangle qui etend de form
class Triangle : public Form
{
public:
	Triangle(string id, Vecteur2D c1, Vecteur2D c2, Vecteur2D c3, string color);

	operator string() const;

	void accept(const FormVisitor* formVisitor);
};
