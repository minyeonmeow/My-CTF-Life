#include <stdio.h>

void bossB(int time){
    printf("do this in %d hours", time/2);
}
void bossA(int time){
    int bossA_want = time/2;
    printf("do this in %d hours", bossA_want);
    bossB(bossA_want);
}

int main(){
    int a;
    scanf("%d", &a);
    bossA(a);    
    puts("ok");
    return 0;
}
