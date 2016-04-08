// CopenGL.cpp : 实现文件
//

#include "stdafx.h"
#include "MFCApplication4.h"
#include "CopenGL.h"


// CopenGL

IMPLEMENT_DYNAMIC(CopenGL, CWnd)

CopenGL::CopenGL()
{
	RegisterWindowClass();
	time = 0;
	heightFactor = 1;
	flag = false;
}

CopenGL::~CopenGL()
{
}

BEGIN_MESSAGE_MAP(CopenGL, CWnd)
	ON_WM_PAINT()
	ON_WM_CLOSE()
	ON_WM_QUERYDRAGICON()
	ON_WM_SIZE()
	ON_WM_ERASEBKGND()
//	ON_WM_INITMENU()
ON_WM_TIMER()
END_MESSAGE_MAP()



BOOL CopenGL::RegisterWindowClass()
{
	WNDCLASS wndcls;
	HINSTANCE hInst = AfxGetInstanceHandle();

	if (!(::GetClassInfo(hInst, DIAGRAM_CLASSNAME, &wndcls)))
	{
		// otherwise we need to register a new class
		wndcls.style = CS_DBLCLKS | CS_HREDRAW | CS_VREDRAW;
		wndcls.lpfnWndProc = ::DefWindowProc;
		wndcls.cbClsExtra = wndcls.cbWndExtra = 0;
		wndcls.hInstance = hInst;
		wndcls.hIcon = NULL;
		wndcls.hCursor = AfxGetApp()->LoadStandardCursor(IDC_ARROW);
		wndcls.hbrBackground = (HBRUSH)(COLOR_3DFACE + 1);
		wndcls.lpszMenuName = NULL;
		wndcls.lpszClassName = DIAGRAM_CLASSNAME;

		if (!AfxRegisterClass(&wndcls))
		{
			AfxThrowResourceException();
			return FALSE;
		}
	}
	return TRUE;
}

// CopenGL 消息处理程序




void CopenGL::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	// TODO:  在此处添加消息处理程序代码
	// 不为绘图消息调用 CWnd::OnPaint()
}


void CopenGL::PreSubclassWindow()
{
	// TODO:  在此添加专用代码和/或调用基类
	InitOpenGL();
	CWnd::PreSubclassWindow();
}


void CopenGL::OnClose()
{
	// TODO:  在此添加消息处理程序代码和/或调用默认值

	CWnd::OnClose();
}


HCURSOR CopenGL::OnQueryDragIcon()
{
	// TODO:  在此添加消息处理程序代码和/或调用默认值

	return CWnd::OnQueryDragIcon();
}


void CopenGL::OnSize(UINT nType, int cx, int cy)
{
	CWnd::OnSize(nType, cx, cy);

	// TODO:  在此处添加消息处理程序代码
}


BOOL CopenGL::OnEraseBkgnd(CDC* pDC)
{
	// TODO:  在此添加消息处理程序代码和/或调用默认值

	return CWnd::OnEraseBkgnd(pDC);
}

void CopenGL::InitOpenGL() {
	/****************************************************************/
	//设置像素格式，并在DC中选择这种格式
	static PIXELFORMATDESCRIPTOR pfd = { sizeof(PIXELFORMATDESCRIPTOR),
		1,
		PFD_DRAW_TO_WINDOW |
		PFD_SUPPORT_OPENGL |
		PFD_DOUBLEBUFFER,
		PFD_TYPE_RGBA,
		24,
		0, 0, 0, 0, 0, 0,
		0,
		0,
		0,
		0, 0, 0, 0,
		32,
		0,
		0,
		PFD_MAIN_PLANE,
		0,
		0, 0, 0
	};
	int pixelformat;
	hDC = ::GetDC(this->GetSafeHwnd());
	if (!(pixelformat = ChoosePixelFormat(hDC, &pfd)))
	{
		MessageBox(_T("ChoosePixelFormat failed!"));
	}
	if (!SetPixelFormat(hDC, pixelformat, &pfd))
	{
		MessageBox(_T("SetPixelFormat failed!"));
	}
	if (!(hRC = wglCreateContext(hDC)))
	{
		MessageBox(_T("CreateContext failed!"));
	}
	if (!wglMakeCurrent(hDC, hRC))
	{
		MessageBox(_T("MakeCurrent failed!"));
	}

	SetTimer(1, 50, NULL);
}

void CopenGL::OnTimer(UINT_PTR nIDEvent)
{
	// TODO:  在此添加消息处理程序代码和/或调用默认值
	if (flag) {
		if (1 - time * 0.01 > 0) {
			++time;
		}
		else {
			time = 0;
		}
	}
	DrawFunc();
	CWnd::OnTimer(nIDEvent);
}


void CopenGL::DrawFunc() //函数具体实现  
{
	glEnable(GL_DEPTH_TEST);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(70, 1, 1, 1000);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(20, 20, 20, 0, 0, 0, 0, 0, 1);

	glClear(GL_COLOR_BUFFER_BIT);

	glBegin(GL_LINES);

	/*
	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex3f(0.0f, 0.0f, 0.0f);
	glVertex3f(100.0f, 0.0f, 0.0f);  // 以上两个点可以画x轴

	glColor3f(0.0f, 1.0f, 1.0f);
	glVertex3f(0.0f, -0.0f, 0.0f);
	glVertex3f(0.0f, 100.0f, 0.0f);  // 以上两个点可以画y轴

	glColor3f(0.0f, 1.0f, 0.0f);
	glVertex3f(0.0f, 0.0f, -0.0f);
	glVertex3f(0.0f, 0.0f, 10.0f);  // 以上两个点可以画z轴
	glEnd();
	*/

	glColor3f(1.0f, 1.0f, 1.0f);

	GLfloat x;
	GLfloat angel;
	for (angel = 0.0f; angel <= 360.0f; angel += 1.0f) {
		GLfloat length = 30 * time * 0.05 <= 30 ? 30 * time * 0.05 : 30;
		glBegin(GL_LINE_STRIP);
		for (x = 0.0f; x < length; x += 0.1f) {
			if (1 - time * 0.01 > 0) {
				glVertex3f(x * cos(angel), x * sin(angel), heightFactor * (1 - time * 0.01) * sin(x - time));
			}
			else {
				glVertex3f(x * cos(angel), x * sin(angel), 0);
			}
		}
		glEnd();

		glBegin(GL_LINES);
		glVertex3f(length * cos(angel), x * sin(angel), 0);
		glVertex3f(30 * cos(angel), 30 * sin(angel), 0);
		glEnd();
	}

	SwapBuffers(hDC); //利用双缓冲  
}

void CopenGL::setTime(int newTime) {
	time = newTime;
}