// APDUExplorer.h : ������� ���� ��������� ��� ���������� PROJECT_NAME
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�������� stdafx.h �� ��������� ����� ����� � PCH"
#endif

#include "resource.h"		// �������� �������


// CAPDUExplorerApp:
// � ���������� ������� ������ ��. APDUExplorer.cpp
//

class CAPDUExplorerApp : public CWinApp
{
public:
	CAPDUExplorerApp();

// ���������������
	public:
	virtual BOOL InitInstance();

// ����������

	DECLARE_MESSAGE_MAP()
};

extern CAPDUExplorerApp theApp;