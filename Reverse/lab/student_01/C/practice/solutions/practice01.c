#include <stdio.h>

int main(int argc, char** argv, char** evnp){
   if( argc <= 0 ){
        if (argc == 0){
            printf("argc is 0 !");
        }else if ( argc < 0 ){
            printf("what ? argc is negative");
        }else{
            printf("no... it's impossible, you should not be here"); 
        }
   }else{
       if ( argc < 6){
           printf("argc is from 1 to 5");
       }else if ( argc >= 6 && argc <  10 ){
           printf("argc is from 6 to 9");
       }else{
           printf("oh! so much argc");
       }
   }
   return 0;
}
