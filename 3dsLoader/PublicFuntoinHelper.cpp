#include "StdAfx.h"
#include "PublicFuntoinHelper.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

//////////////////////////////////////////////////////////////////////////
//			��Ϣ��
//type=0:��ͨ��Ϣ��;type=1:ѯ����Ϣ��;type=2:������Ϣ��;type=3:������Ϣ��
//////////////////////////////////////////////////////////////////////////
int PublicFuntoinHelper::ShowMessage(LPCSTR content, UINT type, LPCTSTR title)
{
	if (title==NULL)
	{
		title = _T("��Ϣ��");
	}
	switch (type)
	{
	case 0:
		return MessageBoxA(NULL, content, title, MB_OK | MB_ICONINFORMATION);
	case 1:
		return MessageBoxA(NULL, content, title, MB_YESNO | MB_ICONQUESTION);
	case 2:
		return MessageBoxA(NULL, content, title, MB_OK | MB_ICONEXCLAMATION);
	case 3:
		return MessageBoxA(NULL, content, title, MB_OK | MB_ICONSTOP);
	default:
		return MessageBoxA(NULL, content, title, MB_OK | MB_ICONINFORMATION);
		break;
	}

}
//////////////////////////////////////////////////////////////////////////
//	�ָ��ַ�����ת���ɸ����� values:Ҫ������ַ���;splitChar:�ָ���
//////////////////////////////////////////////////////////////////////////
float* PublicFuntoinHelper::SplitString(CString values, CString splitChar)
{
	float* fv = new float[4];
	int index = 0;
	CString strleft;

	//�����ַ������û�ҵ����򷵻�0���ҵ��򷵻��ַ���λ��,
	//�����������ַ�Ҳ�������ַ���
	int pos = values.Find(splitChar);
	while (pos > 0)
	{
		strleft = values.Left(pos);//ȡ��,����Ϊ�ַ����ĸ���
		values = values.Right(values.GetLength() - pos - 1);//ȡ�ң�����ͬ��
		fv[index++] = atof(strleft);
		pos = values.Find(splitChar);
	}
	fv[index++] = atof(values);
	
	return fv;
}