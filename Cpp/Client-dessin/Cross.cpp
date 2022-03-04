#define _CRT_SECURE_NO_WARNINGS

#include <sstream>
#include <string.h>
#include "Cross.h"


Cross::Cross(Vecteur2D downLeft, Vecteur2D upRight, Vecteur2D downRight, Vecteur2D upLeft, string color)
{
	_pointList.push_back(&downLeft);
	_pointList.push_back(&upRight);
	_pointList.push_back(&downRight);
	_pointList.push_back(&upLeft);

}

Cross::operator string()
{
	return "Cross:" + string(*_pointList[0]) + "," + string(*_pointList[1]) + "," + string(*_pointList[2]) + "," + string(*_pointList[3]) + ";" + _color;
}