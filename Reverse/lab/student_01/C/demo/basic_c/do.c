#include <stdio.h>

int main(){
   int input;
   scanf("%d",&input);
   do{
       input += 1;
   }while(input > 0);
   printf("%d",input);
   return 0;
}
