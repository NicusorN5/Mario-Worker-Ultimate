#include "Dialogs.hpp"
#include <Windows.h>
#include <PathCch.h>
#include "../resource.h"
#include <string>
#include <strstream>

#pragma comment(lib,"Pathcch.lib")

void ProperlySetWorkingPath()
{
#ifdef _WIN32
	wchar_t path[_MAX_PATH];
	GetModuleFileNameW(nullptr, path, _MAX_PATH);
	PathCchRemoveFileSpec(path, _MAX_PATH);
	SetCurrentDirectoryW(path);
#endif
}

int ShowMessageBox(void* owner, const char* content, const char* title, unsigned flags)
{
#ifdef _WIN32
	return MessageBoxA(static_cast<HWND>(owner), content, title, flags);
#endif
}

int ShowMessageBoxError(void* window, const char* content, const char* title)
{
#ifdef _WIN32
	return MessageBoxA(static_cast<HWND>(window), content, title, MB_OK | MB_ICONERROR);
#endif
}

void PauseGame(void* window)
{
#ifdef _WIN32
	MessageBoxA(static_cast<HWND>(window), "Press \"OK\" to continue.", "Game paused", MB_OK | MB_ICONINFORMATION);
#endif
}

FileDialogResult* ShowOpenFileDialog(const char* title)
{
#ifdef _WIN32
	FileDialogResult* result = new FileDialogResult();

	OPENFILENAMEA ofn{};
	ofn.lStructSize = sizeof(OPENFILENAMEA);
	ofn.lpstrFile = result->File.get();
	ofn.lpstrTitle = title;
	ofn.nMaxFile = _MAX_PATH;

	if(GetOpenFileNameA(&ofn) == true) result->Result = 0;
	else result->Result = (GetLastError() != 0 ? GetLastError() : -1);
	return result;
#endif
}

FileDialogResult *ShowSaveFileDialog(const char* title)
{
	FileDialogResult* result = new FileDialogResult();
#ifdef _WIN32
	OPENFILENAMEA ofn{};
	ofn.lStructSize = sizeof(OPENFILENAMEA);
	ofn.lpstrFile = result->File.get();
	ofn.lpstrTitle = title;
	ofn.nMaxFile = _MAX_PATH;

	if(GetSaveFileNameA(&ofn)) result->Result = 0;
	else result->Result = (GetLastError() != 0 ? GetLastError() : -1);
#endif
	return result;
}

void ExitFileNotFound()
{
	exit(0x80070002); // 0x80070002 = E_FILE_NOT_FOUND
}

void SetGameIcon(void* window)
{
#ifdef _WIN32
	SendMessageA(static_cast<HWND>(window), WM_SETICON, ICON_SMALL, reinterpret_cast<LPARAM>(LoadIconA(GetModuleHandle(nullptr), MAKEINTRESOURCEA(IDI_ICON1))));
	SendMessageA(static_cast<HWND>(window), WM_SETICON, ICON_BIG, reinterpret_cast<LPARAM>(LoadIconA(GetModuleHandle(nullptr), MAKEINTRESOURCEA(IDI_ICON1))));
#endif
}

FileDialogResult::FileDialogResult():
	Result(-1),
	File(std::make_unique<char[]>(255))	
{

}

COLORREF customColors[16];

ColorDialogResult::ColorDialogResult(unsigned char defR,unsigned char defG,unsigned char defB)
{
#ifdef _WIN32
	CHOOSECOLORA ccd{};
	ccd.lStructSize = sizeof(CHOOSECOLORA);
	ccd.rgbResult = RGB(defR, defG, defB);
	ccd.Flags = CC_RGBINIT | CC_FULLOPEN;
	ccd.lpCustColors = customColors;

	if(ChooseColorA(&ccd) == true)
	{
		this->Result = 0;

		this->ResultColor.R = GetRValue(ccd.rgbResult);
		this->ResultColor.G = GetGValue(ccd.rgbResult);
		this->ResultColor.B = GetBValue(ccd.rgbResult);
	}
	else
	{
		this->Result = (GetLastError() != 0 ? GetLastError() : -1);
		this->ResultColor = { defR, defG, defB };
	}
#endif
}