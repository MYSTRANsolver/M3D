
// MoMo_Start

// AppSettings.h
#pragma once
#include <Windows.h>
#include <VersionHelpers.h>

class CAppSettings {
	public:
		CAppSettings(const CString& section = _T("Settings"))
		    : m_section(section) {}

		void WriteBool(const CString& key, BOOL value) {
			AfxGetApp()->WriteProfileInt(m_section, key, value ? 1 : 0);
		}

		BOOL ReadBool(const CString& key, BOOL defaultValue = TRUE) {
			int val = AfxGetApp()->GetProfileInt(m_section, key, defaultValue ? 1 : 0);
			return (val != 0);
		}

		void WriteInt(const CString& key, int value) {
			AfxGetApp()->WriteProfileInt(m_section, key, value);
		}

		int ReadInt(const CString& key, int defaultValue = 0) {
			int returnValue = AfxGetApp()->GetProfileInt(m_section, key, defaultValue);
			return returnValue;
		}

		int ToggleDoubleBuffer(int newValue) {
			WriteInt(_T("DoubleBufferModeNew"), newValue);
			int returnValue = ReadInt(_T("DoubleBufferModeCurrent"), 2);
			return returnValue;
		}

		void CurrentBuffer(int& currentValue, int& resultValue) {
			currentValue = ReadInt(_T("DoubleBufferModeCurrent"), 2);
			resultValue = BufferResult(currentValue);
		}

		int ReadDoubleBuffer() {
			int newValue = ReadInt(_T("DoubleBufferModeNew"), 2);
			WriteInt(_T("DoubleBufferModeCurrent"), newValue);
			int returnValue = BufferResult(newValue);
			return returnValue;
		}

		int BufferResult(int newValue) {
			if (newValue == 0 || newValue == 1) {
				return newValue;
			} else {
				if (IsWindows11OrGreater()) {
					return 1;
				} else {
					return 0;
				}
			}
		}

	private:
		CString m_section;

		bool IsWindows11OrGreater() {
			typedef LONG(WINAPI * RtlGetVersionPtr)(PRTL_OSVERSIONINFOW);
			HMODULE hMod = ::GetModuleHandleW(L"ntdll.dll");
			if (hMod) {
				RtlGetVersionPtr fxPtr = (RtlGetVersionPtr)::GetProcAddress(hMod, "RtlGetVersion");
				if (fxPtr != nullptr) {
					RTL_OSVERSIONINFOW rovi = {0};
					rovi.dwOSVersionInfoSize = sizeof(rovi);
					if (fxPtr(&rovi) == 0) // STATUS_SUCCESS == 0
					{
						return (rovi.dwMajorVersion == 10 && rovi.dwBuildNumber >= 22000);
					}
				}
			}
			return false;
		}
};

// MoMo_End