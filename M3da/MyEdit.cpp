// MyEdit.cpp : implementation file
//

#include "stdafx.h"
#include "M3da.h"
#include "MyEdit.h"
// MoMo_Start
#include "GLOBAL_VARS.h"
// MoMo_End

// CMyEdit

IMPLEMENT_DYNAMIC(CMyEdit, CEdit)

CMyEdit::CMyEdit() {
}

CMyEdit::~CMyEdit() {
}

BEGIN_MESSAGE_MAP(CMyEdit, CEdit)
ON_CONTROL_REFLECT(EN_CHANGE, &CMyEdit::OnEnChange)
ON_WM_SYSCOMMAND()
ON_WM_CLOSE()
END_MESSAGE_MAP()

// CMyEdit message handlers

void CMyEdit::OnEnChange() {
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CEdit::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
	outtextMSG("AA");
}

void CMyEdit::OnSysCommand(UINT nID, LPARAM lParam) {
	// TODO: Add your message handler code here and/or call default

	CEdit::OnSysCommand(nID, lParam);
}

void CMyEdit::OnClose() {
	// TODO: Add your message handler code here and/or call default

	CEdit::OnClose();
}

BOOL CMyEdit::PreTranslateMessage(MSG* pMsg) {
	// TODO: Add your specialized code here and/or call the base class
	// MoMo_Start
	// MoMo// if (pMsg->wParam == VK_ESCAPE) {
	if (pMsg->wParam == VK_ESCAPE && pMsg->message == WM_KEYDOWN) {
		if (!SeedVals.IsSeedMode) {
			outtextMSG2("C");
		} else {
			outtextMSG2("Cancel");
		}
		// MoMo_End
		return TRUE;
		// MoMo_Start
	} else if (pMsg->message == WM_KEYDOWN && (::GetKeyState(VK_CONTROL) & 0x8000)) {
		switch (pMsg->wParam) {
			case 'C': // Ctrl+C
				Copy();
				return TRUE;
			case 'X': // Ctrl+X
				Cut();
				return TRUE;
			case 'V': // Ctrl+V
				Paste();
				return TRUE;
			case 'A': // Ctrl+A
				SetSel(0, -1);
				return TRUE;
		}
		return CEdit::PreTranslateMessage(pMsg);
		// MoMo_End
	} else {
		return CEdit::PreTranslateMessage(pMsg);
	}
}
