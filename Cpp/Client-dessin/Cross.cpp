#include <sstream>
#include <string.h>
#include "Cross.h"
#include "Connection.h"

Cross::Cross(double left, double right, double up, double down)
{
	_left = left;
	_right = right;
	_up = up;
	_down = down;
}

void Cross::dessiner(Connection &co)
{
	ostringstream ss;
	ss << "form:cross:{left:" << _left << ",right:" << _right << ",up:" << _up << ",down:" << _down << "}";
	string sstr;

	int lenght = sstr.length();
	char* request = (char*)malloc(sizeof(char) * lenght);

	strcpy_s(request, sstr.c_str());

	co.sendMsg(request);

	free(request);
}

extern ostream& operator <<(ostream& os, const Form& f)
{
	return os;
}