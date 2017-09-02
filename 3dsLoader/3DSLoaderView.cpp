// 3DSLoaderView.cpp : implementation of the CMy3DSLoaderView class
//

#include "stdafx.h"
//#include "MatlabEng.h"

#include "3DSLoader.h"

#include "3DSLoaderDoc.h"
#include "3DSLoaderView.h"
#include "GloableVariable.h"
#include <windows.h>
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMy3DSLoaderView

IMPLEMENT_DYNCREATE(CMy3DSLoaderView, CView)

BEGIN_MESSAGE_MAP(CMy3DSLoaderView, CView)
	//{{AFX_MSG_MAP(CMy3DSLoaderView)
	ON_WM_CREATE()
	ON_WM_DESTROY()
	ON_WM_SIZE()
	ON_WM_TIMER()
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
	ON_WM_RBUTTONDOWN()
	ON_WM_RBUTTONUP()
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
	ON_COMMAND(ID_Reset, &CMy3DSLoaderView::OnReset)
	ON_COMMAND(ID_Thumb, &CMy3DSLoaderView::OnThumb)
	ON_COMMAND(ID_Thumb_Inverse, &CMy3DSLoaderView::OnThumbInverse)
	ON_COMMAND(ID_Index, &CMy3DSLoaderView::OnIndex)
	ON_COMMAND(ID_Index_Inverse, &CMy3DSLoaderView::OnIndexInverse)
	ON_COMMAND(ID_Middle, &CMy3DSLoaderView::OnMiddle)
	ON_COMMAND(ID_Middle_Inverse, &CMy3DSLoaderView::OnMiddleInverse)
	ON_COMMAND(ID_Ring, &CMy3DSLoaderView::OnRing)
	ON_COMMAND(ID_Ring_Inverse, &CMy3DSLoaderView::OnRingInverse)
	ON_COMMAND(ID_Little, &CMy3DSLoaderView::OnLittle)
	ON_COMMAND(ID_Little_Inverse, &CMy3DSLoaderView::OnLittleInverse)
	ON_COMMAND(ID_grab, &CMy3DSLoaderView::OnGrab)
	ON_COMMAND(ID_Fist, &CMy3DSLoaderView::OnFist)
	ON_COMMAND(ID_Push, &CMy3DSLoaderView::OnPush)
	ON_COMMAND(ID_Clamp, &CMy3DSLoaderView::OnClamp)
	ON_COMMAND(ID_Pull, &CMy3DSLoaderView::OnPull)
	ON_COMMAND(ID_Insert, &CMy3DSLoaderView::OnInsert)
	ON_COMMAND(ID_Support, &CMy3DSLoaderView::OnSupport)
	ON_COMMAND(ID_Squeeze, &CMy3DSLoaderView::OnSqueeze)
	ON_COMMAND(ID_Cut, &CMy3DSLoaderView::OnCut)
	ON_COMMAND(ID_Rip, &CMy3DSLoaderView::OnRip)
	ON_COMMAND(ID_Tongs, &CMy3DSLoaderView::OnTongs)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMy3DSLoaderView construction/destruction


CMy3DSLoaderView::CMy3DSLoaderView()
{
	// TODO: add construction code here

}

CMy3DSLoaderView::~CMy3DSLoaderView()
{
}

BOOL CMy3DSLoaderView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs
////////////////////////////////////////////////////////////////
//���ô�������
	cs.style |=WS_CLIPCHILDREN | WS_CLIPSIBLINGS;
////////////////////////////////////////////////////////////////
	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CMy3DSLoaderView drawing

void CMy3DSLoaderView::OnDraw(CDC* pDC)
{
	CMy3DSLoaderDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
//////////////////////////////////////////////////////////////////
	
	
	//OpenFile("C:\\Users\\robot\\Desktop\\DexterousHand\\Ring\\Ring_1.3DS");
	RenderScene();	//��Ⱦ����
	
	//OpenFile("C:\\Users\\robot\\Desktop\\DexterousHand\\Thumb\\Palm.3DS");
	//::glPushMatrix();
	//::glTranslated(-18, -10, -25);
	//::glRotatef(22, 1.0F, 0.0F, 0.0F);
	//::glRotatef(100, 0.0F, 1.0F, 0.0F);
	//::glRotatef(50, 0.0F, 0.0F, 1.0F);

	//
	//Draw3ds();
	//::glPopMatrix();

	//::SwapBuffers(m_pDC->GetSafeHdc());		//����������
//////////////////////////////////////////////////////////////////
	
}

/////////////////////////////////////////////////////////////////////////////
// CMy3DSLoaderView printing

BOOL CMy3DSLoaderView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CMy3DSLoaderView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CMy3DSLoaderView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CMy3DSLoaderView diagnostics

#ifdef _DEBUG
void CMy3DSLoaderView::AssertValid() const
{
	CView::AssertValid();
}

