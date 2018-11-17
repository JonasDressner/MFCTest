#pragma once
#include "afxwin.h"


// CTraceDlg dialog

class CTraceDlg : public CDialog
{
	DECLARE_DYNAMIC(CTraceDlg)

public:
	CTraceDlg(CWnd* pParent = NULL);   // standard constructor
	virtual ~CTraceDlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_TRACE };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 
	
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	CStatic m_ctrlStatus;
	afx_msg void OnBnClickedButtonStart();
	afx_msg void OnBnClickedButtonStop();
	//UINT MyThreadProc(LPVOID Param);
};
