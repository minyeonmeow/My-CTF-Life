#include <stdio.h>
#include <stdlib.h>
#include <windows.h>


int main()
{
    HMODULE hModule = GetModuleHandleA(0);
    printf("this program is at %p\n", hModule);
    system("pause");
}
