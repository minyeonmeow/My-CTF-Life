#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef struct {
    char aChar;  //1 byte
    char aCharArray[6]; //6 byte
    int16_t aInt16; //2 byte
} ss;

int main(){
    ss* demo = (ss*)malloc(sizeof(ss));
    printf("%c",demo->aChar);
    printf("%d",demo->aCharArray[0]);
    printf("%hd",demo->aInt16);
    return 0;
}
