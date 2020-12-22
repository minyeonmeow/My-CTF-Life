#include <stdio.h>
#include <windows.h>

typedef int(__stdcall* msgboxFunc)(HWND, LPCSTR, LPCSTR, UINT);

int main()
{
    msgboxFunc msgbox = NULL;
    HMODULE load32 = LoadLibraryA("user32.dll");
    HMODULE hModule = GetModuleHandleA("user32.dll");
    printf("user32.dll by LoadLibraryA is at %p\n", load32);
    printf("user32.dll by GetModuleHandleA is at %p\n", hModule);
    if (hModule != NULL) {
        msgbox = (msgboxFunc)(GetProcAddress(hModule,"MessageBoxA"));
    }

    if (msgbox != NULL) {
        (*msgbox)(NULL, "nini say hi to you", "Hello", MB_OK);
    }

    if (hModule != NULL) {
        FreeLibrary(hModule);
    }
}
