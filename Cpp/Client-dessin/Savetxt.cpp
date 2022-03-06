#include "Savetxt.h"

#include <iostream>
#include <fstream>
#include <iomanip>



void Savetxt::visite(const FormGroup* formGroup) const
{
	string data = "{";
	for (Form* form : formGroup->getFromList())
	{
		data += string(*form) + "/";
	}
	data += formGroup->getColor() + ",";
	data += formGroup->getName() + "}";

	saveOnFile(data, "FormGroup");
}

void Savetxt::visite(const Circle* form) const
{
	string data = "{" + string(*form) + "}";
	saveOnFile(data, "Circle");
}

void Savetxt::visite(const Cross* form) const
{
	string data = "{" + string(*form) + "}";
	saveOnFile(data, "Cross");
}

void Savetxt::visite(const Segment* form) const
{
	string data = "{" + string(*form) + "}";
	saveOnFile(data, "Segment");
}

void Savetxt::visite(const Triangle* form) const
{
	string data = "{" + string(*form) + "}";
	saveOnFile(data, "Triangle");
}

void Savetxt::visite(const polygon::Polygon* form) const
{
	string data = "{" + string(*form) + "}";
	saveOnFile(data, "Polygon");
}

void Savetxt::saveOnFile(string data, string name) const
{
	string nameFile;

	time_t curr_time;
	tm curr_tm;
	char timeString[100];

	time(&curr_time);
	localtime_s(&curr_tm, &curr_time);
	strftime(timeString, 50, "%H-%M-%S", &curr_tm);

	nameFile = "../Save/" + name + timeString + ".txt";

	ofstream file(nameFile);

	file << data << "\n";
	file.close();
}
