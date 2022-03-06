#pragma once

#include "Form.h"

//! @brief Classe Segment qui etend de form
class Segment : public Form
{
public:
	Segment(string id, Vecteur2D c1, Vecteur2D c2, string color);

	operator string() const;

	void accept(const FormVisitor* formVisitor);
};
