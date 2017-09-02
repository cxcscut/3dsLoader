// ��������һ�����ĵ�Ԫ(��ָ�ؽ�+����)��ɣ�ÿ���ؽڶ�Ӧһ��CRobotHand����
//ע��ÿֻ�������������ָ+������ɣ�ÿ����ָ���ĸ�ָ�����
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_RobotHand_H__F4D23E1D_92BF_4F04_A498_761E19114FC0__INCLUDED_)
#define AFX_RobotHand_H__F4D23E1D_92BF_4F04_A498_761E19114FC0__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Knuckle.h"
class CRobotHand  
{
public:
	CRobotHand();
	virtual ~CRobotHand();

	CKnuckle* getObjectByName(char* name);
	void removeAllObjects();
	void doAfterMath();
	void Init();
	int	 getNumObjects() {return numobjects;};

	void drawGL();
	BOOL add(CKnuckle* _object);
	
private:
	int numobjects;
	int free;
	int maxobjects;

public:
	CKnuckle* objects[100];	
//	CKnuckle* objects_r[100];
	
public:
	void Initial_Length();//��ʼ������ָ�ڵĳ���
	void Initial_CenterPos();//��ʼ������ָ�ڵ�����
	//�������������ָ���ĸ��ؽڵĽǶ�
	//����ָ�������ָ�룬�ֱ�洢theta1,theta2,theta3,theta4
	//�����ֱ�Ϊpx,py,pz
	float* CalculateThetaByCoordinate(tVector coordinate,int choice[]);

	float ConvertAngleToRadian(float angle);//���Ƕ�ת���ɻ���
	float ConvertRadianToAngle(float radian);//������ת���ɽǶ�

	void RotateFunction(int i, float angle);
	void RotateFunction_r(int i, float angle);
	void RotateFunction_b(int i, float angle);
	void Thumb1_Rotate(float angle);//��Ĵָ���ؽ���ת
	void Thumb2_Rotate(float angle);//��Ĵָ�����ؽ���ת
	void Thumb3_Rotate(float angle);//��Ĵָ�м�ؽ���ת
	void Thumb4_Rotate(float angle);//��Ĵָĩ�ҹؽ���ת

	void Index1_Rotate(float angle);//ʳָ���ؽ���ת
	void Index2_Rotate(float angle);//ʳָ�����ؽ���ת
	void Index3_Rotate(float angle);//ʳָ�м�ؽ���ת
	void Index4_Rotate(float angle);//ʳָĩ�ҹؽ���ת

	void Middle1_Rotate(float angle);//��ָ���ؽ���ת
	void Middle2_Rotate(float angle);//��ָ�����ؽ���ת
	void Middle3_Rotate(float angle);//��ָ�м�ؽ���ת
	void Middle4_Rotate(float angle);//��ָĩ�ҹؽ���ת

	void Ring1_Rotate(float angle);//����ָ���ؽ���ת
	void Ring2_Rotate(float angle);//����ָ�����ؽ���ת
	void Ring3_Rotate(float angle);//����ָ�м�ؽ���ת
	void Ring4_Rotate(float angle);//����ָĩ�ҹؽ���ת

	void Little1_Rotate(float angle);//СĴָ���ؽ���ת
	void Little2_Rotate(float angle);//СĴָ�����ؽ���ת
	void Little3_Rotate(float angle);//СĴָ�м�ؽ���ת
	void Little4_Rotate(float angle);//СĴָĩ�ҹؽ���ת
	/*����*/
	void Thumb1_Rotate_r(float angle);//��Ĵָ���ؽ���ת
	void Thumb2_Rotate_r(float angle);//��Ĵָ�����ؽ���ת
	void Thumb3_Rotate_r(float angle);//��Ĵָ�м�ؽ���ת
	void Thumb4_Rotate_r(float angle);//��Ĵָĩ�ҹؽ���ת

	void Index1_Rotate_r(float angle);//ʳָ���ؽ���ת
	void Index2_Rotate_r(float angle);//ʳָ�����ؽ���ת
	void Index3_Rotate_r(float angle);//ʳָ�м�ؽ���ת
	void Index4_Rotate_r(float angle);//ʳָĩ�ҹؽ���ת

	void Middle1_Rotate_r(float angle);//��ָ���ؽ���ת
	void Middle2_Rotate_r(float angle);//��ָ�����ؽ���ת
	void Middle3_Rotate_r(float angle);//��ָ�м�ؽ���ת
	void Middle4_Rotate_r(float angle);//��ָĩ�ҹؽ���ת

	void Ring1_Rotate_r(float angle);//����ָ���ؽ���ת
	void Ring2_Rotate_r(float angle);//����ָ�����ؽ���ת
	void Ring3_Rotate_r(float angle);//����ָ�м�ؽ���ת
	void Ring4_Rotate_r(float angle);//����ָĩ�ҹؽ���ת

	void Little1_Rotate_r(float angle);//СĴָ���ؽ���ת
	void Little2_Rotate_r(float angle);//СĴָ�����ؽ���ת
	void Little3_Rotate_r(float angle);//СĴָ�м�ؽ���ת
	void Little4_Rotate_r(float angle);//СĴָĩ�ҹؽ���ת

	void Thumb_Rotate_b(float angle);//��Ĵָ���ؽ���ת
	void Thumb_Rotate_br(float angle);//��Ĵָ���ؽ���ת
};

#endif // !defined(AFX_RobotHand_H__F4D23E1D_92BF_4F04_A498_761E19114FC0__INCLUDED_)
