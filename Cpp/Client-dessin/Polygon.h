#pragma once

#include "Form.h"

//! @brief Utilisation d'un namespace dedie car polygon rentre en conflit avec une librairie
namespace polygon
{
	//! @brief Classe d'un polygon quelconque fermer
	class Polygon : public Form
	{
	public:
		//! @brief Cette forme gere tout les polygon ferme avec une liste de point infini
		//! @param listpoint 
		Polygon(string id, vector<Vecteur2D*> listpoint, string color);

		operator string() const;

		void accept(const FormVisitor* formVisitor);

	};
}
