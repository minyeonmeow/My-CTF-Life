#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <stdint.h>

void dead(){
    puts("YOU ARE DEBUGGING!!!!");
    ExitProcess(-1);
}
int main(){
    int8_t flag;
    int8_t temp;
    puts("IsDebuggerPresent");
    if (IsDebuggerPresent())
        dead();
    puts("CheckRemoteDebuggerPresent");
    BOOL bDebuggerPresent;
    if (TRUE == CheckRemoteDebuggerPresent(GetCurrentProcess(), &bDebuggerPresent) &&
    TRUE == bDebuggerPresent)
        dead();

    puts("Oh...You are too poor to afford a CPU which is capable to run a debugger");
    system("pause");
}
