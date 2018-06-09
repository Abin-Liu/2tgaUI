// 2tgaUI.h : main header file for the 2TGAUI application
//

#if !defined(AFX_2TGAUI_H__84B488D7_1D9F_48C6_8A0F_624622B7DF00__INCLUDED_)
#define AFX_2TGAUI_H__84B488D7_1D9F_48C6_8A0F_624622B7DF00__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CMy2tgaUIApp:
// See 2tgaUI.cpp for the implementation of this class
//

class CMy2tgaUIApp : public CWinApp
{
public:
	CMy2tgaUIApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMy2tgaUIApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CMy2tgaUIApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_2TGAUI_H__84B488D7_1D9F_48C6_8A0F_624622B7DF00__INCLUDED_)
