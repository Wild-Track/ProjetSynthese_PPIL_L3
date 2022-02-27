#pragma once
#include "Form.h"

class Cross: public Form
{
private:
	double _left, _right, _up, _down;

public:
	Cross(double left, double right, double up, double down);

	void dessiner(Connection &co);
};

