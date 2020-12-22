#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

int main()
{
    puts("this is x86 version");
    printf("PEB is at %p\n", __readfsdword(0x30));
    system("pause");
    return 0;
}
