// Scard.cpp: файл реализации
//

#include "stdafx.h"
#include <stdio.h>
#include <string>
#include "APDUExplorer.h"
#include "APDUExplorerDlg.h"
#include "Scard.h"


CString str_hextable=_T("00,01,02,03,04,05,06,07,08,09,0a,0b,0c,0d,0e,0f,10,11,12,13,14,15,16,17,18,19,1a,1b,1c,1d,1e,1f,20,21,22,23,24,25,26,27,28,29,2a,2b,2c,2d,2e,2f,30,31,32,33,34,35,36,37,38,39,3a,3b,3c,3d,3e,3f,40,41,42,43,44,45,46,47,48,49,4a,4b,4c,4d,4e,4f,50,51,52,53,54,55,56,57,58,59,5a,5b,5c,5d,5e,5f,60,61,62,63,64,65,66,67,68,69,6a,6b,6c,6d,6e,6f,70,71,72,73,74,75,76,77,78,79,7a,7b,7c,7d,7e,7f,80,81,82,83,84,85,86,87,88,89,8a,8b,8c,8d,8e,8f,90,91,92,93,94,95,96,97,98,99,9a,9b,9c,9d,9e,9f,a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,aa,ab,ac,ad,ae,af,b0,b1,b2,b3,b4,b5,b6,b7,b8,b9,ba,bb,bc,bd,be,bf,c0,c1,c2,c3,c4,c5,c6,c7,c8,c9,ca,cb,cc,cd,ce,cf,d0,d1,d2,d3,d4,d5,d6,d7,d8,d9,da,db,dc,dd,de,df,e0,e1,e2,e3,e4,e5,e6,e7,e8,e9,ea,eb,ec,ed,ee,ef,f0,f1,f2,f3,f4,f5,f6,f7,f8,f9,fa,fb,fc,fd,fe,ff");

 
BYTE hexTable[256] = 
{
    0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09, 0x0a, 0x0b, 0x0c, 0x0d, 0x0e, 0x0f, 0x10, 0x11,
    0x12, 0x13, 0x14, 0x15, 0x16, 0x17, 0x18, 0x19, 0x1a, 0x1b, 0x1c, 0x1d, 0x1e, 0x1f, 0x20, 0x21, 0x22, 0x23,
    0x24, 0x25, 0x26, 0x27, 0x28, 0x29, 0x2a, 0x2b, 0x2c, 0x2d, 0x2e, 0x2f, 0x30, 0x31, 0x32, 0x33, 0x34, 0x35,
    0x36, 0x37, 0x38, 0x39, 0x3a, 0x3b, 0x3c, 0x3d, 0x3e, 0x3f, 0x40, 0x41, 0x42, 0x43, 0x44, 0x45, 0x46, 0x47,
    0x48, 0x49, 0x4a, 0x4b, 0x4c, 0x4d, 0x4e, 0x4f, 0x50, 0x51, 0x52, 0x53, 0x54, 0x55, 0x56, 0x57, 0x58, 0x59,
    0x5a, 0x5b, 0x5c, 0x5d, 0x5e, 0x5f, 0x60, 0x61, 0x62, 0x63, 0x64, 0x65, 0x66, 0x67, 0x68, 0x69, 0x6a, 0x6b,
    0x6c, 0x6d, 0x6e, 0x6f, 0x70, 0x71, 0x72, 0x73, 0x74, 0x75, 0x76, 0x77, 0x78, 0x79, 0x7a, 0x7b, 0x7c, 0x7d,
    0x7e, 0x7f, 0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8a, 0x8b, 0x8c, 0x8d, 0x8e, 0x8f,
    0x90, 0x91, 0x92, 0x93, 0x94, 0x95, 0x96, 0x97, 0x98, 0x99, 0x9a, 0x9b, 0x9c, 0x9d, 0x9e, 0x9f, 0xa0, 0xa1,
    0xa2, 0xa3, 0xa4, 0xa5, 0xa6, 0xa7, 0xa8, 0xa9, 0xaa, 0xab, 0xac, 0xad, 0xae, 0xaf, 0xb0, 0xb1, 0xb2, 0xb3,
    0xb4, 0xb5, 0xb6, 0xb7, 0xb8, 0xb9, 0xba, 0xbb, 0xbc, 0xbd, 0xbe, 0xbf, 0xc0, 0xc1, 0xc2, 0xc3, 0xc4, 0xc5,
    0xc6, 0xc7, 0xc8, 0xc9, 0xca, 0xcb, 0xcc, 0xcd, 0xce, 0xcf, 0xd0, 0xd1, 0xd2, 0xd3, 0xd4, 0xd5, 0xd6, 0xd7,
    0xd8, 0xd9, 0xda, 0xdb, 0xdc, 0xdd, 0xde, 0xdf, 0xe0, 0xe1, 0xe2, 0xe3, 0xe4, 0xe5, 0xe6, 0xe7, 0xe8, 0xe9,
    0xea, 0xeb, 0xec, 0xed, 0xee, 0xef, 0xf0, 0xf1, 0xf2, 0xf3, 0xf4, 0xf5, 0xf6, 0xf7, 0xf8, 0xf9, 0xfa, 0xfb,
    0xfc, 0xfd, 0xfe, 0xff
};


