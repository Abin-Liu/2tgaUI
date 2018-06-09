// 2tgaUIDlg.cpp : implementation file
//

#include "stdafx.h"
#include "2tgaUI.h"
#include "2tgaUIDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
		// No message handlers
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMy2tgaUIDlg dialog

CMy2tgaUIDlg::CMy2tgaUIDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CMy2tgaUIDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CMy2tgaUIDlg)
	m_nBcb = 0;
	m_nBcg = 0;
	m_bG = FALSE;
	m_bH = FALSE;
	m_bBcm = FALSE;
	m_nBcr = 0;
	m_h = 0;
	m_bNotransp = FALSE;
	m_bTotranspm = FALSE;
	m_nTransb = 0;
	m_nTransg = 0;
	m_nTransr = 0;
	m_bW = FALSE;
	m_w = 0;
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	// Copies application directory
	TCHAR sz[MAX_PATH + 1] = _T("");
	::GetModuleFileName(NULL, sz, MAX_PATH);
	LPTSTR p = _tcsrchr(sz, _T('\\'));
	if (p)
		*p = _T('\0');
	m_s2tga = sz;
	m_s2tga += _T("\\2tga.exe");
}

void CMy2tgaUIDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CMy2tgaUIDlg)
	DDX_Control(pDX, IDC_NOTRANSP, m_wndNoTrans);
	DDX_Control(pDX, IDC_TOTRANSPM, m_wndTrans);
	DDX_Control(pDX, IDC_TRANSR, m_wndTransr);
	DDX_Control(pDX, IDC_TRANSG, m_wndTransg);
	DDX_Control(pDX, IDC_TRANSB, m_wndTransb);
	DDX_Control(pDX, IDC_WIDTH, m_wndW);
	DDX_Control(pDX, IDC_HEIGHT, m_wndH);
	DDX_Control(pDX, IDC_BCR, m_wndBcr);
	DDX_Control(pDX, IDC_BCG, m_wndBcg);
	DDX_Control(pDX, IDC_BCB, m_wndBcb);
	DDX_Control(pDX, IDC_SRCPATH, m_wndPath);
	DDX_Text(pDX, IDC_BCB, m_nBcb);
	DDV_MinMaxByte(pDX, m_nBcb, 0, 255);
	DDX_Text(pDX, IDC_BCG, m_nBcg);
	DDV_MinMaxByte(pDX, m_nBcg, 0, 255);
	DDX_Check(pDX, IDC_G, m_bG);
	DDX_Check(pDX, IDC_H, m_bH);
	DDX_Check(pDX, IDC_BCM, m_bBcm);
	DDX_Text(pDX, IDC_BCR, m_nBcr);
	DDV_MinMaxByte(pDX, m_nBcr, 0, 255);
	DDX_Text(pDX, IDC_HEIGHT, m_h);
	DDX_Check(pDX, IDC_NOTRANSP, m_bNotransp);
	DDX_Check(pDX, IDC_TOTRANSPM, m_bTotranspm);
	DDX_Text(pDX, IDC_TRANSB, m_nTransb);
	DDV_MinMaxByte(pDX, m_nTransb, 0, 255);
	DDX_Text(pDX, IDC_TRANSG, m_nTransg);
	DDV_MinMaxByte(pDX, m_nTransg, 0, 255);
	DDX_Text(pDX, IDC_TRANSR, m_nTransr);
	DDV_MinMaxByte(pDX, m_nTransr, 0, 255);
	DDX_Check(pDX, IDC_W, m_bW);
	DDX_Text(pDX, IDC_WIDTH, m_w);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CMy2tgaUIDlg, CDialog)
	//{{AFX_MSG_MAP(CMy2tgaUIDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_CONVERT, OnConvert)
	ON_BN_CLICKED(IDC_W, CheckStatus)
	ON_BN_CLICKED(IDC_H, CheckStatus)
	ON_BN_CLICKED(IDC_BCM, CheckStatus)
	ON_BN_CLICKED(IDC_TOTRANSPM, CheckStatus)
	ON_BN_CLICKED(IDC_NOTRANSP, CheckStatus)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMy2tgaUIDlg message handlers

BOOL CMy2tgaUIDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	// TODO: Add extra initialization here
	m_wndPath.ModifyButtonStyle(0, BC_CTL_ALLOWEDIT);
	CheckStatus();
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CMy2tgaUIDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CMy2tgaUIDlg::OnPaint() 
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
HCURSOR CMy2tgaUIDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CMy2tgaUIDlg::CheckStatus() 
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	m_wndH.EnableWindow(m_bH);
	m_wndW.EnableWindow(m_bW);
	m_wndTransr.EnableWindow(m_bTotranspm);
	m_wndTransg.EnableWindow(m_bTotranspm);
	m_wndTransb.EnableWindow(m_bTotranspm);
	m_wndBcr.EnableWindow(m_bBcm);
	m_wndBcg.EnableWindow(m_bBcm);
	m_wndBcb.EnableWindow(m_bBcm);
}

void CMy2tgaUIDlg::OnConvert() 
{
	// TODO: Add your control notification handler code here
	if (!UpdateData(TRUE))
		return;

	CString sParam, sSeg;
	sParam.Format(_T("s=\"%s\" d=\"%s\" "), (LPCTSTR)m_wndPath.GetPathName(), (LPCTSTR)m_wndPath.GetDirectory());

	if (m_bW)
	{
		sSeg.Format(_T("-w%d "), m_w);
		sParam += sSeg;
	}

	if (m_bH)
	{
		sSeg.Format(_T("-h%d "), m_h);
		sParam += sSeg;
	}

	if (m_bW || m_bH)
		sParam += _T("-sm1 ");

	if (m_bG)
		sParam += _T("-g ");

	if (m_bBcm)
	{
		sSeg.Format(_T("-bcm(%d;%d;%d) "), m_nBcr, m_nBcg, m_nBcb);
		sParam += sSeg;
	}

	if (m_bTotranspm)
	{
		sSeg.Format(_T("-totranspm(%d;%d;%d) -cd32 "), m_nTransr, m_nTransg, m_nTransb);
		sParam += sSeg;
	}
	
	if (m_bNotransp)
		sParam += _T("notransp ");

	sParam += _T("-nodlg ");
	::ShellExecute(NULL, _T("open"), m_s2tga, sParam, NULL, SW_HIDE);
}
