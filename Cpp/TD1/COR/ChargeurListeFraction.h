#pragma once
#include <vector>
#include "Fraction.h"

using namespace std;

class ChargeurListeFraction
{
private:
	vector<Fraction> _listeFraction;

public:
	void charge(ifstream& fichier);
};

