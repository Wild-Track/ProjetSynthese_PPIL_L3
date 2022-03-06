#pragma once

#include "FormVisitor.h"

//! @brief Classe du DP Visitor permettant de sauvegarder les formes 
//! 
//! Les formes sont dessiner sur le serveur Java et cette classe et independante des formes dans le cas ou il faut implementer d'autre librairies graphiques
class Savetxt : public FormVisitor
{
public:
	void visite(const FormGroup* form) const;
	void visite(const Circle* form) const;
	void visite(const Cross* form) const;
	void visite(const Segment* form) const;
	void visite(const Triangle* form) const;
	void visite(const polygon::Polygon* form) const;

	//! @brief Fonction qui va sauvegarder la forme dans un fichier
	//! @param data Forme sous forme string 
	//! @param name nom du fichier
	void saveOnFile(string data, string name) const;
};
