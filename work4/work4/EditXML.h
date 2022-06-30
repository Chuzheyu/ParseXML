#pragma once
#include "Markup.h"
#include "ReadINI.h"

class EditXML
{
public:
	EditXML();
	~EditXML();

	CMarkup xml;
	ReadINI* readINI;
	CString PATH;

	void Edit_08();
	void Edit_15();
	void Edit_15_f();

};

