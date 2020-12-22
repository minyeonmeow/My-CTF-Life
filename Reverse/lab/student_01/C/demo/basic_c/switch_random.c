#include <stdio.h>

int main(){
    unsigned char a;
    scanf("%c", &a);
    switch(a){
        case 1:
            printf("1");
            break;
        case 6:
            printf("6");
            break;
        case 100:
            printf("100");
            break;
        case 120:
            printf("120");
            break;
        case 88:
            printf("88");
            break;
        case 255:
            printf("255");
            break;
        default:
            printf("default");
          
    }
    return 0;
}
