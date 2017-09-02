#include "stdafx.h"
#include "GloableVariable.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

CString CGloableVariable::files_3ds[N+23];
//������ǰ��մ�Ĵָ��ʳָ����ָ������ָ��СĴָ��˳��

float CGloableVariable::defaultPos[N][3] = { { 150,0,0 },                 //ÿ����������ʼλ��
{ 46.186,24.331,0 },{ 56.521,42.232,0 },{ 69.047,63.927,0 },{ 81.378,85.286,0 },

{ 20.941,37.685,0 },{ 20.941,58.556,0 },{ 20.941,108.615,0 },{ 20.941,153.236,0 },

{ 0.669,40.220,0 },{ 0.669,60.894,0 },{ 0.669,125.957,0 },{ 0.669,170.576,0 },

{ -23.204,40.220,0 },{ -23.204,60.894,0 },{ -23.204,110.957,0 },{ -23.204,155.576,0 },
{ -43.541,37.685,0 },{ -43.541,58.556,0 },{ -43.541,88.615,0 },{ -43.541,118.236,0 } };

float CGloableVariable::defaultPos_r[21][3] = { {150,0,0},
{ 46.186,24.331,0 },{ 56.521,42.232,0 },{ 69.047,63.927,0 },{ 81.378,85.286,0 },

{ 20.941,37.685,0 },{ 20.941,58.556,0 },{ 20.941,108.615,0 },{ 20.941,153.236,0 },

{ 0.669,40.220,0 },{ 0.669,60.894,0 },{ 0.669,125.957,0 },{ 0.669,170.576,0 },

{ -23.204,40.220,0 },{ -23.204,60.894,0 },{ -23.204,110.957,0 },{ -23.204,155.576,0 },
{ -43.541,37.685,0 },{ -43.541,58.556,0 },{ -43.541,88.615,0 },{ -43.541,118.236,0 } };

