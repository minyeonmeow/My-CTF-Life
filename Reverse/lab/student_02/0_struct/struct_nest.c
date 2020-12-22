#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef struct {
    char aChar;  //1 byte
    char aCharArray[6]; //6 byte
    int16_t aInt16; //2 byte 8+2 = 10
} ss;

typedef struct{
    ss ass;// 10 byte =  0xa
    long long aLongLong; // 8 byte -> 0x10
} bigss;

int main(){
    bigss* demo = (bigss*)malloc(sizeof(bigss));
    printf("%c",demo->ass.aChar);
    printf("%lld",demo->aLongLong);
    return 0;
}
