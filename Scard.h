#include <winscard.h> 
#pragma comment (lib, "winscard.lib")
#pragma once


class CScard 
{
	

public:
	CScard();   // стандартный конструктор
	virtual ~CScard();
SCARDCONTEXT    hSC;
LPTSTR          pmszReaders;
LPTSTR          pReader;
LONG            lReturn2;
DWORD           cch;
SCARDHANDLE     hCardHandle;
DWORD           dwAP;

LPTSTR ListReaders();
long Transmit();
long ATR(CString name);
void OnClose();


protected:
	
};

