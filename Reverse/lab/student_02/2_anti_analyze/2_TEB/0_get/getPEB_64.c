#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

int main() {
    puts("this is x86 version");
	printf("PEB is at %p\n", __readgsqword(0x60));
    system("pause");
	return 0;
}

