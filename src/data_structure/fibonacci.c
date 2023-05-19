#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//fibonacci  = 0, 1, 1, 2, 3, 5, 8 ...
//recursion
// O(2^n)
int fib(int n)
{
    if(n==0) return 0;
    if(n==1) return 1;
    return ( fib(n-2) + fib(n-1) );
}

// 메모이제이션
// 다이나믹 프로그래밍
// 중간고사?
//iteration
// O(n)
int fib_iter(int n){
    if(n==0) return 0;
    if(n==1) return 1;

    int pp=0;
    int p=1;
    int result=0;

    for(int i=2 ; i <= n ; i++){
        result = p+pp;
        pp = p;
        p = result;
    }
    return result;
}
int main(){
    clock_t start_1, stop_1, start_2, stop_2;
    double duration_1, duration_2;

    int num = 15;

    start_1 = clock();
    printf("fib(%d) = %d\n", num, fib(num));
    stop_1 = clock();

    duration_1 = (double)(stop_1 - start_1)/CLOCKS_PER_SEC;
    printf("duration_1 :%f\n", duration_1);

//////

    start_2 = clock();
    printf("fib_iter(%d) = %d\n", num, fib_iter(num));
    stop_2 = clock();

    duration_2 = (double)(stop_2 - start_2)/CLOCKS_PER_SEC;
    printf("duration_2 :%f\n", duration_2);


}