void CMy3DSLoaderView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMy3DSLoaderDoc* CMy3DSLoaderView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy3DSLoaderDoc)));
	return (CMy3DSLoaderDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CMy3DSLoaderView message handlers

int CMy3DSLoaderView::OnCreate(LPCREATESTRUCT lpCreateStruct) 
{
	if (CView::OnCreate(lpCreateStruct) == -1)
		return -1;
	
	// TODO: Add your specialized creation code here
//////////////////////////////////////////////////////////////////
//��ʼ��OpenGL�����ö�ʱ��
	m_pDC = new CClientDC(this);
	//SetTimer(1, 20, NULL);
	InitializeOpenGL(m_pDC);
//////////////////////////////////////////////////////////////////
	Init();	
	return 0;
}

void CMy3DSLoaderView::OnDestroy() 
{
	CView::OnDestroy();
	
	// TODO: Add your message handler code here
/////////////////////////////////////////////////////////////////
//ɾ����ɫ�����Ⱦ�����ġ���ʱ��
	::wglMakeCurrent(0,0);
	::wglDeleteContext( m_hRC);
	if (m_hPalette)
	    DeleteObject(m_hPalette);
	if ( m_pDC )
	{
		delete m_pDC;
	}
	//::engClose(engine);//�ر�matlab����
	
	//KillTimer(1);		
/////////////////////////////////////////////////////////////////
	
}

void CMy3DSLoaderView::OnSize(UINT nType, int cx, int cy) 
{
	CView::OnSize(nType, cx, cy);
	
	// TODO: Add your message handler code here
/////////////////////////////////////////////////////////////////
//��Ӵ�������ʱ��ͼ�α任����
	glViewport(0,0,cx,cy);
/////////////////////////////////////////////////////////////////
	GLdouble aspect_ratio;
	aspect_ratio = (GLdouble)cx/(GLdouble)cy;
	::glMatrixMode(GL_PROJECTION);
	::glLoadIdentity();
	gluPerspective(40.0F, aspect_ratio, 1.0F, 10000.0F);
	::glMatrixMode(GL_MODELVIEW);
	::glLoadIdentity();

}

void CMy3DSLoaderView::OnTimer(UINT nIDEvent) 
{
	// TODO: Add your message handler code here and/or call default
/////////////////////////////////////////////////////////////////
//��Ӷ�ʱ����Ӧ�����ͳ������º���
	Invalidate(FALSE);	
/////////////////////////////////////////////////////////////////
	
	CView::OnTimer(nIDEvent);
}

/////////////////////////////////////////////////////////////////////
//	                  �����߼���ɫ��
//////////////////////////////////////////////////////////////////////
void CMy3DSLoaderView::SetLogicalPalette(void)
{
    struct
    {
        WORD Version;
        WORD NumberOfEntries;
        PALETTEENTRY aEntries[256];
    } logicalPalette = { 0x300, 256 };

	BYTE reds[] = {0, 36, 72, 109, 145, 182, 218, 255};
	BYTE greens[] = {0, 36, 72, 109, 145, 182, 218, 255};
	BYTE blues[] = {0, 85, 170, 255};

    for (int colorNum=0; colorNum<256; ++colorNum)
    {
        logicalPalette.aEntries[colorNum].peRed =
            reds[colorNum & 0x07];
        logicalPalette.aEntries[colorNum].peGreen =
            greens[(colorNum >> 0x03) & 0x07];
        logicalPalette.aEntries[colorNum].peBlue =
            blues[(colorNum >> 0x06) & 0x03];
        logicalPalette.aEntries[colorNum].peFlags = 0;
    }

    m_hPalette = CreatePalette ((LOGPALETTE*)&logicalPalette);
}


//////////////////////////////////////////////////////////
//						��ʼ��openGL����
//////////////////////////////////////////////////////////
BOOL CMy3DSLoaderView::InitializeOpenGL(CDC* pDC)
{
	m_pDC = pDC;
	SetupPixelFormat();
	//���ɻ���������
	m_hRC = ::wglCreateContext(m_pDC->GetSafeHdc());
	//�õ�ǰ����������
	::wglMakeCurrent(m_pDC->GetSafeHdc(), m_hRC);

	return TRUE;
}

//////////////////////////////////////////////////////////
//						�������ظ�ʽ
//////////////////////////////////////////////////////////
BOOL CMy3DSLoaderView::SetupPixelFormat()
{
	PIXELFORMATDESCRIPTOR pfd = { 
	    sizeof(PIXELFORMATDESCRIPTOR),    // pfd�ṹ�Ĵ�С 
	    1,                                // �汾�� 
	    PFD_DRAW_TO_WINDOW |              // ֧���ڴ����л�ͼ 
	    PFD_SUPPORT_OPENGL |              // ֧�� OpenGL 
	    PFD_DOUBLEBUFFER,                 // ˫����ģʽ 
	    PFD_TYPE_RGBA,                    // RGBA ��ɫģʽ 
	    24,                               // 24 λ��ɫ��� 
	    0, 0, 0, 0, 0, 0,                 // ������ɫλ 
	    0,                                // û�з�͸���Ȼ��� 
	    0,                                // ������λλ 
	    0,                                // ���ۼӻ��� 
	    0, 0, 0, 0,                       // �����ۼ�λ 
	    32,                               // 32 λ��Ȼ���     
	    0,                                // ��ģ�建�� 
	    0,                                // �޸������� 
	    PFD_MAIN_PLANE,                   // ���� 
	    0,                                // ���� 
	    0, 0, 0                           // ���Բ�,�ɼ��Ժ������ģ 
	}; 	
	int pixelformat;
	pixelformat = ::ChoosePixelFormat(m_pDC->GetSafeHdc(), &pfd);//ѡ�����ظ�ʽ
	::SetPixelFormat(m_pDC->GetSafeHdc(), pixelformat, &pfd);	//�������ظ�ʽ
	if(pfd.dwFlags & PFD_NEED_PALETTE)
		SetLogicalPalette();	//�����߼���ɫ��
	return TRUE;
}



//////////////////////////////////////////////////////////
//						������������Ⱦ
//////////////////////////////////////////////////////////
BOOL CMy3DSLoaderView::RenderScene() 
{
	::glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
	::glMatrixMode(GL_MODELVIEW);
	::glLoadIdentity();

	
	::glTranslatef(camPos[0], camPos[1], camPos[2]);
	::glRotatef(camRot[0], 1.0F, 0.0F, 0.0F);
	::glRotatef(camRot[1], 0.0F, 1.0F, 0.0F);
	::glRotatef(camRot[2], 0.0F, 0.0F, 1.0F);
	::glPushMatrix();
	DrawAxis();
	m_RobotHand.drawGL();
	::glPopMatrix();
	::SwapBuffers(m_pDC->GetSafeHdc());		//����������
	
	return TRUE;
}

//////////////////////////////////////////////////////////////////////////
//			��ʾָ���ı�
//////////////////////////////////////////////////////////////////////////
void DrawText(const char* str)
{
	static int isFirstCall = 1;
	static GLuint lists;

	if (isFirstCall)
	{ // ����ǵ�һ�ε��ã�ִ�г�ʼ��
	  // Ϊÿһ��ASCII�ַ�����һ����ʾ�б�
		isFirstCall = 0;

		// ����MAX_CHAR����������ʾ�б���
		lists = glGenLists(MAX_CHAR);


		// ��ÿ���ַ��Ļ������װ����Ӧ����ʾ�б���
		wglUseFontBitmaps(wglGetCurrentDC(), 0, MAX_CHAR, lists);
	}
	// ����ÿ���ַ���Ӧ����ʾ�б�����ÿ���ַ�
	for (; *str != '\0'; ++str)
	{
		glCallList(lists + *str);
	}
}
//////////////////////////////////////////////////////////
//							DrawAxis()
//////////////////////////////////////////////////////////
void CMy3DSLoaderView::DrawAxis()
{//�ڿռ�����(0,0,0)��Ϊ���Ļ���������
	glBegin( GL_LINES);
			//ÿ����������6���㹹�ɣ�ǰ�������ʾֱ�ߣ��м������㻭�����벿�ּ�ͷ����������㻭����Ұ벿�ݼ�ͷ
			// x��--��ɫ
			glColor3f(1.0F, 0.0F, 0.0F);
			glVertex3f(CGloableVariable::MIN_AXIS, 0.0f, 0.0f);
			glVertex3f(CGloableVariable::MAX_AXIS, 0.0f, 0.0f);
			glVertex3f( CGloableVariable::MAX_AXIS -CGloableVariable::ARROW_LENGTH, CGloableVariable::ARROW_LENGTH, 0.0f);
			glVertex3f(CGloableVariable::MAX_AXIS, 0.0f, 0.0f);
			glVertex3f(CGloableVariable::MAX_AXIS - CGloableVariable::ARROW_LENGTH,-CGloableVariable::ARROW_LENGTH,-0.0f);
			glVertex3f(CGloableVariable::MAX_AXIS, 0.0f, 0.0f);
			
			// y��--��ɫ
			glColor3f(0.0F, 1.0F, 0.0F);
			glVertex3f( 0.0f,CGloableVariable::MIN_AXIS, 0.0f);
			glVertex3f( 0.0f, CGloableVariable::MAX_AXIS, 0.0f); 
			glVertex3f(-CGloableVariable::ARROW_LENGTH,  CGloableVariable::MAX_AXIS-CGloableVariable::ARROW_LENGTH, 0.0f);
			glVertex3f( 0.0f, CGloableVariable::MAX_AXIS, 0.0f);
			glVertex3f( CGloableVariable::ARROW_LENGTH,  CGloableVariable::MAX_AXIS-CGloableVariable::ARROW_LENGTH, 0.0f);
			glVertex3f( 0.0f, CGloableVariable::MAX_AXIS, 0.0f);

			// z��--��ɫ
			glColor3f(1.0F, 1.0F, 1.0F);
			glVertex3f( 0.0f, 0.0f,CGloableVariable::MIN_AXIS);
			glVertex3f( 0.0f, 0.0f, CGloableVariable::MAX_AXIS);
			glVertex3f(-CGloableVariable::ARROW_LENGTH, 0.0f,  CGloableVariable::MAX_AXIS-CGloableVariable::ARROW_LENGTH);
			glVertex3f( 0.0f, 0.0f, CGloableVariable::MAX_AXIS);
			glVertex3f( CGloableVariable::ARROW_LENGTH, 0.0f,  CGloableVariable::MAX_AXIS-CGloableVariable::ARROW_LENGTH);
			glVertex3f( 0.0f, 0.0f, CGloableVariable::MAX_AXIS);
	glEnd();
	
}

//////////////////////////////////////////////////////////
//							Draw3ds()
//////////////////////////////////////////////////////////
void CMy3DSLoaderView::Draw3ds(CRobotHand ctl)
{
	if (m_3dsLoaded) 
	{
		ctl.drawGL();
	}
}

//////////////////////////////////////////////////////////////////////////
//			��ʼ��
//////////////////////////////////////////////////////////////////////////
void CMy3DSLoaderView::Init(GLvoid)
{
	/*if (!CGloableVariable::engine->IsInitialized())
	{
		MessageBoxA("matlab�����ʼ��ʧ��!");
		CGloableVariable::engine->GetLastErrorMessage();
	}
	CGloableVariable::engine->MinimizeWindow();
	CGloableVariable::engine->Execute("plot([1 2],[3 5],'*r')");*/
	
	m_3dsLoaded  = FALSE;

	camPos[0]	 = 0.0f;
	camPos[1]	 = 0.0f;
	camPos[2]	 = -500.0f;
	camRot[0]	 = 0.0f;
	camRot[1]	 = 0.0f;
	camRot[2]	 = 0.0f;

	mouseprevpoint.x = 0;
	mouseprevpoint.y = 0;
	mouserightdown = FALSE;
	mouseleftdown = FALSE;
	CGloableVariable::Initial();
	
	if (m_RobotHand.getNumObjects() > 0) m_RobotHand.removeAllObjects();
	m_RobotHand.Init();

	for (int i = 0; i < CGloableVariable::N+23; i++) //���ļ�
	{
		OpenFile(m_RobotHand, CGloableVariable::files_3ds[i]);
	}

	m_RobotHand.Initial_Length();
	m_RobotHand.Initial_CenterPos();

	::glShadeModel(GL_FLAT);
	
	::glClearColor(0.0F, 0.0F, 0.0F, 0.0F);
	
	::glClearDepth(1.0F);

	::glEnable(GL_DEPTH_TEST);

	::glEnable(GL_CULL_FACE);

	//���ù���
	GLfloat ambientLight[] = { 0.3f, 0.3f, 0.3f, 1.0f};
	GLfloat diffuseLight[] = { 0.7f, 0.7f, 0.7f, 1.0f};
	GLfloat lightPos[]     = {6000.0f,6000.0f,6000.0f, 1.0f};

	glLightfv(GL_LIGHT0, GL_AMBIENT, ambientLight);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuseLight);
	glLightfv(GL_LIGHT0, GL_POSITION, lightPos);
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, ambientLight);
	
	glEnable(GL_COLOR_MATERIAL);
	glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	
}

