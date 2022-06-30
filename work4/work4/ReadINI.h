#pragma once
#include <afx.h>
#include <vector>
class ReadINI
{
public:
	ReadINI();
	~ReadINI();

	std::vector<CString> cppFilePathVector;
	std::vector<CString> hFilePathVector;
	std::vector<CString> projectPathVector;

	CString addedProject;
	CString projectName;

	CString newProject;
	CString fileName;

	void GetInfo(CString iniPath);
};

