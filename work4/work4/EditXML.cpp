#include "EditXML.h"



EditXML::EditXML()
{
	readINI = new ReadINI;

	TCHAR exepath[MAX_PATH] = { 0 };
	::GetModuleFileName(NULL, exepath, MAX_PATH);
	PATH = exepath;
	PATH = PATH.Left(PATH.ReverseFind('\\'));
	PATH += _T("\\");
	
	CString iniPath = PATH + _T("test.ini");
	readINI->GetInfo(iniPath);
}


EditXML::~EditXML()
{
	delete readINI;
}

void EditXML::Edit_08()
{
	for (int i = 0; i < readINI->projectPathVector.size(); i++)
	{
		CString XMLName = readINI->projectPathVector[i];
		CString XMLPath = PATH + XMLName + _T("\\") + XMLName + _T(".vcproj");
		xml.Load(XMLPath);
		xml.FindElem(_T("VisualStudioProject"));
		xml.IntoElem();

		xml.FindElem(_T("Files"));
		xml.IntoElem();

		xml.FindElem(_T("Filter"));
		xml.IntoElem();

		for (int j = 0; j < readINI->cppFilePathVector.size(); j++)
		{
			CString cppPath = _T("..\\") + readINI->newProject + _T("\\") + readINI->cppFilePathVector[j];

			int next = 0;
			while (xml.FindElem(_T("File")))
			{
				CString havePath = xml.GetAttrib(_T("RelativePath"));
				if (havePath == cppPath)
				{
					next = 1;
					break;
				}
			}

			if (next == 1)
			{
				continue;
			}

			xml.AddElem(_T("File"), _T("\n"));
			xml.SetAttrib(_T("RelativePath"), cppPath);
		}
		xml.OutOfElem();

		xml.FindElem(_T("Filter"));
		for (int j = 0; j < readINI->hFilePathVector.size(); j++)
		{
			CString hPath = _T("..\\") + readINI->newProject + _T("\\") + readINI->hFilePathVector[j];

			int next = 0;
			while (xml.FindElem(_T("File")))
			{
				CString havePath = xml.GetAttrib(_T("RelativePath"));
				if (havePath == hPath)
				{
					next = 1;
					break;
				}
			}

			if (next == 1)
			{
				continue;
			}

			xml.AddElem(_T("File"), _T("\n"));
			xml.SetAttrib(_T("RelativePath"), hPath);
		}


		xml.Save(XMLPath);
	}
}

void EditXML::Edit_15()
{
	for (int i = 0; i < readINI->projectPathVector.size(); i++)
	{
		CString XMLName = readINI->projectPathVector[i];
		CString XMLPath = PATH + XMLName + _T("\\") + XMLName + _T(".vcxproj");

		xml.Load(XMLPath);
		xml.FindElem(_T("Project"));
		xml.IntoElem();

		xml.FindElem(_T("ItemGroup"));
		xml.FindElem(_T("ItemGroup"));
		xml.IntoElem();

		for (int j = 0; j < readINI->cppFilePathVector.size(); j++)
		{
			CString cppPath = _T("..\\") + readINI->newProject + _T("\\") + readINI->cppFilePathVector[j];

			int next = 0;
			while (xml.FindElem(_T("ClCompile")))
			{
				CString havePath = xml.GetAttrib(_T("Include"));
				if (havePath == cppPath)
				{
					next = 1;
					break;
				}
			}

			if (next == 1)
			{
				continue;
			}

			xml.AddElem(_T("ClCompile"));
			xml.SetAttrib(_T("Include"), cppPath);
		}
		xml.OutOfElem();

		xml.FindElem(_T("ItemGroup"));
		xml.FindElem(_T("ItemGroup"));
		xml.IntoElem();

		for (int j = 0; j < readINI->hFilePathVector.size(); j++)
		{
			CString hPath = _T("..\\") + readINI->newProject + _T("\\") + readINI->hFilePathVector[j];

			int next = 0;
			while (xml.FindElem(_T("ClInclude")))
			{
				CString havePath = xml.GetAttrib(_T("Include"));
				if (havePath == hPath)
				{
					next = 1;
					break;
				}
			}

			if (next == 1)
			{
				continue;
			}

			xml.AddElem(_T("ClInclude"));
			xml.SetAttrib(_T("Include"), hPath);
		}


		xml.Save(XMLPath);
	}
}

void EditXML::Edit_15_f()
{
	for (int i = 0; i < readINI->projectPathVector.size(); i++)
	{
		CString XMLName = readINI->projectPathVector[i];
		CString XMLPath = PATH + XMLName + _T("\\") + XMLName + _T(".vcxproj.filters");

		xml.Load(XMLPath);
		xml.FindElem(_T("Project"));
		xml.IntoElem();

		xml.FindElem(_T("ItemGroup"));
		xml.FindElem(_T("ItemGroup"));
		xml.IntoElem();

		for (int j = 0; j < readINI->cppFilePathVector.size(); j++)
		{
			CString cppPath = _T("..\\") + readINI->newProject + _T("\\") + readINI->cppFilePathVector[j];

			int next = 0;
			while (xml.FindElem(_T("ClCompile")))
			{
				CString havePath = xml.GetAttrib(_T("Include"));
				if (havePath == cppPath)
				{
					next = 1;
					break;
				}
			}

			if (next == 1)
			{
				continue;
			}

			xml.AddElem(_T("ClCompile"));
			xml.SetAttrib(_T("Include"), cppPath);

			xml.IntoElem();
			xml.AddElem(_T("Filter"), _T("源文件"));
			xml.OutOfElem();

		}
		xml.OutOfElem();

		xml.FindElem(_T("ItemGroup"));
		xml.FindElem(_T("ItemGroup"));
		xml.IntoElem();

		for (int j = 0; j < readINI->hFilePathVector.size(); j++)
		{
			CString hPath = _T("..\\") + readINI->newProject + _T("\\") + readINI->hFilePathVector[j];

			int next = 0;
			while (xml.FindElem(_T("ClInclude")))
			{
				CString havePath = xml.GetAttrib(_T("Include"));
				if (havePath == hPath)
				{
					next = 1;
					break;
				}
			}

			if (next == 1)
			{
				continue;
			}

			xml.AddElem(_T("ClInclude"), _T("\n"));
			xml.SetAttrib(_T("Include"), hPath);

			xml.IntoElem();
			xml.AddElem(_T("Filter"), _T("头文件"));
			xml.OutOfElem();

		}

		xml.Save(XMLPath);
	}
}