void CMy3DSLoaderView::OnRButtonUp(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	ReleaseCapture( );
	mouserightdown = FALSE;
	SetCamPos(2, (point.y - mouseprevpoint.y) , TRUE, TRUE);
	
	CView::OnRButtonUp(nFlags, point);
}

void CMy3DSLoaderView::OnRButtonDown(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	SetCapture( );
	mouserightdown = TRUE;
	mouseprevpoint.x = point.x;
	mouseprevpoint.y = point.y;
	
	CView::OnRButtonDown(nFlags, point);
}

void CMy3DSLoaderView::OnMouseMove(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	
	if(mouserightdown)
	{
		SetCamPos(2, -(point.y - mouseprevpoint.y) , TRUE,TRUE);//���������λ��
	}
	else if(mouseleftdown)
	{	
		SetSceneRot(0, (point.y - mouseprevpoint.y) , TRUE,TRUE);
		SetSceneRot(2, (point.x - mouseprevpoint.x) , TRUE,TRUE);
	}
	CView::OnMouseMove(nFlags, point);

	mouseprevpoint.x = point.x;
	mouseprevpoint.y = point.y;	
	CView::OnMouseMove(nFlags, point);
}

void CMy3DSLoaderView::OnLButtonUp(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	ReleaseCapture( );
	mouseleftdown = FALSE;
	SetSceneRot(0, (point.y - mouseprevpoint.y) , TRUE, TRUE);
	SetSceneRot(2, (point.x - mouseprevpoint.x) , TRUE, TRUE);
	
	CView::OnLButtonUp(nFlags, point);
}

void CMy3DSLoaderView::OnLButtonDown(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	SetCapture( );
	mouseleftdown = TRUE;
	mouseprevpoint.x = point.x;
	mouseprevpoint.y = point.y;	
	CView::OnLButtonDown(nFlags, point);
}
//////////////////////////////////////////////////////////////////////////
//			���������λ��
//////////////////////////////////////////////////////////////////////////
void CMy3DSLoaderView::SetCamPos(int axis, int value, BOOL increment, BOOL apply)
{//���������λ��
	if(increment)
	{
		camPos[axis] += (float)value*camPos[axis]/100;
	}
	else
	{
		camPos[axis] = (float)value/2;
	}

	::glMatrixMode(GL_MODELVIEW);
	::glLoadIdentity();

	RenderScene();

}
//////////////////////////////////////////////////////////////////////////
//			����������Ƕ�
//////////////////////////////////////////////////////////////////////////
void CMy3DSLoaderView::SetSceneRot(int axis, int value, BOOL increment, BOOL apply)
{
	if (increment)
	{
		camRot[axis] += (camRot[axis] >= 360) ? (-360 + value / 2) : value / 2;
	}
	else
	{
		camRot[axis] = (camRot[axis] >= 360) ? (-360 + value / 2) : value / 2;
	}		
	RenderScene();
}
//////////////////////////////////////////////////////////////////////////
//			��3ds�ļ�
//////////////////////////////////////////////////////////////////////////
BOOL CMy3DSLoaderView::OpenFile(CRobotHand& ctl,LPCTSTR lpszPathName)
{
	char* file = new char[strlen(lpszPathName)];
	strcpy(file, lpszPathName);

	C3dsReader Loader;
	BOOL result;
	//if( m_RobotHand.getNumObjects() > 0 ) m_RobotHand.removeAllObjects();

	result = Loader.Reader(file, &ctl);
	if (result)
	{
		m_3dsLoaded = TRUE;
		ctl.doAfterMath();

	}

	return result;
}