//Функция вывода байт
void showarr(LPCBYTE b, DWORD n){
CString	str;

	for (int i = 0; i < n; i++)
	{
		
		AfxGetApp()->m_pMainWnd->GetDlgItemTextW(IDC_EDIT2,str);
		CString data;
        data.AppendFormat(_T("%02x "), (UINT)b[i]);
        str=str+data;
		AfxGetApp()->m_pMainWnd->SetDlgItemTextW(IDC_EDIT2,str);
	}
str=str+_T("\r\n");
AfxGetApp()->m_pMainWnd->SetDlgItemTextW(IDC_EDIT2,str);	
}

CScard::CScard()
{
LONG            lReturn;
// Establish the context.
lReturn = SCardEstablishContext(SCARD_SCOPE_USER,
                                NULL,
                                NULL,
                                &(this->hSC));
if ( SCARD_S_SUCCESS != lReturn )
	AfxMessageBox(_T("Failed SCardEstablishContext"));


}





CScard::~CScard()
{
//Free context
SCardReleaseContext(
  hSC
);
}

//Получение списка ридеров
LPTSTR CScard::ListReaders()
{
	cch = SCARD_AUTOALLOCATE;
	LONG            lReturn;
// Retrieve the list the readers.
// hSC was set by a previous call to SCardEstablishContext.
lReturn = SCardListReaders(hSC,
                           NULL,
                           (LPTSTR)&pmszReaders,
                           &cch );
switch( lReturn )
{
    case SCARD_E_NO_READERS_AVAILABLE:
        AfxMessageBox(_T("Reader is not in groups."));
        // Take appropriate action.
        // ...
        break;

    case SCARD_S_SUCCESS:
        
        pReader = pmszReaders;
        return pReader;
        break;

default:
        AfxMessageBox(_T("Failed SCardListReaders"));
        exit(1);
        break;
}




}

