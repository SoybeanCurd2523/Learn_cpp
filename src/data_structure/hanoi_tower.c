#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//recursion
static int cnt = 0;
void hanoi_tower(int n, char from, char tmp, char to){
    if(n==1){
        printf("원판 1을  %c 에서 %c 으로 옮긴다. \n", from, to);
        cnt++;
    }
    else{
        hanoi_tower(n-1, from, to, tmp);
        printf("원판 %d를 %c에서 %c으로 옮긴다.\n", n, from, to);
        cnt++;
        hanoi_tower(n-1, tmp, from, to);
    }
}

int main(){
    hanoi_tower(4, 'A', 'B', 'C');
    printf("cnt : %d\n", cnt);
    return 0;
}