//////////////////////////////////////////////////////////////////////////
//			����
//////////////////////////////////////////////////////////////////////////
/*ץ����*/
void CMy3DSLoaderView::OnGrab(){
	/*ץȡ*/
	//��ָ
	int choice[5] = { 0,0,1,0,0 };
	float* res = m_RobotHand.CalculateThetaByCoordinate(tVector(0.669, 125.957, -40.0), choice);
	CString str;
	float angle0 = -(*res);
	float angle1 = -*(res + 1);
	float angle2 = *(res + 2);
	float angle3 = *(res + 3);
	str.Format("%f,%f,%f,%f", angle0, angle1, angle2, angle3);
	//	PublicFuntoinHelper::ShowMessage(str);

	m_RobotHand.Middle1_Rotate(angle0);
	m_RobotHand.Middle2_Rotate(angle1);
	m_RobotHand.Middle3_Rotate(angle1 + angle2);
	m_RobotHand.Middle4_Rotate(angle1 + angle2 + angle3);

	m_RobotHand.Middle1_Rotate_r(angle0); //���ֲ���
	m_RobotHand.Middle2_Rotate_r(angle1);
	m_RobotHand.Middle3_Rotate_r(angle1 + angle2);
	m_RobotHand.Middle4_Rotate_r(angle1 + angle2 + angle3);

	//����ָ
	choice[3] = 1; choice[2] = 0;
	res = m_RobotHand.CalculateThetaByCoordinate(tVector(-23.204, 125.957, -40.0), choice);

	angle0 = -(*res);
	angle1 = -*(res + 1);
	angle2 = *(res + 2);
	angle3 = *(res + 3);
	str.Format("%f,%f,%f,%f", angle0, angle1, angle2, angle3);
	//	PublicFuntoinHelper::ShowMessage(str);

	m_RobotHand.Ring1_Rotate(angle0);
	m_RobotHand.Ring2_Rotate(angle1);
	m_RobotHand.Ring3_Rotate(angle1 + angle2);
	m_RobotHand.Ring4_Rotate(angle1 + angle2 + angle3);

	m_RobotHand.Ring1_Rotate_r(angle0); //���ֲ���
	m_RobotHand.Ring2_Rotate_r(angle1);
	m_RobotHand.Ring3_Rotate_r(angle1 + angle2);
	m_RobotHand.Ring4_Rotate_r(angle1 + angle2 + angle3);

	//ʳָ
	choice[1] = 1; choice[3] = 0;
	res = m_RobotHand.CalculateThetaByCoordinate(tVector(20.941, 125.957, -40.0), choice);

	angle0 = -(*res);
	angle1 = -*(res + 1);
	angle2 = *(res + 2);
	angle3 = *(res + 3);
	str.Format("%f,%f,%f,%f", angle0, angle1, angle2, angle3);
	//	PublicFuntoinHelper::ShowMessage(str);

	m_RobotHand.Index1_Rotate(angle0);
	m_RobotHand.Index2_Rotate(angle1);
	m_RobotHand.Index3_Rotate(angle1 + angle2);
	m_RobotHand.Index4_Rotate(angle1 + angle2 + angle3);

	m_RobotHand.Index1_Rotate_r(angle0);
	m_RobotHand.Index2_Rotate_r(angle1);
	m_RobotHand.Index3_Rotate_r(angle1 + angle2);
	m_RobotHand.Index4_Rotate_r(angle1 + angle2 + angle3);
	
	//Сָ
	choice[4] = 1; choice[1] = 0;
	res = m_RobotHand.CalculateThetaByCoordinate(tVector(-43.541, 125.957, -40.0), choice);

	angle0 = -(*res);
	angle1 = -*(res + 1);
	angle2 = *(res + 2);
	angle3 = *(res + 3);
	str.Format("%f,%f,%f,%f", angle0, angle1, angle2, angle3);
	//	PublicFuntoinHelper::ShowMessage(str);

	m_RobotHand.Little1_Rotate(angle0);
	m_RobotHand.Little2_Rotate(angle1);
	m_RobotHand.Little3_Rotate(angle1 + angle2);
	m_RobotHand.Little4_Rotate(angle1 + angle2 + angle3);

	m_RobotHand.Little1_Rotate_r(angle0);
	m_RobotHand.Little2_Rotate_r(angle1);
	m_RobotHand.Little3_Rotate_r(angle1 + angle2);
	m_RobotHand.Little4_Rotate_r(angle1 + angle2 + angle3);

	//��Ĵָ�������
	m_RobotHand.Thumb1_Rotate(5);
	m_RobotHand.Thumb2_Rotate(10);
	m_RobotHand.Thumb3_Rotate(60);
	m_RobotHand.Thumb4_Rotate(90);

	m_RobotHand.Thumb1_Rotate_r(5);
	m_RobotHand.Thumb2_Rotate_r(10);
	m_RobotHand.Thumb3_Rotate_r(60);
	m_RobotHand.Thumb4_Rotate_r(90);

	m_RobotHand.Thumb_Rotate_b(40);
	m_RobotHand.Thumb_Rotate_br(40);

	m_RobotHand.drawGL();
	RenderScene();
}
/*�ƶ���*/
void CMy3DSLoaderView::OnPush() {
	//��Ĵָ�������
	m_RobotHand.Thumb1_Rotate(-20);
	m_RobotHand.Thumb2_Rotate(-20);
	m_RobotHand.Thumb3_Rotate(20);
	m_RobotHand.Thumb4_Rotate(25);

	m_RobotHand.Thumb1_Rotate_r(-20);
	m_RobotHand.Thumb2_Rotate_r(-20);
	m_RobotHand.Thumb3_Rotate_r(20);
	m_RobotHand.Thumb4_Rotate_r(25);
	//ʳָ
	m_RobotHand.Index1_Rotate(-5);
	m_RobotHand.Index2_Rotate(-15);
	m_RobotHand.Index3_Rotate(15);
	m_RobotHand.Index4_Rotate(15);

	m_RobotHand.Index1_Rotate_r(-5);
	m_RobotHand.Index2_Rotate_r(-15);
	m_RobotHand.Index3_Rotate_r(15);
	m_RobotHand.Index4_Rotate_r(15);
	//��ָ
	m_RobotHand.Middle1_Rotate(0);
	m_RobotHand.Middle2_Rotate(-15);
	m_RobotHand.Middle3_Rotate(15);
	m_RobotHand.Middle4_Rotate(15);

	m_RobotHand.Middle1_Rotate_r(0);
	m_RobotHand.Middle2_Rotate_r(-15);
	m_RobotHand.Middle3_Rotate_r(15);
	m_RobotHand.Middle4_Rotate_r(15);
	
	//����ָ
	m_RobotHand.Ring1_Rotate(5);
	m_RobotHand.Ring2_Rotate(-15);
	m_RobotHand.Ring3_Rotate(15);
	m_RobotHand.Ring4_Rotate(15);

	m_RobotHand.Ring1_Rotate_r(5);
	m_RobotHand.Ring2_Rotate_r(-15);
	m_RobotHand.Ring3_Rotate_r(15);
	m_RobotHand.Ring4_Rotate_r(15);
	
	//Сָ
	m_RobotHand.Little1_Rotate(5);
	m_RobotHand.Little2_Rotate(-15);
	m_RobotHand.Little3_Rotate(15);
	m_RobotHand.Little4_Rotate(15);

	m_RobotHand.Little1_Rotate_r(5);
	m_RobotHand.Little2_Rotate_r(-15);
	m_RobotHand.Little3_Rotate_r(15);
	m_RobotHand.Little4_Rotate_r(15);

	m_RobotHand.drawGL();
	RenderScene();
}
/*�ж���*/
void CMy3DSLoaderView::OnClamp() {
	/*��Ĵָ�˶�*/
	m_RobotHand.Thumb1_Rotate(5);
	m_RobotHand.Thumb3_Rotate(50);
	m_RobotHand.Thumb4_Rotate(50);

	m_RobotHand.Thumb1_Rotate_r(5);
	m_RobotHand.Thumb3_Rotate_r(50);
	m_RobotHand.Thumb4_Rotate_r(50);

	m_RobotHand.Thumb_Rotate_b(60);
	m_RobotHand.Thumb_Rotate_br(60);

	/*ץȡ*/
	//��ָ
	int choice[5] = { 0,0,1,0,0 };
	float* res = m_RobotHand.CalculateThetaByCoordinate(tVector(14.669, 180.957, -40.0), choice);
	CString str;
	float angle0 = -(*res);
	float angle1 = -*(res + 1);
	float angle2 = *(res + 2);
	float angle3 = *(res + 3);
	str.Format("%f,%f,%f,%f", angle0, angle1, angle2, angle3);
	//	PublicFuntoinHelper::ShowMessage(str);

	m_RobotHand.Middle1_Rotate(angle0);
	m_RobotHand.Middle2_Rotate(angle1);
	m_RobotHand.Middle3_Rotate(angle1 + angle2);
	m_RobotHand.Middle4_Rotate(angle1 + angle2 + angle3);

	m_RobotHand.Middle1_Rotate_r(angle0); //���ֲ���
	m_RobotHand.Middle2_Rotate_r(angle1);
	m_RobotHand.Middle3_Rotate_r(angle1 + angle2);
	m_RobotHand.Middle4_Rotate_r(angle1 + angle2 + angle3);

	//����ָ
	choice[3] = 1; choice[2] = 0;
	res = m_RobotHand.CalculateThetaByCoordinate(tVector(-9.204, 170.957, -40.0), choice);

	angle0 = -(*res);
	angle1 = -*(res + 1);
	angle2 = *(res + 2);
	angle3 = *(res + 3);
	str.Format("%f,%f,%f,%f", angle0, angle1, angle2, angle3);
	//	PublicFuntoinHelper::ShowMessage(str);

	m_RobotHand.Ring1_Rotate(angle0);
	m_RobotHand.Ring2_Rotate(angle1);
	m_RobotHand.Ring3_Rotate(angle1 + angle2);
	m_RobotHand.Ring4_Rotate(angle1 + angle2 + angle3);

	m_RobotHand.Ring1_Rotate_r(angle0); //���ֲ���
	m_RobotHand.Ring2_Rotate_r(angle1);
	m_RobotHand.Ring3_Rotate_r(angle1 + angle2);
	m_RobotHand.Ring4_Rotate_r(angle1 + angle2 + angle3);

	//ʳָ
	choice[1] = 1; choice[3] = 0;
	res = m_RobotHand.CalculateThetaByCoordinate(tVector(34.941, 125.957, -40.0), choice);

	angle0 = -(*res);
	angle1 = -*(res + 1);
	angle2 = *(res + 2);
	angle3 = *(res + 3);
	str.Format("%f,%f,%f,%f", angle0, angle1, angle2, angle3);
	//	PublicFuntoinHelper::ShowMessage(str);

	m_RobotHand.Index1_Rotate(angle0);
	m_RobotHand.Index2_Rotate(angle1);
	m_RobotHand.Index3_Rotate(angle1 + angle2);
	m_RobotHand.Index4_Rotate(angle1 + angle2 + angle3);

	m_RobotHand.Index1_Rotate_r(angle0);
	m_RobotHand.Index2_Rotate_r(angle1);
	m_RobotHand.Index3_Rotate_r(angle1 + angle2);
	m_RobotHand.Index4_Rotate_r(angle1 + angle2 + angle3);

	//Сָ
	choice[4] = 1; choice[1] = 0;
	res = m_RobotHand.CalculateThetaByCoordinate(tVector(-29.541, 130.957, -40.0), choice);

	angle0 = -(*res);
	angle1 = -*(res + 1);
	angle2 = *(res + 2);
	angle3 = *(res + 3);
	str.Format("%f,%f,%f,%f", angle0, angle1, angle2, angle3);
	//	PublicFuntoinHelper::ShowMessage(str);

	m_RobotHand.Little1_Rotate(angle0);
	m_RobotHand.Little2_Rotate(angle1);
	m_RobotHand.Little3_Rotate(angle1 + angle2);
	m_RobotHand.Little4_Rotate(angle1 + angle2 + angle3);

	m_RobotHand.Little1_Rotate_r(angle0);
	m_RobotHand.Little2_Rotate_r(angle1);
	m_RobotHand.Little3_Rotate_r(angle1 + angle2);
	m_RobotHand.Little4_Rotate_r(angle1 + angle2 + angle3);

	m_RobotHand.drawGL();
	RenderScene();
	
}
/*��*/
void CMy3DSLoaderView::OnFist() {
	//��ָ
	int choice[5] = { 0,0,1,0,0 };
	float* res = m_RobotHand.CalculateThetaByCoordinate(tVector(0.669, 30.0, -40.0), choice);
	CString str;
	float angle0 = -(*res);
	float angle1 = -*(res + 1);
	float angle2 = *(res + 2);
	float angle3 = *(res + 3);

	m_RobotHand.Middle1_Rotate(angle0);
	m_RobotHand.Middle2_Rotate(angle1);
	m_RobotHand.Middle3_Rotate(angle1 + angle2);
	m_RobotHand.Middle4_Rotate(angle1 + angle2 + angle3);

	m_RobotHand.Middle1_Rotate_r(angle0); //���ֲ���
	m_RobotHand.Middle2_Rotate_r(angle1);
	m_RobotHand.Middle3_Rotate_r(angle1 + angle2);
	m_RobotHand.Middle4_Rotate_r(angle1 + angle2 + angle3);

	//����ָ
	choice[3] = 1; choice[2] = 0;
	res = m_RobotHand.CalculateThetaByCoordinate(tVector(-23.204, 30.0, -20.0), choice);

	angle0 = -(*res);
	angle1 = -*(res + 1);
	angle2 = *(res + 2);
	angle3 = *(res + 3);

	m_RobotHand.Ring1_Rotate(angle0);
	m_RobotHand.Ring2_Rotate(angle1);
	m_RobotHand.Ring3_Rotate(angle1 + angle2);
	m_RobotHand.Ring4_Rotate(angle1 + angle2 + angle3);

	m_RobotHand.Ring1_Rotate_r(angle0); //���ֲ���
	m_RobotHand.Ring2_Rotate_r(angle1);
	m_RobotHand.Ring3_Rotate_r(angle1 + angle2);
	m_RobotHand.Ring4_Rotate_r(angle1 + angle2 + angle3);

	//ʳָ
	choice[1] = 1; choice[3] = 0;
	res = m_RobotHand.CalculateThetaByCoordinate(tVector(20.941, 30.0, -20.0), choice);

	angle0 = -(*res);
	angle1 = -*(res + 1);
	angle2 = *(res + 2);
	angle3 = *(res + 3);

	m_RobotHand.Index1_Rotate(angle0);
	m_RobotHand.Index2_Rotate(angle1);
	m_RobotHand.Index3_Rotate(angle1 + angle2);
	m_RobotHand.Index4_Rotate(angle1 + angle2 + angle3);

	m_RobotHand.Index1_Rotate_r(angle0);
	m_RobotHand.Index2_Rotate_r(angle1);
	m_RobotHand.Index3_Rotate_r(angle1 + angle2);
	m_RobotHand.Index4_Rotate_r(angle1 + angle2 + angle3);
	//Сָ
	choice[4] = 1; choice[1] = 0;
	res = m_RobotHand.CalculateThetaByCoordinate(tVector(-43.541, 30.0, -30.0), choice);

	angle0 = -(*res);
	angle1 = -*(res + 1);
	angle2 = *(res + 2);
	angle3 = *(res + 3);

	m_RobotHand.Little1_Rotate(angle0);
	m_RobotHand.Little2_Rotate(angle1);
	m_RobotHand.Little3_Rotate(angle1 + angle2);
	m_RobotHand.Little4_Rotate(angle1 + angle2 + angle3);

	m_RobotHand.Little1_Rotate_r(angle0);
	m_RobotHand.Little2_Rotate_r(angle1);
	m_RobotHand.Little3_Rotate_r(angle1 + angle2);
	m_RobotHand.Little4_Rotate_r(angle1 + angle2 + angle3);

	//��Ĵָ
	choice[0] = 1; choice[4] = 0;
	res = m_RobotHand.CalculateThetaByCoordinate(tVector(46.186, 30.0, -20.0), choice);

	angle0 = -(*res);
	angle1 = -*(res + 1);
	angle2 = *(res + 2);
	angle3 = *(res + 3);

	m_RobotHand.Thumb1_Rotate(angle0);
	m_RobotHand.Thumb2_Rotate(angle1);
	m_RobotHand.Thumb3_Rotate(angle1 + angle2);
	m_RobotHand.Thumb4_Rotate(angle1 + angle2 + angle3);

	m_RobotHand.Thumb1_Rotate_r(angle0);
	m_RobotHand.Thumb2_Rotate_r(angle1);
	m_RobotHand.Thumb3_Rotate_r(angle1 + angle2);
	m_RobotHand.Thumb4_Rotate_r(angle1 + angle2 + angle3);

	m_RobotHand.Thumb_Rotate_b(30);
	m_RobotHand.Thumb_Rotate_br(30);
	m_RobotHand.drawGL();
	RenderScene();
}
/*��*/
void CMy3DSLoaderView::OnPull() {
	//ʳָ
	m_RobotHand.Index3_Rotate(60);
	m_RobotHand.Index4_Rotate(90);

	m_RobotHand.Index3_Rotate_r(60);
	m_RobotHand.Index4_Rotate_r(90);

	//��ָ
	m_RobotHand.Middle3_Rotate(60);
	m_RobotHand.Middle4_Rotate(90);
	m_RobotHand.Middle3_Rotate_r(60);
	m_RobotHand.Middle4_Rotate_r(90);

	//����ָ
	m_RobotHand.Ring3_Rotate(60);
	m_RobotHand.Ring4_Rotate(90);
	m_RobotHand.Ring3_Rotate_r(60);
	m_RobotHand.Ring4_Rotate_r(90);

	//Сָ
	m_RobotHand.Little3_Rotate(60);
	m_RobotHand.Little4_Rotate(90);
	m_RobotHand.Little3_Rotate_r(60);
	m_RobotHand.Little4_Rotate_r(90);

	//��Ĵָ�������
	m_RobotHand.Thumb3_Rotate(20);
	m_RobotHand.Thumb4_Rotate(25);
	m_RobotHand.Thumb3_Rotate_r(20);
	m_RobotHand.Thumb4_Rotate_r(25);

	m_RobotHand.Thumb_Rotate_b(70);
	m_RobotHand.Thumb_Rotate_br(70);
	m_RobotHand.drawGL();
	RenderScene();
}
/*��*/
void CMy3DSLoaderView::OnInsert() {
	/*��Ĵָ�˶�*/
	m_RobotHand.Thumb1_Rotate(5);
	m_RobotHand.Thumb3_Rotate(50);
	m_RobotHand.Thumb4_Rotate(50);
	m_RobotHand.Thumb_Rotate_b(60);

	/*����ץȡ*/
	//��ָ
	int choice[5] = { 0,0,1,0,0 };
	float* res = m_RobotHand.CalculateThetaByCoordinate(tVector(14.669, 150.957, -40.0), choice);
	CString str;
	float angle0 = -(*res);
	float angle1 = -*(res + 1);
	float angle2 = *(res + 2);
	float angle3 = *(res + 3);
	m_RobotHand.Middle1_Rotate(angle0);
	m_RobotHand.Middle2_Rotate(angle1);
	m_RobotHand.Middle3_Rotate(angle1 + angle2);
	m_RobotHand.Middle4_Rotate(angle1 + angle2 + angle3);

	//����ָ
	choice[3] = 1; choice[2] = 0;
	res = m_RobotHand.CalculateThetaByCoordinate(tVector(-9.204, 150.957, -40.0), choice);
	angle0 = -(*res);
	angle1 = -*(res + 1);
	angle2 = *(res + 2);
	angle3 = *(res + 3);
	m_RobotHand.Ring1_Rotate(angle0);
	m_RobotHand.Ring2_Rotate(angle1);
	m_RobotHand.Ring3_Rotate(angle1 + angle2);
	m_RobotHand.Ring4_Rotate(angle1 + angle2 + angle3);

	//ʳָ
	choice[1] = 1; choice[3] = 0;
	res = m_RobotHand.CalculateThetaByCoordinate(tVector(34.941, 125.957, -40.0), choice);
	angle0 = -(*res);
	angle1 = -*(res + 1);
	angle2 = *(res + 2);
	angle3 = *(res + 3);
	m_RobotHand.Index1_Rotate(angle0);
	m_RobotHand.Index2_Rotate(angle1);
	m_RobotHand.Index3_Rotate(angle1 + angle2);
	m_RobotHand.Index4_Rotate(angle1 + angle2 + angle3);

	//Сָ
	choice[4] = 1; choice[1] = 0;
	res = m_RobotHand.CalculateThetaByCoordinate(tVector(-29.541, 130.957, -40.0), choice);
	angle0 = -(*res);
	angle1 = -*(res + 1);
	angle2 = *(res + 2);
	angle3 = *(res + 3);
	m_RobotHand.Little1_Rotate(angle0);
	m_RobotHand.Little2_Rotate(angle1);
	m_RobotHand.Little3_Rotate(angle1 + angle2);
	m_RobotHand.Little4_Rotate(angle1 + angle2 + angle3);

	//��Ĵָ�������
	m_RobotHand.Thumb2_Rotate_r(60);
	m_RobotHand.Thumb3_Rotate_r(120);
	m_RobotHand.Thumb4_Rotate_r(130);

	m_RobotHand.Thumb_Rotate_br(50);
	//ʳָ
	m_RobotHand.Index2_Rotate_r(60);
	m_RobotHand.Index3_Rotate_r(120);
	m_RobotHand.Index4_Rotate_r(160);
	//��ָ
	m_RobotHand.Middle2_Rotate_r(60);
	m_RobotHand.Middle3_Rotate_r(120);
	m_RobotHand.Middle4_Rotate_r(160);

	//����ָ
	m_RobotHand.Ring2_Rotate_r(60);
	m_RobotHand.Ring3_Rotate_r(120);
	m_RobotHand.Ring4_Rotate_r(160);

	//Сָ
	m_RobotHand.Little2_Rotate_r(60);
	m_RobotHand.Little3_Rotate_r(120);
	m_RobotHand.Little4_Rotate_r(160);
	m_RobotHand.drawGL();
	RenderScene();
}
/*��*/
void CMy3DSLoaderView::OnSupport() {
	//ʳָ
	m_RobotHand.Index3_Rotate(30);
	m_RobotHand.Index4_Rotate(60);

	m_RobotHand.Index3_Rotate_r(30);
	m_RobotHand.Index4_Rotate_r(60);

	//��ָ
	m_RobotHand.Middle3_Rotate(30);
	m_RobotHand.Middle4_Rotate(60);
	m_RobotHand.Middle3_Rotate_r(30);
	m_RobotHand.Middle4_Rotate_r(60);

	//����ָ
	m_RobotHand.Ring3_Rotate(30);
	m_RobotHand.Ring4_Rotate(60);
	m_RobotHand.Ring3_Rotate_r(30);
	m_RobotHand.Ring4_Rotate_r(60);

	//Сָ
	m_RobotHand.Little3_Rotate(30);
	m_RobotHand.Little4_Rotate(60);
	m_RobotHand.Little3_Rotate_r(30);
	m_RobotHand.Little4_Rotate_r(60);

	//��Ĵָ�������
	m_RobotHand.Thumb1_Rotate(30);
	m_RobotHand.Thumb3_Rotate(30);
	m_RobotHand.Thumb4_Rotate(30);
	m_RobotHand.Thumb1_Rotate_r(30);
	m_RobotHand.Thumb3_Rotate_r(30);
	m_RobotHand.Thumb4_Rotate_r(30);

	m_RobotHand.Thumb_Rotate_b(30);
	m_RobotHand.Thumb_Rotate_br(30);
	m_RobotHand.drawGL();
	RenderScene();
}
/*��*/
void CMy3DSLoaderView::OnSqueeze() {
	//��Ĵָ�������
	m_RobotHand.Thumb1_Rotate(-10);
	m_RobotHand.Thumb2_Rotate(30);
	m_RobotHand.Thumb3_Rotate(60);
	m_RobotHand.Thumb4_Rotate(130);

	m_RobotHand.Thumb_Rotate_b(30);
	//ʳָ
	m_RobotHand.Index1_Rotate(-10);
	m_RobotHand.Index2_Rotate(60);
	m_RobotHand.Index3_Rotate(120);
	m_RobotHand.Index4_Rotate(200);
	//��ָ
	m_RobotHand.Middle2_Rotate(60);
	m_RobotHand.Middle3_Rotate(120);
	m_RobotHand.Middle4_Rotate(200);

	//����ָ
	m_RobotHand.Ring1_Rotate(10);
	m_RobotHand.Ring2_Rotate(60);
	m_RobotHand.Ring3_Rotate(120);
	m_RobotHand.Ring4_Rotate(200);

	//Сָ
	m_RobotHand.Little1_Rotate(10);
	m_RobotHand.Little2_Rotate(60);
	m_RobotHand.Little3_Rotate(120);
	m_RobotHand.Little4_Rotate(200);

	//���ִ�Ĵָ�������
	m_RobotHand.Thumb1_Rotate_r(-10);
	m_RobotHand.Thumb2_Rotate_r(30);
	m_RobotHand.Thumb3_Rotate_r(60);
	m_RobotHand.Thumb4_Rotate_r(130);

	m_RobotHand.Thumb_Rotate_br(30);
	//ʳָ
	m_RobotHand.Index1_Rotate_r(-10);
	m_RobotHand.Index2_Rotate_r(60);
	m_RobotHand.Index3_Rotate_r(120);
	m_RobotHand.Index4_Rotate_r(200);
	//��ָ
	m_RobotHand.Middle2_Rotate_r(60);
	m_RobotHand.Middle3_Rotate_r(120);
	m_RobotHand.Middle4_Rotate_r(200);

	//����ָ
	m_RobotHand.Ring1_Rotate_r(10);
	m_RobotHand.Ring2_Rotate_r(60);
	m_RobotHand.Ring3_Rotate_r(120);
	m_RobotHand.Ring4_Rotate_r(200);

	//Сָ
	m_RobotHand.Little1_Rotate_r(10);
	m_RobotHand.Little2_Rotate_r(60);
	m_RobotHand.Little3_Rotate_r(120);
	m_RobotHand.Little4_Rotate_r(200);
	m_RobotHand.drawGL();
	RenderScene();
}
/*��*/
void CMy3DSLoaderView::OnCut() 
{	
	//��Ĵָ�������
	m_RobotHand.Thumb1_Rotate(-10);
	m_RobotHand.Thumb2_Rotate(30);
	m_RobotHand.Thumb3_Rotate(90);
	m_RobotHand.Thumb4_Rotate(90);

	m_RobotHand.Thumb_Rotate_b(100);
	
	//ʳָ
	m_RobotHand.Index1_Rotate(-2);
	m_RobotHand.Index2_Rotate(-5);
	m_RobotHand.Index3_Rotate(10);
	m_RobotHand.Index4_Rotate(10);
	//��ָ
	m_RobotHand.Middle2_Rotate(-5);
	m_RobotHand.Middle3_Rotate(10);
	m_RobotHand.Middle4_Rotate(10);

	//����ָ
	m_RobotHand.Ring1_Rotate(2);
	m_RobotHand.Ring2_Rotate(-5);
	m_RobotHand.Ring3_Rotate(10);
	m_RobotHand.Ring4_Rotate(10);

	//Сָ
	m_RobotHand.Little1_Rotate(4);
	m_RobotHand.Little2_Rotate(-5);
	m_RobotHand.Little3_Rotate(10);
	m_RobotHand.Little4_Rotate(10);

	/*�����ü���*/
	//��ָ
	m_RobotHand.Middle2_Rotate_r(10);
	m_RobotHand.Middle3_Rotate_r(80);
	m_RobotHand.Middle4_Rotate_r(160);

	//����ָ
	m_RobotHand.Ring2_Rotate_r(10);
	m_RobotHand.Ring3_Rotate_r(80);
	m_RobotHand.Ring4_Rotate_r(160);

	//Сָ
	m_RobotHand.Little2_Rotate_r(10);
	m_RobotHand.Little3_Rotate_r(80);
	m_RobotHand.Little4_Rotate_r(160);

	//��Ĵָ�������
	m_RobotHand.Thumb1_Rotate_r(-10);
	m_RobotHand.Thumb3_Rotate_r(60);
	m_RobotHand.Thumb4_Rotate_r(80);

	m_RobotHand.Thumb_Rotate_br(60);
	// ʳָ
	m_RobotHand.Index3_Rotate_r(20);
	m_RobotHand.Index4_Rotate_r(30);

	m_RobotHand.drawGL();
	RenderScene();
}
/*˺*/
void CMy3DSLoaderView::OnRip()
{
	//��ָ
	int choice[5] = { 0,0,1,0,0 };
	float* res = m_RobotHand.CalculateThetaByCoordinate(tVector(0.669, 30, -40.0), choice);
	CString str;
	float angle0 = -(*res);
	float angle1 = -*(res + 1);
	float angle2 = *(res + 2);
	float angle3 = *(res + 3);
	m_RobotHand.Middle1_Rotate(angle0);
	m_RobotHand.Middle2_Rotate(angle1);
	m_RobotHand.Middle3_Rotate(angle1 + angle2);
	m_RobotHand.Middle4_Rotate(angle1 + angle2 + angle3);

	m_RobotHand.Middle1_Rotate_r(angle0);
	m_RobotHand.Middle2_Rotate_r(angle1);
	m_RobotHand.Middle3_Rotate_r(angle1 + angle2);
	m_RobotHand.Middle4_Rotate_r(angle1 + angle2 + angle3);

	//����ָ
	choice[3] = 1; choice[2] = 0;
	res = m_RobotHand.CalculateThetaByCoordinate(tVector(-23.204, 30, -20.0), choice);
	angle0 = -(*res);
	angle1 = -*(res + 1);
	angle2 = *(res + 2);
	angle3 = *(res + 3);
	m_RobotHand.Ring1_Rotate(angle0); //���ֲ���
	m_RobotHand.Ring2_Rotate(angle1);
	m_RobotHand.Ring3_Rotate(angle1 + angle2);
	m_RobotHand.Ring4_Rotate(angle1 + angle2 + angle3);

	m_RobotHand.Ring1_Rotate_r(angle0); //���ֲ���
	m_RobotHand.Ring2_Rotate_r(angle1);
	m_RobotHand.Ring3_Rotate_r(angle1 + angle2);
	m_RobotHand.Ring4_Rotate_r(angle1 + angle2 + angle3);

	//Сָ
	choice[4] = 1; choice[3] = 0;
	res = m_RobotHand.CalculateThetaByCoordinate(tVector(-43.541, 30, -20.0), choice);

	angle0 = -(*res);
	angle1 = -*(res + 1);
	angle2 = *(res + 2);
	angle3 = *(res + 3);
	m_RobotHand.Little1_Rotate(angle0);
	m_RobotHand.Little2_Rotate(angle1);
	m_RobotHand.Little3_Rotate(angle1 + angle2);
	m_RobotHand.Little4_Rotate(angle1 + angle2 + angle3);

	m_RobotHand.Little1_Rotate_r(angle0);
	m_RobotHand.Little2_Rotate_r(angle1);
	m_RobotHand.Little3_Rotate_r(angle1 + angle2);
	m_RobotHand.Little4_Rotate_r(angle1 + angle2 + angle3);


	//��Ĵָ
	m_RobotHand.Thumb1_Rotate(-10);
	m_RobotHand.Thumb3_Rotate(30);
	m_RobotHand.Thumb4_Rotate(40);

	m_RobotHand.Thumb1_Rotate_r(-10);
	m_RobotHand.Thumb3_Rotate_r(30);
	m_RobotHand.Thumb4_Rotate_r(40);

	m_RobotHand.Thumb_Rotate_b(60);
	m_RobotHand.Thumb_Rotate_br(60);
	
	//ʳָ
	m_RobotHand.Index1_Rotate(-12);
	m_RobotHand.Index2_Rotate(-10);
	m_RobotHand.Index3_Rotate(80);
	m_RobotHand.Index4_Rotate(100);

	m_RobotHand.Index1_Rotate_r(-12);
	m_RobotHand.Index2_Rotate_r(-10);
	m_RobotHand.Index3_Rotate_r(80);
	m_RobotHand.Index4_Rotate_r(100);

	m_RobotHand.drawGL();
	RenderScene();
}
/*ǯ*/
void CMy3DSLoaderView::OnTongs() 
{
	//��ָ
	int choice[5] = { 0,0,1,0,0 };
	float* res = m_RobotHand.CalculateThetaByCoordinate(tVector(0.669, 30, -40.0), choice);
	CString str;
	float angle0 = -(*res);
	float angle1 = -*(res + 1);
	float angle2 = *(res + 2);
	float angle3 = *(res + 3);
	m_RobotHand.Middle1_Rotate(angle0);
	m_RobotHand.Middle2_Rotate(angle1);
	m_RobotHand.Middle3_Rotate(angle1 + angle2);
	m_RobotHand.Middle4_Rotate(angle1 + angle2 + angle3);

	//����ָ
	choice[3] = 1; choice[2] = 0;
	res = m_RobotHand.CalculateThetaByCoordinate(tVector(-23.204, 30, -20.0), choice);
	angle0 = -(*res);
	angle1 = -*(res + 1);
	angle2 = *(res + 2);
	angle3 = *(res + 3);
	m_RobotHand.Ring1_Rotate(angle0); //���ֲ���
	m_RobotHand.Ring2_Rotate(angle1);
	m_RobotHand.Ring3_Rotate(angle1 + angle2);
	m_RobotHand.Ring4_Rotate(angle1 + angle2 + angle3);

	//Сָ
	choice[4] = 1; choice[3] = 0;
	res = m_RobotHand.CalculateThetaByCoordinate(tVector(-43.541, 30, -20.0), choice);

	angle0 = -(*res);
	angle1 = -*(res + 1);
	angle2 = *(res + 2);
	angle3 = *(res + 3);
	m_RobotHand.Little1_Rotate(angle0);
	m_RobotHand.Little2_Rotate(angle1);
	m_RobotHand.Little3_Rotate(angle1 + angle2);
	m_RobotHand.Little4_Rotate(angle1 + angle2 + angle3);

	//��Ĵָ
	m_RobotHand.Thumb1_Rotate(-10);
	m_RobotHand.Thumb3_Rotate(30);
	m_RobotHand.Thumb4_Rotate(40);
	m_RobotHand.Thumb_Rotate_b(60);

	//ʳָ
	m_RobotHand.Index1_Rotate(-12);
	m_RobotHand.Index2_Rotate(-10);
	m_RobotHand.Index3_Rotate(80);
	m_RobotHand.Index4_Rotate(100);
	/*������ǯ*/
	//��ָ
	m_RobotHand.Middle2_Rotate_r(10);
	m_RobotHand.Middle3_Rotate_r(80);
	m_RobotHand.Middle4_Rotate_r(160);

	//����ָ
	m_RobotHand.Ring2_Rotate_r(10);
	m_RobotHand.Ring3_Rotate_r(80);
	m_RobotHand.Ring4_Rotate_r(160);

	//Сָ
	m_RobotHand.Little2_Rotate_r(10);
	m_RobotHand.Little3_Rotate_r(80);
	m_RobotHand.Little4_Rotate_r(160);
	
	//��Ĵָ�������
	m_RobotHand.Thumb1_Rotate_r(-10);
	m_RobotHand.Thumb3_Rotate_r(60);
	m_RobotHand.Thumb4_Rotate_r(80);

	m_RobotHand.Thumb_Rotate_br(60);
	// ʳָ
	m_RobotHand.Index3_Rotate_r(20);
	m_RobotHand.Index4_Rotate_r(30);
	
	m_RobotHand.drawGL();
	RenderScene();
}

