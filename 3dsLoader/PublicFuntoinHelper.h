#ifndef PUBLICFUNCTIONHELPER_H
#define PUBLICFUNCTIONHELPER_H

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "windows.h"

class PublicFuntoinHelper
{
public:
	PublicFuntoinHelper()
	{
	}

	~PublicFuntoinHelper()
	{
	}
	static int ShowMessage(LPCSTR content, UINT type = 0, LPCTSTR title = NULL);//��Ϣ��
	static float* SplitString(CString values, CString splitChar=",");//�ָ��ַ���
};
#endif
