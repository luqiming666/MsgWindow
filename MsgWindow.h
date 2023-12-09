// MsgWindow.h : main header file for the MSGWINDOW application
//

#if !defined(AFX_MSGWINDOW_H__C1E44E6B_2407_4AA6_8A66_C7C43F9961F0__INCLUDED_)
#define AFX_MSGWINDOW_H__C1E44E6B_2407_4AA6_8A66_C7C43F9961F0__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CMsgWindowApp:
// See MsgWindow.cpp for the implementation of this class
//

class CMsgWindowApp : public CWinApp
{
public:
	CMsgWindowApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMsgWindowApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CMsgWindowApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MSGWINDOW_H__C1E44E6B_2407_4AA6_8A66_C7C43F9961F0__INCLUDED_)
