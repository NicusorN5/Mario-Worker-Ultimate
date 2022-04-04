#include "Dialogs.hpp"
#include <Windows.h>
#include <PathCch.h>
#include "resource.h"

#pragma comment(lib,"Pathcch.lib")

void ProperlySetWorkingPath()
{
	wchar_t path[_MAX_PATH];
	GetModuleFileNameW(nullptr, path, _MAX_PATH);
	PathCchRemoveFileSpec(path, _MAX_PATH);
	SetCurrentDirectoryW(path);
}

int ShowMessageBox(void* owner, const char* content, const char* title, unsigned flags)
{
	return MessageBoxA(static_cast<HWND>(owner), content, title, flags);
}

int ShowMessageBoxError(void* window, const char* content, const char* title)
{
	return MessageBoxA(static_cast<HWND>(window), content, title, MB_OK | MB_ICONERROR);
}

void PauseGame(void* window)
{
	MessageBoxA(static_cast<HWND>(window), "Press \"OK\" to continue.", "Game paused", MB_OK | MB_ICONINFORMATION);
}

FileDialogResult* ShowOpenFileDialog(const char* title)
{
	FileDialogResult *result = new FileDialogResult;
	memset(result->File, 0, _MAX_PATH);

	OPENFILENAMEA ofn{};
	ofn.lStructSize = sizeof(OPENFILENAMEA);
	ofn.lpstrFile = result->File;
	ofn.lpstrTitle = title;
	ofn.nMaxFile = _MAX_PATH;

	if(GetOpenFileNameA(&ofn) == true) result->Result = 0;
	else result->Result = GetLastError();
	return result;
}

FileDialogResult* ShowSaveFileDialog(const char* title)
{
	FileDialogResult* result = new FileDialogResult;

	OPENFILENAMEA ofn{};
	ofn.lStructSize = sizeof(OPENFILENAME);
	ofn.lpstrFile = result->File;
	ofn.lpstrTitle = title;
	ofn.nMaxFile = _MAX_PATH;

	if(GetSaveFileNameA(&ofn)) result->Result = 0;
	else result->Result = GetLastError();
	return result;
}

void ExitFileNotFound()
{
	exit(0x80070002); // 0x80070002 = E_FILE_NOT_FOUND
}

void SetGameIcon(void* window)
{
	SendMessageA(static_cast<HWND>(window), WM_SETICON, ICON_SMALL, reinterpret_cast<LPARAM>(LoadIconA(GetModuleHandle(nullptr), MAKEINTRESOURCEA(IDI_ICON1))));
	SendMessageA(static_cast<HWND>(window), WM_SETICON, ICON_BIG, reinterpret_cast<LPARAM>(LoadIconA(GetModuleHandle(nullptr), MAKEINTRESOURCEA(IDI_ICON1))));
}

FileDialogResult::FileDialogResult()
{
	this->Result = -1;
	this->File = new char[_MAX_PATH];
}

FileDialogResult::~FileDialogResult()
{
	delete[] File;
}
