// TraceDlg.cpp : implementation file
//

#include "stdafx.h"
#include "MFCTest.h"
#include "TraceDlg.h"
#include "afxdialogex.h"

int currValue;
int maxValue;
BOOL stopNow;

// CTraceDlg dialog

IMPLEMENT_DYNAMIC(CTraceDlg, CDialog)

CTraceDlg::CTraceDlg(CWnd* pParent /*=NULL*/)
	: CDialog(IDD_DIALOG_TRACE, pParent)
{

}

CTraceDlg::~CTraceDlg()
{
}

void CTraceDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_STATIC_TEXT, m_ctrlStatus);
}


BEGIN_MESSAGE_MAP(CTraceDlg, CDialog)
	ON_WM_TIMER()
	ON_BN_CLICKED(IDC_BUTTON_START, &CTraceDlg::OnBnClickedButtonStart)
	ON_BN_CLICKED(IDC_BUTTON_STOP, &CTraceDlg::OnBnClickedButtonStop)
END_MESSAGE_MAP()


void CTraceDlg::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: Add your message handler code here and/or call default
	CString sStatusMsg;
	sStatusMsg.Format(L"Running: %d", currValue);
	m_ctrlStatus.SetWindowText(sStatusMsg);

	CDialog::OnTimer(nIDEvent);
}

UINT MyThreadProc(LPVOID Param)
{
	while (!stopNow && (currValue < maxValue)) {
		currValue++;
		Sleep(50);     // would do some work here
	}

	return TRUE;
}

void CTraceDlg::OnBnClickedButtonStart()
{
	// TODO: Add your control notification handler code here
	currValue = 0;
	maxValue = 5000;
	stopNow = 0;
	m_ctrlStatus.SetWindowText(L"Starting...");
	SetTimer(1234, 333, 0); // 3 times per second

	AfxBeginThread(MyThreadProc, 0); // <<== START THE THREAD
}


void CTraceDlg::OnBnClickedButtonStop()
{
	// TODO: Add your control notification handler code here
	stopNow = TRUE;
	KillTimer(1234);
	m_ctrlStatus.SetWindowText(L"Stopped");
}
