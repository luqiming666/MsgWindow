// CMsgFrameWnd.cpp : implementation file
//

#include "stdafx.h"
#include "CMsgFrameWnd.h"

#include "GlobalDef.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMsgFrameWnd

IMPLEMENT_DYNCREATE(CMsgFrameWnd, CFrameWnd)

CMsgFrameWnd::CMsgFrameWnd()
{
}

CMsgFrameWnd::~CMsgFrameWnd()
{
}

BEGIN_MESSAGE_MAP(CMsgFrameWnd, CFrameWnd)
	//{{AFX_MSG_MAP(CMsgFrameWnd)
	ON_MESSAGE(WM_USER_MSG, OnUserMsg)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMsgFrameWnd message handlers
LONG CMsgFrameWnd::OnUserMsg(UINT wParam, LONG lParam)
{
	CString  strMsg = "Receive message using message map(FrameWnd): ";
	CString  strParam;
	strParam.Format("Method %d!", wParam);
	::AfxMessageBox(strMsg + strParam);
	return 0;
}