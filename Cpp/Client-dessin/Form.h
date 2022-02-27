#pragma once

#include <iostream>
#include "Connection.h"

using namespace std;

class Form
{
public:

	virtual void dessiner(Connection &co) const = 0;
	friend ostream& operator <<(ostream& os, const Form& f);
};

