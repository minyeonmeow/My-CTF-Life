#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "PEB32.h"

int main(){
    PEB* pPeb = __readfsdword(0x30);
    if (pPeb->BeingDebugged || pPeb->NtGlobalFlag & 0x70)
        puts("YOU ARE DEBUGGING!!!");
    else
        puts("curl terrynini.tw | sh");
    system("pause");
}
