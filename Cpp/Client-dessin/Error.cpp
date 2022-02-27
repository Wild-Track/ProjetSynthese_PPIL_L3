#include <stdio.h>
#include <string.h>
#include <iostream>
#include <string>
#include "Error.h"

using namespace std;

Error::Error()
{
	strcpy_s(msg, "Erreur : ");
}

Error::Error(const char* errorMsg)
{
	strcpy_s(msg, "Erreur : ");
	int l = strlen(errorMsg);
	static int n = LENGHTMSG - 9;

	if (l <= n) strcat_s(msg, errorMsg);
	else
	{
		strncat_s(msg, errorMsg, n);
		msg[LENGHTMSG] = '\0';
	}
}

Error::operator string() const
{
	return string(msg);
}

ostream& operator << (ostream& os, const Error& error)
{
	return os << (string)error;
}