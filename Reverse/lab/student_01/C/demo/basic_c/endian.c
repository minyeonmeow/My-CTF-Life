#include <stdio.h>

int main(){
    int number = 0x12345678;
    printf("%.4s\n", &number);
    return 0;
}
