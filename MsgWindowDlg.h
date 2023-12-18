// MsgWindowDlg.h : header file
//

#if !defined(AFX_MSGWINDOWDLG_H__725997D1_44CB_49E0_8079_BE9042F08E7A__INCLUDED_)
#define AFX_MSGWINDOWDLG_H__725997D1_44CB_49E0_8079_BE9042F08E7A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CMsgWindowDlg dialog

#include "CMsgWnd.h"
#include "CMsgFrameWnd.h"

class CMsgWindowDlg : public CDialog
{
// Construction
public:
	CMsgWindowDlg(CWnd* pParent = NULL);	// standard constructor
	~CMsgWindowDlg();

// Dialog Data
	//{{AFX_DATA(CMsgWindowDlg)
	enum { IDD = IDD_MSGWINDOW_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMsgWindowDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

protected:


// Implementation
protected:
	HICON m_hIcon;

	// Method 1
	CMsgWnd         mMsgWnd;
	CMsgFrameWnd *  mMsgFrameWnd;

	// Generated message map functions
	//{{AFX_MSG(CMsgWindowDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnButton1Sendmsg();
	afx_msg void OnButton2Sendmsg();
	afx_msg void OnButton1Sendmsg2();
	afx_msg void OnButton3Sendmsg();
	afx_msg void OnBnClickedButton4Sendmsg();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MSGWINDOWDLG_H__725997D1_44CB_49E0_8079_BE9042F08E7A__INCLUDED_)
