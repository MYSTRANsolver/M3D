
// M3da.h : main header file for the M3da application
//
#pragma once

#ifndef __AFXWIN_H__
#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h" // main symbols
// Saeed_Material_SaveBugV1_05_20_2025_Start
#include <set>
// Saeed_Material_SaveBugV1_05_20_2025_End

// CM3daApp:
// See M3da.cpp for the implementation of this class
//

class CM3daApp: public CWinAppEx {
	public:
		CM3daApp();
		// Overrides
	public:
		virtual BOOL InitInstance();
		virtual int ExitInstance();
		// Implementation
		COleTemplateServer m_server;
		// Server object for document creation
		BOOL m_bHiColorIcons;

		virtual void PreLoadState();
		virtual void LoadCustomState();
		virtual void SaveCustomState();

		afx_msg void OnAppAbout();
		DECLARE_MESSAGE_MAP()
		afx_msg void OnFileRunscriptfile();

		// Esp_Mod_Config_File_Mod_Start//
	private:
		void LoadConfiguration();
		// Esp_Mod_Config_File_Mod_End//
};
void outtext1(CString AAA);
void outtext2(CString AAA);
// Saeed_Material_SaveBugV1_05_20_2025_Start
void outtextSprintf(CString AAA, int intValue, double floatValue, bool IsInt, int iText);
void outtextMultiLine(CString AAA, int nText);
// Saeed_Material_SaveBugV1_05_20_2025_End
void SendMsg(CString AAA);
void SetFocus();
void outtextMSG(CString AAA);
void outtextMSG2(CString AAA);

extern CM3daApp theApp;
