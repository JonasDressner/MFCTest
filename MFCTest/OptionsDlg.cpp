// OptionsDlg.cpp : implementation file
//

#include "stdafx.h"
#include "MFCTest.h"
#include "OptionsDlg.h"
#include "afxdialogex.h"


// COptionsDlg dialog

IMPLEMENT_DYNAMIC(COptionsDlg, CDialog)

COptionsDlg::COptionsDlg(CWnd* pParent /*=NULL*/)
	: CDialog(IDD_DIALOG_OPTIONS, pParent)
	, m_text(_T("Enter text"))
	, m_bgColor(0)
	, m_x(0)
	, m_y(0)
{

}

COptionsDlg::~COptionsDlg()
{
}

void COptionsDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_TEXT, m_text);
	DDX_Radio(pDX, IDC_RADIO_RED, m_bgColor);
	DDX_Text(pDX, IDC_EDIT_POS_X, m_x);
	DDV_MinMaxInt(pDX, m_x, 0, 9999999);
	DDX_Text(pDX, IDC_EDIT_POS_Y, m_y);
	DDV_MinMaxInt(pDX, m_y, 0, 9999999);
}


BEGIN_MESSAGE_MAP(COptionsDlg, CDialog)
END_MESSAGE_MAP()


// COptionsDlg message handlers
