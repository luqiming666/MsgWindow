//
// CMsgFrameWnd.h
//

#ifndef __H_CMsgFrameWnd__
#define __H_CMsgFrameWnd__

class CMsgFrameWnd : public CFrameWnd
{
protected:

public:
	CMsgFrameWnd();           // protected constructor used by dynamic creation
	virtual ~CMsgFrameWnd();

	DECLARE_DYNCREATE(CMsgFrameWnd)
protected:
// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMsgFrameWnd)
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CMsgFrameWnd)
	afx_msg LONG OnUserMsg(UINT wParam, LONG lParam);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // __H_CMsgFrameWnd__
