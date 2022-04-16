#pragma once

struct FileDialogResult
{
	char* File;
	int Result;

	FileDialogResult();
	~FileDialogResult();
};

void ProperlySetWorkingPath();

int ShowMessageBox(void* owner, const char* content, const char* title, unsigned flags);
int ShowMessageBoxError(void* window, const char* content, const char* title);
void PauseGame(void* window);

FileDialogResult *ShowOpenFileDialog(const char* title);
FileDialogResult *ShowSaveFileDialog(const char* title);

void ExitFileNotFound();
void SetGameIcon(void* window);