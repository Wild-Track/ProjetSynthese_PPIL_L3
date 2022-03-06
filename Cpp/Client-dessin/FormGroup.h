#pragma once
#include "Form.h"

using namespace std;

//! @brief Classe gerant un groupe de forme
class FormGroup: public Form
{
private:
	//! @brief _formList est la liste qui contient toute les formes du groupes
	vector<Form*> _formList;
	string _name;

public:

	FormGroup(string id, string name, string color);

	//! @brief Ajoute une formes a la liste du groupe
	//! @param form Forme a ajouter
	void addForm(Form& form);
	//! @brief  Supprime une forme de la liste du groupe
	//! @param i index de l'element a supprimer
	void deleteForm(int i);

	//! @brief Redefinition de la fonction pour appeler celle de chaque forme  
	void translation(const Vecteur2D& u);
	//! @brief Redefinition de la fonction pour appeler celle de chaque forme 
	void rotation(const Vecteur2D& invariantPoint, const double& rad);
	//! @brief Redefinition de la fonction pour appeler celle de chaque forme 
	void homothety(double ratio, const Vecteur2D& invariant);


	bool operator ==(const FormGroup& group);
	operator string() const;

	void accept(const FormVisitor* formVisitor);


	vector<Form*> getFromList() const { return _formList; };
	string getName() const { return _name; };
};