float CGloableVariable::defaultPos_b[2][3] = {
	{ 34.032,0,0},{ 34.032,0,0 }
};
//////////////////////////////////////////////////////////////////////////
//			��ʼ��
//////////////////////////////////////////////////////////////////////////
void CGloableVariable::Initial()
{
	Initial_3dsFilesName();
}
//////////////////////////////////////////////////////////////////////////
//			����ָ�ؽڶ�Ӧ��3DS�ļ���
//////////////////////////////////////////////////////////////////////////
void CGloableVariable::Initial_3dsFilesName()          //�����ĵ�����Դ�ļ�
{
	int index = 0;

	files_3ds[index++] = "./3DSModels/robotic hand/palm/palm2.3DS";//����
	files_3ds[index++] = "./3DSModels/robotic hand/��е�ָ�/1thumb/thumb_1.3DS"; //��Ĵָ���ؽ�
	files_3ds[index++] = "./3DSModels/robotic hand/��е�ָ�/1thumb/thumb_2.3DS"; //��Ĵָ�����ؽ�
	files_3ds[index++] = "./3DSModels/robotic hand/��е�ָ�/1thumb/thumb_3.3DS"; //��Ĵָ�м�ؽ�
	files_3ds[index++] = "./3DSModels/robotic hand/��е�ָ�/1thumb/thumb_4.3DS"; //��Ĵָĩ�ҹؽ�

	files_3ds[index++] = "./3DSModels/robotic hand/2index/index_1.3DS"; //ʳָ���ؽ�
	files_3ds[index++] = "./3DSModels/robotic hand/2index/index_2.3DS"; //ʳָ�����ؽ�
	files_3ds[index++] = "./3DSModels/robotic hand/2index/index_3.3DS"; //ʳָ�м�ؽ�
	files_3ds[index++] = "./3DSModels/robotic hand/2index/index_4.3DS"; //ʳָĩ�ҹؽ�

	files_3ds[index++] = "./3DSModels/robotic hand/��е�ָ�/3middle/middle_1.3DS"; //��ָ���ؽ�
	files_3ds[index++] = "./3DSModels/robotic hand/��е�ָ�/3middle/middle_2.3DS"; //��ָ�����ؽ�
	files_3ds[index++] = "./3DSModels/robotic hand/��е�ָ�/3middle/middle_3.3DS"; //��ָ�м�ؽ�
	files_3ds[index++] = "./3DSModels/robotic hand/��е�ָ�/3middle/middle_4.3DS"; //��ָĩ�ҹؽ�

	files_3ds[index++] = "./3DSModels/robotic hand/4ring/ring_1.3DS"; //����ָ���ؽ�
	files_3ds[index++] = "./3DSModels/robotic hand/4ring/ring_2.3DS"; //����ָ�����ؽ�
	files_3ds[index++] = "./3DSModels/robotic hand/4ring/ring_3.3DS"; //����ָ�м�ؽ�
	files_3ds[index++] = "./3DSModels/robotic hand/4ring/ring_4.3DS"; //����ָĩ�ҹؽ�

	files_3ds[index++] = "./3DSModels/robotic hand/��е�ָ�/5little/little_1.3DS"; //СĴָ���ؽ�
	files_3ds[index++] = "./3DSModels/robotic hand/��е�ָ�/5little/little_2.3DS"; //СĴָ�����ؽ�
	files_3ds[index++] = "./3DSModels/robotic hand/��е�ָ�/5little/little_3.3DS"; //СĴָ�м�ؽ�
	files_3ds[index++] = "./3DSModels/robotic hand/��е�ָ�/5little/little_4.3DS"; //СĴָĩ�ҹؽ�

	files_3ds[index++] = "./3DSModels/robotic hand/palm/background.3DS"; //����
	
	files_3ds[index++] = "./3DSModels/robotic hand/palm/palm2.3DS";//����

	files_3ds[index++] = "./3DSModels/robotic hand/��е�ָ�/1thumb/thumb_1.3DS"; //��Ĵָ���ؽ�
	files_3ds[index++] = "./3DSModels/robotic hand/��е�ָ�/1thumb/thumb_2.3DS"; //��Ĵָ�����ؽ�
	files_3ds[index++] = "./3DSModels/robotic hand/��е�ָ�/1thumb/thumb_3.3DS"; //��Ĵָ�м�ؽ�
	files_3ds[index++] = "./3DSModels/robotic hand/��е�ָ�/1thumb/thumb_4.3DS"; //��Ĵָĩ�ҹؽ�

	files_3ds[index++] = "./3DSModels/robotic hand/2index/index_1.3DS"; //ʳָ���ؽ�

	files_3ds[index++] = "./3DSModels/robotic hand/2index/index_2.3DS"; //ʳָ�����ؽ�
	files_3ds[index++] = "./3DSModels/robotic hand/2index/index_3.3DS"; //ʳָ�м�ؽ�
	files_3ds[index++] = "./3DSModels/robotic hand/2index/index_4.3DS"; //ʳָĩ�ҹؽ�

	files_3ds[index++] = "./3DSModels/robotic hand/��е�ָ�/3middle/middle_1.3DS"; //��ָ���ؽ�
	files_3ds[index++] = "./3DSModels/robotic hand/��е�ָ�/3middle/middle_2.3DS"; //��ָ�����ؽ�
	files_3ds[index++] = "./3DSModels/robotic hand/��е�ָ�/3middle/middle_3.3DS"; //��ָ�м�ؽ�

	files_3ds[index++] = "./3DSModels/robotic hand/��е�ָ�/3middle/middle_4.3DS"; //��ָĩ�ҹؽ�
	files_3ds[index++] = "./3DSModels/robotic hand/4ring/ring_1.3DS"; //����ָ���ؽ�
	files_3ds[index++] = "./3DSModels/robotic hand/4ring/ring_2.3DS"; //����ָ�����ؽ�
	files_3ds[index++] = "./3DSModels/robotic hand/4ring/ring_3.3DS"; //����ָ�м�ؽ�
	files_3ds[index++] = "./3DSModels/robotic hand/4ring/ring_4.3DS"; //����ָĩ�ҹؽ�

	files_3ds[index++] = "./3DSModels/robotic hand/��е�ָ�/5little/little_1.3DS"; //СĴָ���ؽ�
	files_3ds[index++] = "./3DSModels/robotic hand/��е�ָ�/5little/little_2.3DS"; //СĴָ�����ؽ�
	files_3ds[index++] = "./3DSModels/robotic hand/��е�ָ�/5little/little_3.3DS"; //СĴָ�м�ؽ�
	files_3ds[index++] = "./3DSModels/robotic hand/��е�ָ�/5little/little_4.3DS"; //СĴָĩ�ҹؽ�

	files_3ds[index++] = "./3DSModels/robotic hand/palm/tumb_b.3DS";//��������һ����
	files_3ds[index++] = "./3DSModels/robotic hand/palm/tumb_b.3DS";//��������һ����

}

