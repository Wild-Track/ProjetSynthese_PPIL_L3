#include "SaveParserSegmentCOR.h"
#include <sstream>


SaveParserSegmentCOR::SaveParserSegmentCOR(SaveParserCOR* suivant) : SaveParserCOR(suivant) {}

Segment* SaveParserSegmentCOR::Parser(const string& s) const
{
	int pos = s.find('{');
	char type[20];
	char color[20];
	int x1, y1, x2, y2;

	if (pos == -1)
	{
		return NULL;
	}
	else
	{
		try 
		{
			sscanf_s(s.c_str(), "{type:%s,coord:(%d,%d)(%d,%d),color:%s}", type, (unsigned)_countof(type), &x1, &y1, &x2, &y2, color, (unsigned)_countof(color));
		} catch (const invalid_argument& e)
		{
			return NULL;
		}
	}
}