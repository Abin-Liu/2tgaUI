// 2tgaUIDlg.h : header file
//

#if !defined(AFX_2TGAUIDLG_H__6B1373B0_DCAE_424F_B746_26EBE6C6B8D2__INCLUDED_)
#define AFX_2TGAUIDLG_H__6B1373B0_DCAE_424F_B746_26EBE6C6B8D2__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CMy2tgaUIDlg dialog

#include "BrowseCtrl.h"

class CMy2tgaUIDlg : public CDialog
{
// Construction
public:
	CMy2tgaUIDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CMy2tgaUIDlg)
	enum { IDD = IDD_MY2TGAUI_DIALOG };
	CButton	m_wndNoTrans;
	CButton	m_wndTrans;
	CEdit	m_wndTransr;
	CEdit	m_wndTransg;
	CEdit	m_wndTransb;
	CEdit	m_wndW;
	CEdit	m_wndH;
	CEdit	m_wndBcr;
	CEdit	m_wndBcg;
	CEdit	m_wndBcb;
	CBrowseCtrl	m_wndPath;
	BYTE	m_nBcb;
	BYTE	m_nBcg;
	BOOL	m_bG;
	BOOL	m_bH;
	BOOL	m_bBcm;
	BYTE	m_nBcr;
	UINT	m_h;
	BOOL	m_bNotransp;
	BOOL	m_bTotranspm;
	BYTE	m_nTransb;
	BYTE	m_nTransg;
	BYTE	m_nTransr;
	BOOL	m_bW;
	UINT	m_w;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMy2tgaUIDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CMy2tgaUIDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnConvert();
	afx_msg void CheckStatus();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

protected:
	CString m_s2tga;
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_2TGAUIDLG_H__6B1373B0_DCAE_424F_B746_26EBE6C6B8D2__INCLUDED_)
