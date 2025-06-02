// EditBasic.cpp : implementation file
//

#include "stdafx.h"
#include "M3da.h"
#include "EditBasic.h"
// MoMo_Start
#include "GLOBAL_VARS.h"
// MoMo_End

// CEditBasic

IMPLEMENT_DYNAMIC(CEditBasic, CEdit)

CEditBasic::CEditBasic() {
}

CEditBasic::~CEditBasic() {
}

BEGIN_MESSAGE_MAP(CEditBasic, CEdit)
END_MESSAGE_MAP()

// CEditBasic message handlers

BOOL CEditBasic::PreTranslateMessage(MSG* pMsg) {
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