//Основная функция работы с ридером
long CScard::Transmit()
{
	CString temp;
	CString readerName;
	CString apduCommand;
	AfxGetApp()->m_pMainWnd->GetDlgItemTextW(IDC_EDIT1,apduCommand);
	AfxGetApp()->m_pMainWnd->GetDlgItemTextW(IDC_COMBO1,readerName);

	LONG            lReturn;
	//Подключение к ридеру
lReturn = SCardConnect( hSC, 
                        readerName, //Name of reader "ARDS JaCarta 0" "SafeNet Token JC 0" "Aladdin Token JC 0"
                        SCARD_SHARE_SHARED,
                        SCARD_PROTOCOL_T0 | SCARD_PROTOCOL_T1,
                        &(this)->hCardHandle,
                        &dwAP );
if ( SCARD_S_SUCCESS != lReturn )
{
    AfxMessageBox(_T("Failed SCardConnect"));
    exit(1);  
}
switch ( dwAP )
{
    case SCARD_PROTOCOL_T0:
		AfxGetApp()->m_pMainWnd->GetDlgItemTextW(IDC_EDIT2,temp);
        temp=temp+_T("Active protocol T0\r\n");
        AfxGetApp()->m_pMainWnd->SetDlgItemTextW(IDC_EDIT2,temp);
		break;

    case SCARD_PROTOCOL_T1:
		AfxGetApp()->m_pMainWnd->GetDlgItemTextW(IDC_EDIT2,temp);
        temp=temp+_T("Active protocol T1\r\n");
        AfxGetApp()->m_pMainWnd->SetDlgItemTextW(IDC_EDIT2,temp);
		break;

    case SCARD_PROTOCOL_UNDEFINED:
    default:
		AfxGetApp()->m_pMainWnd->GetDlgItemTextW(IDC_EDIT2,temp);
        temp=temp+_T("Active protocol unnegotiated or unknown\r\n");
        AfxGetApp()->m_pMainWnd->SetDlgItemTextW(IDC_EDIT2,temp);
        break;
}


lReturn = SCardBeginTransaction( hCardHandle );
if ( SCARD_S_SUCCESS != lReturn )
 AfxMessageBox(_T("Failed SCardBeginTransaction"));

    BYTE *pbSend, *pbRecv;
    DWORD  dwRecv = 1024;
	DWORD dwSend = 128;
	pbSend = new BYTE[dwSend];
	pbRecv = new BYTE[dwRecv];

//Получение команды из строки
	apduCommand.MakeLower();
	AfxGetApp()->m_pMainWnd->GetDlgItemTextW(IDC_EDIT2,temp);
    temp=temp+_T("Выполняется команда APDU\r\n");
    AfxGetApp()->m_pMainWnd->SetDlgItemTextW(IDC_EDIT2,temp);
apduCommand.Remove(_T(' '));
apduCommand.Remove(_T(':'));
BYTE* APDU;
APDU = new BYTE[apduCommand.GetLength()/2];
CString tmp;

int f=0;
for (int i = 0; i < apduCommand.GetLength(); i=i+2)
			{
				tmp=apduCommand.Mid(i, 2);
				int count=str_hextable.Find(tmp);
				CString tmpstr;
				tmpstr=str_hextable.Mid(count,2);
				AfxGetApp()->m_pMainWnd->GetDlgItemTextW(IDC_EDIT2,temp);
				temp=temp+tmpstr+_T(" ");
				AfxGetApp()->m_pMainWnd->SetDlgItemTextW(IDC_EDIT2,temp);
				APDU[f]	= hexTable[count/3];
				f++;
			}

	dwSend=apduCommand.GetLength()/2;//sizeof(APDU);
	memset(pbSend, 0, dwSend);
	memcpy(pbSend, APDU, dwSend); 
  
lReturn = SCardTransmit(this->hCardHandle,
                        SCARD_PCI_T1,
                        pbSend,
                        dwSend,  //size of pbSend
                        NULL,
                        pbRecv,
                        &dwRecv );
if ( SCARD_S_SUCCESS != lReturn )
{
     AfxMessageBox(_T("Failed SCardTransmit"));
	// Disconnect
    lReturn = SCardDisconnect(this->hCardHandle, 
                          SCARD_LEAVE_CARD);
	//Free context
    SCardReleaseContext(
    hSC
    );
    
}


	AfxGetApp()->m_pMainWnd->GetDlgItemTextW(IDC_EDIT2,temp);
    temp=temp+_T("\r\nSend bytes: \r\n");
    AfxGetApp()->m_pMainWnd->SetDlgItemTextW(IDC_EDIT2,temp);
	showarr(pbSend, dwSend);
	AfxGetApp()->m_pMainWnd->GetDlgItemTextW(IDC_EDIT2,temp);
    temp=temp+_T("Resv bytes: \r\n");
    AfxGetApp()->m_pMainWnd->SetDlgItemTextW(IDC_EDIT2,temp);
	showarr(pbRecv, dwRecv); 

///////////////////////

SCardEndTransaction(this->hCardHandle, SCARD_LEAVE_CARD);
 // Disconnect
lReturn = SCardDisconnect(hCardHandle, 
                          SCARD_LEAVE_CARD);
if ( SCARD_S_SUCCESS != lReturn )
{
    AfxMessageBox(_T("Failed SCardDisconnect"));
    exit(1);  
}
return 0;
}

