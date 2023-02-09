#include <stdio.h>
#include <stdlib.h>
#include <time.h>

clock_t start_1, stop_1, start_2, stop_2;
double duration_1, duration_2;

// iteration
// O(n)
double slow_power(double x, int n){
    int i;
    double result = 1.0;

    for(int i=0 ; i<n ; i++)
        result = result * x;

    return result;
}

// recursion
// O(log2_n)
double power(double x, int n){
    if(n == 0) return 1;
    else if(n%2 == 0) // n이 짝수 
        return power(x*x, n/2);
    else // n이 홀수
        return x*power(x*x, (n-1)/2);
}

int main(){
    start_1 = clock();
    for(int i=0 ; i<1000000 ; i++){
        double result = 0.0;
        result = slow_power(2, 500);
    }
    stop_1 = clock();

    duration_1 = (double)(stop_1 - start_1)/CLOCKS_PER_SEC;
    printf("duration_1 :%f\n", duration_1);


    start_2 = clock();
    for(int i=0 ; i<1000000 ; i++){
        double result = 0.0;
        result = power(2, 500);
    }
    stop_2 = clock();

    duration_2 = (double)(stop_2 - start_2)/CLOCKS_PER_SEC;
    printf("duration_2 :%f\n", duration_2);
    
}