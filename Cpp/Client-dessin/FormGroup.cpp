#include "FormGroup.h"
#include "FormVisitor.h"


FormGroup::FormGroup(string name, string color): Form(color)
{
	_name = name;
}

void FormGroup::addForm(Form& form)
{
	if (form.getFormGroup() == NULL)
	{
		_formList.push_back(&form);
		form.setFormGroup(this);
	}
}

void FormGroup::deleteForm(int i)
{
	Form* form = _formList[i];
	form->setFormGroup(NULL);
	_formList.erase(_formList.begin() + i);
}

void FormGroup::translation(const Vecteur2D& u)
{
	for (Form* form : _formList)
	{
		(*form).Form::translation(u);
	}
}

void FormGroup::rotation(const Vecteur2D& invariantPoint, const double& rad)
{
	for (Form* form : _formList)
	{
		(*form).Form::rotation(invariantPoint, rad);
	}
}

void FormGroup::homothety(double ratio, const Vecteur2D& invariant)
{
	for (Form* form : _formList)
	{
		(*form).Form::homothety(ratio, invariant);
	}
}

bool FormGroup::operator ==(const FormGroup& group)
{
	return group._color == _color && group._name == _name;
}

FormGroup::operator string() const
{
	string out = "groupform:";

	for (Form* form : _formList)
	{
		out += "{" + string(*form) + "}";
	}
	out += ",color:" + this->Form::_color + ",nom:" + _name;
	return out;
}

void FormGroup::accept(const FormVisitor* formVisitor)
{
	formVisitor->visite(this);
}