// 3DSLoaderView.h : interface of the CMy3DSLoaderView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_MYSDOPENGLVIEW_H__75C5AAEC_37B0_4A8B_9132_9A0C663F6DDC__INCLUDED_)
#define AFX_MYSDOPENGLVIEW_H__75C5AAEC_37B0_4A8B_9132_9A0C663F6DDC__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "glStructures.h"	//���ݽṹ����
#include "3dsReader.h"		//C3dsReader˵���ļ�
#include "RobotHand.h"		//CRobotHand˵���ļ�

class CMy3DSLoaderView : public CView
{
protected: // create from serialization only
	CMy3DSLoaderView();
	DECLARE_DYNCREATE(CMy3DSLoaderView)

// Attributes
public:
	CMy3DSLoaderDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMy3DSLoaderView)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CMy3DSLoaderView();
/////////////////////////////////////////////////////////////////
//��ӳ�Ա�������Ա����
private:
	BOOL RenderScene();
	BOOL SetupPixelFormat(void);
	void SetLogicalPalette(void);
	BOOL InitializeOpenGL(CDC* pDC);

	HGLRC		m_hRC;			//OpenGL����������
	HPALETTE	m_hPalette;		//OpenGL��ɫ��
	CDC*	    m_pDC;			//OpenGL�豸������
/////////////////////////////////////////////////////////////////
	void Init(GLvoid);
	void Draw3ds(CRobotHand ctl);
	void DrawAxis();
	void SetSceneRot(int axis, int value, BOOL increment, BOOL apply);
	void SetCamPos(int axis, int value, BOOL increment, BOOL apply);
	BOOL OpenFile(CRobotHand& ctl, LPCTSTR lpszPathName);

	
	CRobotHand	m_RobotHand;		
	BOOL		m_3dsLoaded;	
	float		camRot[3];//�����������������ĽǶ�		
	float		camPos[3];//������Ŀռ�λ��
	
	BOOL		mouserightdown;	
	BOOL		mouseleftdown;	
	CPoint		mouseprevpoint; 
public:
	CRobotHand GetCRobotHandHandle() { return this->m_RobotHand; };
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CMy3DSLoaderView)
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnDestroy();
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnTimer(UINT nIDEvent);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnGrab();
	afx_msg void OnReset();
	afx_msg void OnThumb();
	afx_msg void OnThumbInverse();
	afx_msg void OnIndex();
	afx_msg void OnIndexInverse();
	afx_msg void OnMiddle();
	afx_msg void OnMiddleInverse();
	afx_msg void OnRing();
	afx_msg void OnRingInverse();
	afx_msg void OnLittle();
	afx_msg void OnLittleInverse();
	afx_msg void OnFist();
	afx_msg void OnPush();
	afx_msg void OnClamp();
	afx_msg void OnPull();
	afx_msg void OnInsert();
	afx_msg void OnSupport();
	afx_msg void OnSqueeze();
	afx_msg void OnCut();
	afx_msg void OnRip();
	afx_msg void OnTongs();
};

#ifndef _DEBUG  // debug version in 3DSLoaderView.cpp
inline CMy3DSLoaderDoc* CMy3DSLoaderView::GetDocument()
   { return (CMy3DSLoaderDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MYSDOPENGLVIEW_H__75C5AAEC_37B0_4A8B_9132_9A0C663F6DDC__INCLUDED_)
