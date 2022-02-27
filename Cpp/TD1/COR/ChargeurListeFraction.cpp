#include "ChargeurListeFraction.h"
#include <iostream>
#include <fstream>

void ChargeurListeFraction::charge(ifstream& fichier)
{
	// Create a text string, which is used to output the text file
	string myText;

	// Read from the text file

	// Use a while loop together with the getline() function to read the file line by line
	while (getline(fichier, myText)) {
		// Output the text from the file
		cout << myText;
	}

}