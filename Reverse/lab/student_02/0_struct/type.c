#include <stdint.h>

struct ss{
    char aChar; //1 byte
    int aInt;   //4 byte
    int16_t aInt16;//2 byte 4+4+2= 10, true= 12
};

struct ss any;
