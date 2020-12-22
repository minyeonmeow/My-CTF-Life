#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

int main() {
    puts("this is x86 version");
	printf("TEB is at %p\n", __readfsdword(0x18));
    system("pause");
	return 0;
}

