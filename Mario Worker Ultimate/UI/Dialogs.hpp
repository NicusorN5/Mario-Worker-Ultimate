#pragma once
#include <memory>

struct FileDialogResult
{
	std::unique_ptr<char[]> File;
	int Result;

	FileDialogResult();
};

int ShowMessageBox(void* owner, const char* content, const char* title, unsigned flags);
int ShowMessageBoxError(void* window, const char* content, const char* title);
 
FileDialogResult *ShowOpenFileDialog(const char* title);
FileDialogResult *ShowSaveFileDialog(const char* title);

struct ColorDialogResult
{
	struct
	{
		unsigned char R, G, B;
	} ResultColor;
	int Result;

	ColorDialogResult(ColorDialogResult&) = delete;
	ColorDialogResult(unsigned char defR, unsigned char defG, unsigned char defB);
};