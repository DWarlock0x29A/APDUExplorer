// APDUExplorerDlg.h : файл заголовка
//

#pragma once


// диалоговое окно CAPDUExplorerDlg
class CAPDUExplorerDlg : public CDialog
{
// Создание
public:
	CAPDUExplorerDlg(CWnd* pParent = NULL);	// стандартный конструктор

// Данные диалогового окна
	enum { IDD = IDD_APDUEXPLORER_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// поддержка DDX/DDV


// Реализация
protected:
	HICON m_hIcon;

	// Созданные функции схемы сообщений
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
