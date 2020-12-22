#include <stdio.h>
#include <windows.h>

typedef int(__stdcall* msgboxFunc)(HWND, LPCSTR, LPCSTR, UINT);
//equivalent to int(WINAPI *msgboxFunc)(HWND, LPCSTR, LPCSTR, UINT);

int main()
{
    msgboxFunc msgbox = NULL;
    HMODULE hModule = LoadLibraryA("user32.dll");

    if (hModule != NULL) {
        msgbox = (msgboxFunc)(GetProcAddress(hModule, (PCSTR)0x863));//"MessageBoxA"));
    }

    if (msgbox != NULL) {
        (*msgbox)(NULL, "nini say hi to you", "Hello", MB_OK);
    }

    if (hModule != NULL) {
        FreeLibrary(hModule);
    }
}
