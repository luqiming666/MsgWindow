// CMsgWnd.cpp : implementation file
//

#include "stdafx.h"
#include "MsgWindow.h"
#include "CMsgWnd.h"

#include "GlobalDef.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMsgWnd

CMsgWnd::CMsgWnd()
{
}

CMsgWnd::~CMsgWnd()
{
}


BEGIN_MESSAGE_MAP(CMsgWnd, CWnd)
	//{{AFX_MSG_MAP(CMsgWnd)
		// NOTE - the ClassWizard will add and remove mapping macros here.
	//}}AFX_MSG_MAP
	ON_MESSAGE(WM_USER_MSG, OnUserMsg)
END_MESSAGE_MAP()


/////////////////////////////////////////////////////////////////////////////
// CMsgWnd message handlers

LRESULT CMsgWnd::OnUserMsg(WPARAM wParam, LPARAM lParam)
{
	CString  strMsg = "Received message using message map (CWnd): ";
	CString  strParam;
	strParam.Format("Method %d!", wParam);
	::AfxMessageBox(strMsg + strParam);
	return 0;
}