//Получение ATR
long CScard::ATR(CString name)
{

CString temp;
AfxGetApp()->m_pMainWnd->GetDlgItemTextW(IDC_EDIT2,temp);
temp=temp+name+_T("\r\n")+_T("Check ATR\r\n");
AfxGetApp()->m_pMainWnd->SetDlgItemTextW(IDC_EDIT2,temp);


LONG            lReturn;
lReturn = SCardConnect( hSC, 
                        name, //Name of reader "ARDS JaCarta 0" "SafeNet Token JC 0" "Aladdin Token JC 0"
                        SCARD_SHARE_SHARED,
                        SCARD_PROTOCOL_T0 | SCARD_PROTOCOL_T1,
                        &(this)->hCardHandle,
                        &dwAP );
if ( SCARD_S_SUCCESS != lReturn )
{
    AfxMessageBox(_T("Failed SCardConnect"));
    exit(1);  
}

WCHAR           szReader[200];
cch = 200;
BYTE            bAttr[32];
DWORD           cByte = 32;
DWORD           dwState, dwProtocol;


// Determine the status.
// hCardHandle was set by an earlier call to SCardConnect.
lReturn = SCardStatus(hCardHandle,
                      szReader,
                      &cch,
                      &dwState,
                      &dwProtocol,
                      (LPBYTE)&bAttr,
                      &cByte); 

if ( SCARD_S_SUCCESS != lReturn )
{
    AfxMessageBox(_T("Failed SCardStatus\n"));
    
}

// Examine retrieved status elements.
// Look at the reader name and card state.

switch ( dwState )
{
    case SCARD_ABSENT:
        AfxGetApp()->m_pMainWnd->GetDlgItemTextW(IDC_EDIT2,temp);
        temp=temp+_T("Card absent.\r\n");
        AfxGetApp()->m_pMainWnd->SetDlgItemTextW(IDC_EDIT2,temp);
        break;
    case SCARD_PRESENT:
		AfxGetApp()->m_pMainWnd->GetDlgItemTextW(IDC_EDIT2,temp);
        temp=temp+_T("Card present.\r\n");
        AfxGetApp()->m_pMainWnd->SetDlgItemTextW(IDC_EDIT2,temp);
        break;
    case SCARD_SWALLOWED:
		AfxGetApp()->m_pMainWnd->GetDlgItemTextW(IDC_EDIT2,temp);
        temp=temp+_T("Card swallowed.\r\n");
        AfxGetApp()->m_pMainWnd->SetDlgItemTextW(IDC_EDIT2,temp);
        break;
    case SCARD_POWERED:
		AfxGetApp()->m_pMainWnd->GetDlgItemTextW(IDC_EDIT2,temp);
        temp=temp+_T("Card has power.\r\n");
        AfxGetApp()->m_pMainWnd->SetDlgItemTextW(IDC_EDIT2,temp);
        break;
    case SCARD_NEGOTIABLE:
		AfxGetApp()->m_pMainWnd->GetDlgItemTextW(IDC_EDIT2,temp);
        temp=temp+_T("Card reset and waiting PTS negotiation.\r\n");
		AfxGetApp()->m_pMainWnd->SetDlgItemTextW(IDC_EDIT2,temp);
        break;
    case SCARD_SPECIFIC:
		AfxGetApp()->m_pMainWnd->GetDlgItemTextW(IDC_EDIT2,temp);
        temp=temp+_T("Card has specific communication protocols set.\r\n");
		AfxGetApp()->m_pMainWnd->SetDlgItemTextW(IDC_EDIT2,temp);
        break;
    default:
		AfxGetApp()->m_pMainWnd->GetDlgItemTextW(IDC_EDIT2,temp);
        temp=temp+_T("Unknown or unexpected card state.\r\n");
		AfxGetApp()->m_pMainWnd->SetDlgItemTextW(IDC_EDIT2,temp);
        break;
}
       

	BYTE *pbSend, *pbRecv;
    DWORD  dwRecv = 1024;
	DWORD dwSend = 128;
	pbSend = new BYTE[dwSend];
	pbRecv = new BYTE[dwRecv]; 
    dwSend=sizeof(bAttr);
	memset(pbSend, 0, dwSend);
	memcpy(pbSend, bAttr, dwSend);

	AfxGetApp()->m_pMainWnd->GetDlgItemTextW(IDC_EDIT2,temp);
    temp=temp+_T("ATR \r\n");
	AfxGetApp()->m_pMainWnd->SetDlgItemTextW(IDC_EDIT2,temp);
	showarr(pbSend, dwSend);

// Disconnect
lReturn = SCardDisconnect(hCardHandle, 
                          SCARD_LEAVE_CARD);
if ( SCARD_S_SUCCESS != lReturn )
{
    AfxMessageBox(_T("Failed SCardDisconnect"));
    exit(1);  
}

return 0;
}

void CScard::OnClose()
{
//Free the memory.
 long lReturn2 = SCardFreeMemory( hSC, pmszReaders );
         if( SCARD_S_SUCCESS != lReturn2 )
         AfxMessageBox(_T("Failed SCardFreeMemory"));
}