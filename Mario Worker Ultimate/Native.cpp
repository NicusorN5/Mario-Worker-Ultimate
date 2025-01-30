#include "Native.hpp"
//  
// Usage: SetThreadName ((DWORD)-1, "MainThread");  
//  
#ifdef _WIN32

#include <windows.h>  
#include "resource.h"

#include <PathCch.h>
#pragma comment(lib,"Pathcch.lib")

const DWORD MS_VC_EXCEPTION = 0x406D1388;  

#pragma pack(push,8)  
typedef struct tagTHREADNAME_INFO  
{  
    DWORD dwType; // Must be 0x1000.  
    LPCSTR szName; // Pointer to name (in user addr space).  
    DWORD dwThreadID; // Thread ID (-1=caller thread).  
    DWORD dwFlags; // Reserved for future use, must be zero.  
 } THREADNAME_INFO;  
#pragma pack(pop)  

#endif

void ResetWorkingPath()
{
#ifdef _WIN32
	wchar_t path[_MAX_PATH];
	GetModuleFileNameW(nullptr, path, _MAX_PATH);
	PathCchRemoveFileSpec(path, _MAX_PATH);
	SetCurrentDirectoryW(path);
#endif
}

void SetThreadName(DWORD dwThreadID, const char* threadName)
{  
#ifdef _WIN32
    THREADNAME_INFO info;  
    info.dwType = 0x1000;  
    info.szName = threadName;  
    info.dwThreadID = dwThreadID;  
    info.dwFlags = 0;  
#pragma warning(push)  
#pragma warning(disable: 6320 6322)  
    __try{  
        RaiseException(MS_VC_EXCEPTION, 0, sizeof(info) / sizeof(ULONG_PTR), (ULONG_PTR*)&info);  
    }  
    __except (EXCEPTION_EXECUTE_HANDLER){  
    }  
#pragma warning(pop)  
#endif
#ifdef _LINUX
	pthread_setname_np(dwThreadID, threadName);
#endif
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


void PauseGame(void* window)
{
#ifdef _WIN32
	MessageBoxA(static_cast<HWND>(window), "Press \"OK\" to continue.", "Game paused", MB_OK | MB_ICONINFORMATION);
#endif
}