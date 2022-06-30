#include "ReadINI.h"
#include <string>


ReadINI::ReadINI()
{
	fileName = _T("File");
	newProject = _T("mrtcomm");
	projectName = _T("Project");
	addedProject = _T("AddedProject");
}


ReadINI::~ReadINI()
{
}

void ReadINI::GetInfo(CString iniPath)
{
	int num = 1;
	CString AllFile = fileName + std::to_string(num).c_str();
	CString inBuf;

	while (GetPrivateProfileString(newProject, AllFile, NULL, inBuf.GetBuffer(MAX_PATH), MAX_PATH, iniPath))
	{
		inBuf.ReleaseBuffer();

		int len = inBuf.GetLength();

		if (inBuf[len - 1] == _T('h'))
		{
			hFilePathVector.push_back(inBuf);
		}
		else
		{
			cppFilePathVector.push_back(inBuf);
		}

		AllFile = fileName + std::to_string(++num).c_str();

	}

	num = 1;
	AllFile = projectName + std::to_string(num).c_str();
	while (GetPrivateProfileString(addedProject, AllFile, NULL, inBuf.GetBuffer(MAX_PATH), MAX_PATH, iniPath))
	{
		projectPathVector.push_back(inBuf);
		AllFile = projectName + std::to_string(++num).c_str();

		inBuf.ReleaseBuffer();
	}

}