#pragma once

#include "Form.h"
#include "Vecteur2D.h"


//! @brief Classe croix qui etend de forme
class Cross: public Form
{
public:
	Cross(string id, Vecteur2D downLeft, Vecteur2D upRight, Vecteur2D downRight, Vecteur2D upLeft, string color);

	operator string() const;

	void accept(const FormVisitor* formVisitor);
};

