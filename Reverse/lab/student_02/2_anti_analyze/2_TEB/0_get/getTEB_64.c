#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

int main() {
    puts("this is x86_64 version");
	printf("TEB is at %p\n", __readgsqword(0x30));
    system("pause");
	return 0;
}

