#pragma once

#include "FormVisitor.h"

//! @brief Classe du DP Visitor permettant de dessiner les formes 
//! 
//! Les formes sont dessiner sur le serveur Java et cette classe et independante des formes dans le cas ou il faut implementer d'autre librairies graphiques
class DrawJava : public FormVisitor
{
public:
	void visite(const FormGroup* form) const;
	void visite(const Circle* form) const;
	void visite(const Cross* form) const;
	void visite(const Segment* form) const;
	void visite(const Triangle* form) const;
	void visite(const polygon::Polygon* form) const;

	//! @brief Gere la requete a envoyer 
	//! @param data la requete
	void drawOnServer(string data) const;
};