void CMy3DSLoaderView::OnReset()
{
	for (int i = 0; i < CGloableVariable::N; i++)
	{
		m_RobotHand.objects[i]->currentPos.x = CGloableVariable::defaultPos[i][0]-150;
		m_RobotHand.objects[i]->currentPos.y = CGloableVariable::defaultPos[i][1];
		m_RobotHand.objects[i]->currentPos.z = CGloableVariable::defaultPos[i][2];
	}
	int j = 0;
	for (int i = CGloableVariable::N; i < CGloableVariable::N + 21; i++)//���ֲ���
	{
		m_RobotHand.objects[i]->currentPos.x = CGloableVariable::defaultPos_r[j][0]-150;
		m_RobotHand.objects[i]->currentPos.y = CGloableVariable::defaultPos_r[j][1];
		m_RobotHand.objects[i]->currentPos.z = CGloableVariable::defaultPos_r[j][2];
		j++;

	}
	//���ֻ���
	for (int i = CGloableVariable::N+21,j=0; i < CGloableVariable::N + 23; i++,j++)//���ֲ���
	{
		m_RobotHand.objects[i]->currentPos.x = CGloableVariable::defaultPos_b[j][0] - 150;
		m_RobotHand.objects[i]->currentPos.y = CGloableVariable::defaultPos_b[j][1];
		m_RobotHand.objects[i]->currentPos.z = CGloableVariable::defaultPos_b[j][2];

	}

	for (int i = 0; i < CGloableVariable::N;i++)
	{
		if( i==1 || i==2 || i==3 || i==4 )
		{
			m_RobotHand.objects[i]->sceneRot[2]=m_RobotHand.ConvertAngleToRadian(60);
			m_RobotHand.objects[1]->angle=m_RobotHand.ConvertAngleToRadian(60);
		}
		else 
		m_RobotHand.objects[i]->sceneRot[2] =  0;
		m_RobotHand.objects[i]->sceneRot[1] =  0;
		
		m_RobotHand.objects[i]->sceneRot[0] =  0;
		m_RobotHand.objects[i]->angle =  0;
	}

	for (int i = CGloableVariable::N; i < CGloableVariable::N+23; i++)
	{
		if (i == CGloableVariable::N+1 || i == CGloableVariable::N+2 || i == CGloableVariable::N+3 || i == CGloableVariable::N+4)
		{
			m_RobotHand.objects[i]->sceneRot[2] = m_RobotHand.ConvertAngleToRadian(60);
			m_RobotHand.objects[CGloableVariable::N+1]->angle = m_RobotHand.ConvertAngleToRadian(60);
		}
		else
		m_RobotHand.objects[i]->sceneRot[2] = 0;
		m_RobotHand.objects[i]->sceneRot[1] = 0;

		m_RobotHand.objects[i]->sceneRot[0] = 0;
		m_RobotHand.objects[i]->angle = 0;
	}

	m_RobotHand.drawGL();
	RenderScene();
	return;
}
void CMy3DSLoaderView::OnThumb()
{
	m_RobotHand.Thumb1_Rotate(10);
	m_RobotHand.Thumb2_Rotate(30);
	m_RobotHand.Thumb3_Rotate(60);
	m_RobotHand.Thumb4_Rotate(80);

	m_RobotHand.Thumb1_Rotate_r(10);
	m_RobotHand.Thumb2_Rotate_r(30);
	m_RobotHand.Thumb3_Rotate_r(60);
	m_RobotHand.Thumb4_Rotate_r(80);

	m_RobotHand.Thumb_Rotate_b(60);
	m_RobotHand.Thumb_Rotate_br(60);
	m_RobotHand.drawGL();
	RenderScene();

	return;
}
void CMy3DSLoaderView::OnThumbInverse()
{
//��һ������������������������ת�ġ�
	
		int choice[5]={1,0,0,0,0};
		float *res = m_RobotHand.CalculateThetaByCoordinate(tVector(46.186, 85.286, 60.0), choice);
		CString str;
		float angle0 = -(*res);
		float angle1 = -*(res + 1);
		float angle2 = *(res + 2);
		float angle3 = *(res + 3);
		str.Format("%f,%f,%f,%f", angle0, angle1, angle2, angle3);
		PublicFuntoinHelper::ShowMessage(str);
		m_RobotHand.Thumb1_Rotate(angle0);
		m_RobotHand.Thumb2_Rotate(angle1);
		m_RobotHand.Thumb3_Rotate(angle1 + angle2);
		m_RobotHand.Thumb4_Rotate(angle1 + angle2 + angle3);

		m_RobotHand.Thumb1_Rotate_r(angle0);
		m_RobotHand.Thumb2_Rotate_r(angle1);
		m_RobotHand.Thumb3_Rotate_r(angle1 + angle2);
		m_RobotHand.Thumb4_Rotate_r(angle1 + angle2 + angle3);

		m_RobotHand.drawGL();
		RenderScene();
	
}
void CMy3DSLoaderView::OnIndex()
{

	m_RobotHand.Index1_Rotate(20);
	m_RobotHand.Index2_Rotate(10);
	m_RobotHand.Index3_Rotate(10);
	m_RobotHand.Index4_Rotate(10);

	m_RobotHand.Index1_Rotate_r(10);//���ؽ�
	m_RobotHand.Index2_Rotate_r(10);
	m_RobotHand.Index3_Rotate_r(10);
	m_RobotHand.Index4_Rotate_r(10);

	m_RobotHand.drawGL();
	RenderScene();

	return;
}
void CMy3DSLoaderView::OnIndexInverse()
{
		int choice[5]={0,1,0,0,0};
		float* res= m_RobotHand.CalculateThetaByCoordinate(tVector(22.68,141.24,74.81),choice);
		CString str;
		float angle0= -(*res);
		float angle1= -*(res+1);
		float angle2= -*(res+2);
		float angle3= -*(res+3);
		str.Format("%f,%f,%f,%f",angle0 , angle1, angle2,angle3);
		PublicFuntoinHelper::ShowMessage(str);
	
		m_RobotHand.Index1_Rotate(angle0);
		m_RobotHand.Index2_Rotate(angle1);
		m_RobotHand.Index3_Rotate(angle1+angle2);
		m_RobotHand.Index4_Rotate(angle1+angle2+angle3);

		m_RobotHand.Index1_Rotate_r(angle0);
		m_RobotHand.Index2_Rotate_r(angle1);
		m_RobotHand.Index3_Rotate_r(angle1 + angle2);
		m_RobotHand.Index4_Rotate_r(angle1 + angle2 + angle3);
		
	return;
}
void CMy3DSLoaderView::OnMiddle()
{
	m_RobotHand.Middle1_Rotate(10);
	m_RobotHand.Middle2_Rotate(10);
	m_RobotHand.Middle3_Rotate(10);
	m_RobotHand.Middle4_Rotate(10);

	m_RobotHand.Middle1_Rotate_r(10);
	m_RobotHand.Middle2_Rotate_r(10);
	m_RobotHand.Middle3_Rotate_r(10);
	m_RobotHand.Middle4_Rotate_r(10);

	m_RobotHand.drawGL();
	RenderScene();

	return;
}
void CMy3DSLoaderView::OnMiddleInverse()
{	int choice[5]={0,0,1,0,0};
		float* res= m_RobotHand.CalculateThetaByCoordinate(tVector(22.68,141.24,74.81),choice);
		CString str;
		float angle0= (*res);	
		float angle1= -*(res+1);
		float angle2= -*(res+2);
		float angle3= -*(res+3);
		
		m_RobotHand.Middle1_Rotate(angle0);
		m_RobotHand.Middle2_Rotate(angle1);
		m_RobotHand.Middle3_Rotate(angle1+angle2);
		m_RobotHand.Middle4_Rotate(angle1+angle2+angle3);

		m_RobotHand.Middle1_Rotate_r(angle0);
		m_RobotHand.Middle2_Rotate_r(angle1);
		m_RobotHand.Middle3_Rotate_r(angle1 + angle2);
		m_RobotHand.Middle4_Rotate_r(angle1 + angle2 + angle3);
		m_RobotHand.drawGL();
		RenderScene();

		str.Format("%f,%f,%f,%f",angle0 , angle1, angle2,angle3);
		PublicFuntoinHelper::ShowMessage(str);
		
	return;
}
void CMy3DSLoaderView::OnRing()
{
	m_RobotHand.Ring1_Rotate(10);
	m_RobotHand.Ring2_Rotate(10);
	m_RobotHand.Ring3_Rotate(10);
	m_RobotHand.Ring4_Rotate(10);

	m_RobotHand.Ring1_Rotate_r(10);
	m_RobotHand.Ring2_Rotate_r(10);
	m_RobotHand.Ring3_Rotate_r(10);
	m_RobotHand.Ring4_Rotate_r(10);

	m_RobotHand.drawGL();
	RenderScene();

	return;
}
void CMy3DSLoaderView::OnRingInverse()
{	int choice[5]={0,0,0,1,0};
		float* res= m_RobotHand.CalculateThetaByCoordinate(tVector(22.68,141.24,74.81),choice);
		CString str;
		float angle0= (*res);
		float angle1= -*(res+1);
		float angle2= -*(res+2);
		float angle3= -*(res+3);
		str.Format("%f,%f,%f,%f",angle0 , angle1, angle2,angle3);
		PublicFuntoinHelper::ShowMessage(str);
		
		m_RobotHand.Ring1_Rotate(angle0);
		m_RobotHand.Ring2_Rotate(angle1);
		m_RobotHand.Ring3_Rotate(angle1+angle2);
		m_RobotHand.Ring4_Rotate(angle1+angle2+angle3);	

		m_RobotHand.Ring1_Rotate_r(angle0);
		m_RobotHand.Ring2_Rotate_r(angle1);
		m_RobotHand.Ring3_Rotate_r(angle1 + angle2);
		m_RobotHand.Ring4_Rotate_r(angle1 + angle2 + angle3);
		
	return;
	return;
}
void CMy3DSLoaderView::OnLittle()
{
	m_RobotHand.Little1_Rotate(10);
	m_RobotHand.Little2_Rotate(10);
	m_RobotHand.Little3_Rotate(10);
	m_RobotHand.Little4_Rotate(10);

	m_RobotHand.Little1_Rotate_r(10);
	m_RobotHand.Little2_Rotate_r(10);
	m_RobotHand.Little3_Rotate_r(10);
	m_RobotHand.Little4_Rotate_r(10);

	m_RobotHand.drawGL();
	RenderScene();

	return;
}
void CMy3DSLoaderView::OnLittleInverse()
{	int choice[5]={0,0,0,0,1};
		float* res= m_RobotHand.CalculateThetaByCoordinate(tVector(22.68,80.24,34.81),choice);
				CString str;
		float angle0= -(*res);
		float angle1= -*(res+1);
		float angle2= -*(res+2);
		float angle3= -*(res+3);
		str.Format("%f,%f,%f,%f",angle0 , angle1, angle2,angle3);
		PublicFuntoinHelper::ShowMessage(str);
		
		m_RobotHand.Little1_Rotate(angle0);
		m_RobotHand.Little2_Rotate(angle1);
		m_RobotHand.Little3_Rotate(angle1+angle2);
		m_RobotHand.Little4_Rotate(angle1+angle2+angle3);

		m_RobotHand.Little1_Rotate_r(angle0);
		m_RobotHand.Little2_Rotate_r(angle1);
		m_RobotHand.Little3_Rotate_r(angle1 + angle2);
		m_RobotHand.Little4_Rotate_r(angle1 + angle2 + angle3);
		
	return;
	
}