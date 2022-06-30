#include "EditXML.h"
#include <iostream>

int main()
{
	EditXML* editXML = new EditXML;
	//editXML->Edit_08();
	editXML->Edit_15();
	editXML->Edit_15_f();

	delete editXML;

	std::cout << "Work finished." << std::endl;
	return 0;
}