#pragma once

#include "Form.h"
#include "Vecteur2D.h"

//! @brief Class cercle qui etend de forme
class Circle : public Form
{
private:
	double _radius;

public:
	Circle(string id, Vecteur2D center, double radius, string color);

	//! @brief Redefinition de la fonction a cause du rayon qui est a prendre en compte
	void homothety(double ratio, const Vecteur2D& invariant);
	
	operator string() const;

	void accept(const FormVisitor* formVisitor);

};
