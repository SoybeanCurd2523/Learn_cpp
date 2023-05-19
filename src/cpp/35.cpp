// 재귀함수
// recursion

#include <stdio.h>

// void rec(int n){
//     if(n>5) return;
//     printf("n=%d\n", n);
//     rec(n+1);
// }

// int main(){
//     rec(1);
// }





// 팩토리얼
// 5! = 5*4*3*2*1 = 120
// n! = n * (n-1)!

// n을 매개변수 -> n!을 return
int factorial(int n){
    if(n == 0) return 1;
    return n * factorial(n-1);
}


int main(){
    printf("%d\n", factorial(3));
}