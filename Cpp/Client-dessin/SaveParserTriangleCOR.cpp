#define _CRT_SECURE_NO_WARNINGS

#include "SaveParserTriangleCOR.h"
#include <sstream>


SaveParserTriangleCOR::SaveParserTriangleCOR(SaveParserCOR* suivant) : SaveParserCOR(suivant) {}

Form* SaveParserTriangleCOR::Parser(const string& s) const
{
	char type[8];
	char color[20];
	int x1, y1, x2, y2, x3, y3;

	try
	{
		sscanf(s.c_str(), "{type:%s,coord:(%d,%d)(%d,%d)(%d,%d),color:%s}", type, (unsigned)_countof(type), &x1, &y1, &x2, &y2, &x3, &y3, color, (unsigned)_countof(color));
	}
	catch (const invalid_argument& e)
	{
		return NULL;
	}
}