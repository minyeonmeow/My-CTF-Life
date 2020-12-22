#include <stdio.h>

int main(){
    char a;
    scanf("%c", &a);
    switch(a){
        case 'A':
            printf("A");
            break;
        case 'B':
            printf("B? What the?");
            break;
        case 'C':
            printf("C? you took the wrong way...");
            break;
    }
    return 0;
}
