
/**
* @file Form.h
* @brief Classe mere de toutes les formes presentes
*/ 


#pragma once

#include <iostream>
#include <string>
#include <vector>
#include "Vecteur2D.h"

using namespace std;

class FormGroup;
class FormVisitor;

//! @brief Classe mere de toutes les formes presentes
class Form
{
protected:
	/// @brief _pointList contient les coordonnees de chaque formes
	vector<Vecteur2D*> _pointList;
	/// @brief contient le groupe auquel appartient la forme
	FormGroup* _group;
	string _color, _id;

public:

	/// @brief constructeur pour créer une forme
	/// 
	/// @pre L'id doit etre unique
	/// @param id  l'identifiant de la forme
	/// @param color  sa couleur
	/// 
	/// @details par defaut le groupe est NULL
	Form(string id, string color) { _group = NULL; _id = id; _color = color; };

	//! Fonction translation / rotation / homothety Vecteur2D effectue une operation sur un point en particulier

	Vecteur2D& translationVector2D(Vecteur2D& v, const Vecteur2D& u) { v = v + u; return v; }
	Vecteur2D& rotationVector2D(Vecteur2D& v, const Vecteur2D& invariantPoint, const double& rad);
	Vecteur2D& homothetyVector2D(Vecteur2D& v, double ratio, const Vecteur2D& invariant);


	//! Fonction virtual qui seront redefinis si besoin
	//! @param u Vecteur de translation
	virtual void translation(const Vecteur2D& u);
	//! Fonction virtual qui seront redefinis si besoin
	//! @param invariantPoint Point invariant sur lequelle on va effectuer la rotation
	//! @param rad angle de rotation
	virtual void rotation(const Vecteur2D& invariantPoint, const double& rad);
	//! Fonction virtual qui seront redéfinis si besoin
	//! @param ratio rapport du zoom
	//! @param invariant point a partir duquel on va effectuer le zoom
	virtual void homothety(double ratio, const Vecteur2D& invariant);

	virtual operator string() const = 0;

	//! Fonction virtual accept du DP visitor pour pouvoir utiliser differentes librairies graphiques ou meme sauvegarder
	virtual void accept(const FormVisitor* formVisitor) = 0;

	/// Getters & setters
	FormGroup* getFormGroup() const { return _group; }
	Form& setFormGroup(FormGroup* group) { _group = group; return *this; }
	string getColor() const { return _color; }
};
