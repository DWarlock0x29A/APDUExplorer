// APDUExplorer.h : главный файл заголовка для приложения PROJECT_NAME
//

#pragma once

#ifndef __AFXWIN_H__
	#error "включить stdafx.h до включения этого файла в PCH"
#endif

#include "resource.h"		// основные символы


// CAPDUExplorerApp:
// О реализации данного класса см. APDUExplorer.cpp
//

class CAPDUExplorerApp : public CWinApp
{
public:
	CAPDUExplorerApp();

// Переопределение
	public:
	virtual BOOL InitInstance();

// Реализация

	DECLARE_MESSAGE_MAP()
};

extern CAPDUExplorerApp theApp;