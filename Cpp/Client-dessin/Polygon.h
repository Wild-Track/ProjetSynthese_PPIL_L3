#pragma once

#include "Form.h"

namespace polygon
{
	class Polygon : public Form
	{
	public:
		Polygon(vector<Vecteur2D> listpoint, string color);

		operator string() const;

		void accept(const FormVisitor* formVisitor);

	};
}
