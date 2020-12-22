#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef struct {
    char aChar; //1 byte
    int aInt;   //4 byte
    int16_t aInt16;//2 byte 4+4+2= 10, true= 12
} ss;

int main(){
    ss* demo = (ss*)malloc(sizeof(ss));
    demo->aChar = 'b';
    demo->aInt = 1234;
    demo->aInt16 = 4096;
    printf("%c",demo->aChar);
    printf("%d",demo->aInt);
    printf("%hd",demo->aInt16);
    return 0;
}
