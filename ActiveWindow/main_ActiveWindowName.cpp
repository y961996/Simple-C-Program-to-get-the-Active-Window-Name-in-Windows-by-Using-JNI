#include "main_ActiveWindowName.h"
#include <iostream>
#include <Strsafe.h>
#include <windows.h>
#include <string.h>

JNIEXPORT jstring JNICALL Java_main_ActiveWindowName_getActiveWindowName(JNIEnv *env, jobject object)
{
	HWND test = GetForegroundWindow();
	HWND window;
	int cTxtLen;
	PSTR pszMem;

	window = GetForegroundWindow();
	cTxtLen = GetWindowTextLength(window);
	pszMem = (PSTR)VirtualAlloc((LPVOID)NULL, (DWORD)(cTxtLen + 1), MEM_COMMIT, PAGE_READWRITE);
	GetWindowText(window, pszMem, cTxtLen + 1);

	jstring windowName = env->NewStringUTF(_strdup(pszMem));
	VirtualFree(pszMem, 0, MEM_RELEASE);

	return windowName;
}

int main() {}
