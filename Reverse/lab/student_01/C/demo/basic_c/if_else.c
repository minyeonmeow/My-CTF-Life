#include <stdio.h>

int main(int argc, char** argv, char** evnp){
   if (argc == 0){
       printf("no argc");
   }else{
       printf("there are %d args", argc);
   } 
   return 0;
}
