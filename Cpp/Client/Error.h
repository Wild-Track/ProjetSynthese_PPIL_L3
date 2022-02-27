#pragma once

#include <stdio.h>

using namespace std;

class Error 
{
public:
	const static int LENGHTMSG = 100;
	char msg[1 + LENGHTMSG];

	Error();
	Error(const char* errorMsg);

	operator string() const;
};

ostream& operator << (ostream& os, const Error& error);
