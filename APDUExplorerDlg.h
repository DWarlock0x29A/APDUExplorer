// APDUExplorerDlg.h : ���� ���������
//

#pragma once


// ���������� ���� CAPDUExplorerDlg
class CAPDUExplorerDlg : public CDialog
{
// ��������
public:
	CAPDUExplorerDlg(CWnd* pParent = NULL);	// ����������� �����������

// ������ ����������� ����
	enum { IDD = IDD_APDUEXPLORER_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// ��������� DDX/DDV


// ����������
protected:
	HICON m_hIcon;

	// ��������� ������� ����� ���������
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnTransmit();
	afx_msg void OnATR();
	afx_msg void OnClose();

};
