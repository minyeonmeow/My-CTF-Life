#include <stdio.h>

int main(){
   int input;
   scanf("%d",&input);
   for(int i = 0 ; i < 100 ; i += 1){
       for(int j = 0; j < i ; j += 4);
           printf("%d,%d",i,j);
       while( j > 0){
           printf("%d",j);
           j -= 1;
       }
   }
   return 0;
}
