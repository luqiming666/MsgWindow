// MsgWindowDlg.cpp : implementation file
//

#include "stdafx.h"
#include "MsgWindow.h"
#include "MsgWindowDlg.h"

#include "GlobalDef.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

// Method 2
CWnd        gWindowMethod2;
WNDPROC     gOriginalProc;
void BuildInWindowMethod2(void);
void ReleaseWindowMethod2(void);
LRESULT WINAPI NewWndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

// Method 3
HHOOK       glhHook;
CWnd        gWindowMethod3;
void BuildInWindowMethod3(void);
void ReleaseWindowMethod3(void);
LRESULT CALLBACK CallWndProc(int nCode, WPARAM wParam, LPARAM lParam);

/////////////////////////////////////////////////////////////////////////////
// CMsgWindowDlg dialog

CMsgWindowDlg::CMsgWindowDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CMsgWindowDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CMsgWindowDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	mMsgFrameWnd = NULL;
}

CMsgWindowDlg::~CMsgWindowDlg()
{
	ReleaseWindowMethod2();
	if (mMsgFrameWnd)
	{
		::DestroyWindow(mMsgFrameWnd->GetSafeHwnd());
		mMsgFrameWnd = NULL;
	}
	ReleaseWindowMethod3();
}

void CMsgWindowDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CMsgWindowDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CMsgWindowDlg, CDialog)
	//{{AFX_MSG_MAP(CMsgWindowDlg)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1_SENDMSG, OnButton1Sendmsg)
	ON_BN_CLICKED(IDC_BUTTON2_SENDMSG, OnButton2Sendmsg)
	ON_BN_CLICKED(IDC_BUTTON1_SENDMSG2, OnButton1Sendmsg2)
	ON_BN_CLICKED(IDC_BUTTON3_SENDMSG, OnButton3Sendmsg)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMsgWindowDlg message handlers

BOOL CMsgWindowDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	// TODO: Add extra initialization here
	// Method 1
	//	method 1.1
	mMsgWnd.Create(NULL, "Msg", WS_CHILD, CRect(0,0,1,1), this, 0);
	//	method 1.2
	mMsgFrameWnd = new CMsgFrameWnd(); // creat window in heap
	mMsgFrameWnd->Create(0, "Msg", WS_POPUPWINDOW, CRect(0,0,1,1), 0, 0);

	// Method 2
	BuildInWindowMethod2();

	// Method 3
	BuildInWindowMethod3();

	return TRUE;  // return TRUE  unless you set the focus to a control
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.
void CMsgWindowDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CMsgWindowDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

/////////////////////////////// Method 1 ///////////////////////////////////////////////
void CMsgWindowDlg::OnButton1Sendmsg() 
{
	// TODO: Add your control notification handler code here
	::SendMessage(mMsgWnd.GetSafeHwnd(), WM_USER_MSG, 1, 0);
}

void CMsgWindowDlg::OnButton1Sendmsg2() 
{
	// TODO: Add your control notification handler code here
	::SendMessage(mMsgFrameWnd->GetSafeHwnd(), WM_USER_MSG, 1, 0);
}

/////////////////////////////// Method 2 ///////////////////////////////////////////////
void CMsgWindowDlg::OnButton2Sendmsg() 
{
	// TODO: Add your control notification handler code here
	::SendMessage(gWindowMethod2.GetSafeHwnd(), WM_USER_MSG, 2, 0);
}

void BuildInWindowMethod2(void)
{
	// create an overlapped window with an MFC window class
	LPCTSTR lpszClass = AfxRegisterWndClass(NULL);
	HWND hWnd=::CreateWindow(lpszClass,             // windows class name
						"Msg Hub",                  // window caption
                    WS_OVERLAPPEDWINDOW,            // window style
                    CW_USEDEFAULT, CW_USEDEFAULT,   // position and dimensions
                    CW_USEDEFAULT, CW_USEDEFAULT,
                    NULL,						    // owner window handle--NULL is Desktop
					NULL,					    	// for popup and overlapped windows: window menu handle
					AfxGetInstanceHandle(),	    	// handle to application instance
					NULL				            // pointer to window-creation data
					);
	gWindowMethod2.Attach(hWnd);
	// change the window procdure address
	gOriginalProc = (WNDPROC) SetWindowLong(hWnd, GWL_WNDPROC,	(LONG)NewWndProc);
}

void ReleaseWindowMethod2(void)
{
	if (gWindowMethod2.GetSafeHwnd())
	{
		HWND  hWnd = gWindowMethod2.Detach();
		::DestroyWindow(hWnd);
	}
}

LRESULT WINAPI NewWndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	if (uMsg == WM_USER_MSG)
	{
		CString  strMsg = "Received message using SetWindowLong: ";
		CString  strParam;
		strParam.Format("Method %d!", wParam);
		::AfxMessageBox(strMsg + strParam);
		return 1;
	}
	return CallWindowProc(gOriginalProc,hWnd,uMsg,wParam,lParam);
}
///////////////////////////////////////////////////////////////////////////////////

//////////////////////////// Method 3 //////////////////////////////////////////////
void CMsgWindowDlg::OnButton3Sendmsg() 
{
	// TODO: Add your control notification handler code here
	::SendMessage(gWindowMethod3.GetSafeHwnd(), WM_USER_MSG, 3, 0);
}

void BuildInWindowMethod3(void)
{
	// create an overlapped window with an MFC window class
	LPCTSTR lpszClass = AfxRegisterWndClass(NULL);
	HWND hWnd=::CreateWindow(lpszClass,             // windows class name
						"Msg Hub",                  // window caption
                    WS_OVERLAPPEDWINDOW,            // window style
                    CW_USEDEFAULT, CW_USEDEFAULT,   // position and dimensions
                    CW_USEDEFAULT, CW_USEDEFAULT,
                    NULL,						    // owner window handle--NULL is Desktop
					NULL,					    	// for popup and overlapped windows: window menu handle
					AfxGetInstanceHandle(),	    	// handle to application instance
					NULL				            // pointer to window-creation data
					);
	gWindowMethod3.Attach(hWnd);
	// Install hook for the current thread
	glhHook = SetWindowsHookEx(WH_CALLWNDPROC,CallWndProc,AfxGetInstanceHandle(),GetCurrentThreadId());
}

void ReleaseWindowMethod3(void)
{
	UnhookWindowsHookEx(glhHook);
	if (gWindowMethod3.GetSafeHwnd())
	{
		HWND  hWnd = gWindowMethod3.Detach();
		::DestroyWindow(hWnd);
	}
}

LRESULT CALLBACK CallWndProc(int nCode, WPARAM wParam, LPARAM lParam)
{
	if (nCode == HC_ACTION)
	{
		CWPSTRUCT * pMsg = (CWPSTRUCT*) lParam;
		if (pMsg->hwnd == gWindowMethod3.GetSafeHwnd() &&
			pMsg->message == WM_USER_MSG)
		{
			CString  strMsg = "Received message using Hook: ";
			CString  strParam;
			strParam.Format("Method %d!", pMsg->wParam);
			::AfxMessageBox(strMsg + strParam);
			return TRUE;
		}	
	}
	return CallNextHookEx(glhHook, nCode, wParam, lParam);
}
///////////////////////////////////////////////////////////////////////////////////
