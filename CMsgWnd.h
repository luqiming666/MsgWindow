#if !defined(AFX_CMSGWND_H__64E5DE0E_6819_44B2_8289_B40B2D9156EA__INCLUDED_)
#define AFX_CMSGWND_H__64E5DE0E_6819_44B2_8289_B40B2D9156EA__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// CMsgWnd.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CMsgWnd window

class CMsgWnd : public CWnd
{
// Construction
public:
	CMsgWnd();

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMsgWnd)
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CMsgWnd();

	// Generated message map functions
protected:
	//{{AFX_MSG(CMsgWnd)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_MSG
	afx_msg LRESULT OnUserMsg(WPARAM wParam, LPARAM lParam);
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CMSGWND_H__64E5DE0E_6819_44B2_8289_B40B2D9156EA__INCLUDED_)
