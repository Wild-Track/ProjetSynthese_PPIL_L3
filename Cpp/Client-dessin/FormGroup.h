#pragma once
#include "Form.h"

using namespace std;

class FormGroup: public Form
{
private:
	vector<Form*> _formList;
	string _name;

public:

	FormGroup(string id, string name, string color);

	void addForm(Form& form);
	void deleteForm(int i);

	void translation(const Vecteur2D& u);
	void rotation(const Vecteur2D& invariantPoint, const double& rad);
	void homothety(double ratio, const Vecteur2D& invariant);


	bool operator ==(const FormGroup& group);
	operator string() const;

	void accept(const FormVisitor* formVisitor);


	vector<Form*> getFromList() const { return _formList; };
	string getName() const { return _name; };
};

