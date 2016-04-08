
// MFCApplication4Dlg.h : ͷ�ļ�
//

#pragma once
#include "CopenGL.h"
#include "afxcmn.h"


// CMFCApplication4Dlg �Ի���
class CMFCApplication4Dlg : public CDialogEx
{
// ����
public:
	CMFCApplication4Dlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_MFCAPPLICATION4_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;
	CopenGL m_openGLctrl;
	CSliderCtrl m_time_slider;
	CSliderCtrl m_height_slider;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()

public:
	afx_msg void OnNMCustomdrawSlider1(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnNMCustomdrawSlider2(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg void OnClose();
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
};
