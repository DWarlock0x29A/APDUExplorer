// APDUExplorerDlg.cpp : ���� ����������
//

#include "stdafx.h"
#include "APDUExplorer.h"
#include "APDUExplorerDlg.h"
#include <fstream>
#include <sstream> 
#include "Scard.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif




// ���������� ���� CAboutDlg ������������ ��� �������� �������� � ����������

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// ������ ����������� ����
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // ��������� DDX/DDV

// ����������
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
END_MESSAGE_MAP()


// ���������� ���� CAPDUExplorerDlg




CAPDUExplorerDlg::CAPDUExplorerDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CAPDUExplorerDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CAPDUExplorerDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAPDUExplorerDlg, CDialog)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
	ON_BN_CLICKED(IDC_BUTTON1, OnTransmit)
	ON_BN_CLICKED(IDC_BUTTON2, OnATR)
END_MESSAGE_MAP()


// ����������� ��������� CAPDUExplorerDlg

BOOL CAPDUExplorerDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// IDM_ABOUTBOX ������ ���� � �������� ��������� �������.
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

	// ������ ������ ��� ����� ����������� ����. ����� ������ ��� �������������,
	//  ���� ������� ���� ���������� �� �������� ����������
	SetIcon(m_hIcon, TRUE);			// ������� ������
	SetIcon(m_hIcon, FALSE);		// ������ ������

	ShowWindow(SW_SHOWNORMAL);

	//��������� ������ ������� � ComboBox
	CScard scard;
	scard.ListReaders();
	LPTSTR          pReader;
    CComboBox* Cbox=(CComboBox*)GetDlgItem(IDC_COMBO1);
	pReader = scard.pmszReaders;
        while ( '\0' != *pReader )
        {
            // Display the value.
            Cbox->AddString(pReader);
            // Advance to the next value.
            pReader = pReader + wcslen((wchar_t *)pReader) + 1;
        }

    

	return TRUE;  // ������� �������� TRUE, ���� ����� �� ������� �������� ����������
}

void CAPDUExplorerDlg::OnSysCommand(UINT nID, LPARAM lParam)
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



void CAPDUExplorerDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // �������� ���������� ��� ���������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ������������ ������ �� ������ ����������� ��������������
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ��������� ������
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// ������� �������� ��� ������� ��� ��������� ����������� ������� ��� �����������
//  ���������� ����.
HCURSOR CAPDUExplorerDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void CAPDUExplorerDlg::OnTransmit()
{
	CScard scard;
	scard.Transmit();
}

void CAPDUExplorerDlg::OnATR()
{
	CString text;
	GetDlgItemTextW(IDC_COMBO1,text);
	CScard scard;
	scard.ATR(text);
}

void CAPDUExplorerDlg::OnClose() 
{
    CScard scard;
	scard.OnClose();

	CDialog::OnClose();
}
