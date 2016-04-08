#pragma once
#define DIAGRAM_CLASSNAME	_T("MFCopenGLCtrl")

#include <gl/glut.h>
// CopenGL

class CopenGL : public CWnd
{
	DECLARE_DYNAMIC(CopenGL)

public:
	CopenGL();
	virtual ~CopenGL();

protected:
	BOOL RegisterWindowClass();
	void InitOpenGL();
	void DrawFunc();

	int time;
	double heightFactor;
	bool flag;

	HDC hDC;
	HGLRC hRC;

public:
	afx_msg void OnPaint();
	virtual void PreSubclassWindow();
	afx_msg void OnClose();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	afx_msg void OnTimer(UINT_PTR nIDEvent);

	int getTime() { return time; };
	void setTime(int newTime);
	void setWaterHeightFactor(double newHeightFactor) { heightFactor = newHeightFactor; };
	void setFlag(bool newFlag) { flag = newFlag; };

	DECLARE_MESSAGE_MAP()
//	afx_msg void OnInitMenu(CMenu* pMenu);
};
