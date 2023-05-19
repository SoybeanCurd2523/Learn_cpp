#include <stdio.h>

// recursion
int factorial(int n){
    printf("facotiral(%d)\n", n);
    if(n <= 1) return 1;
    return n*factorial(n-1);
}


// iteration
int factorial_iter(int n){
    printf("factorial_iter(%d)\n", n);
    int i, result = 1;
    for(i=1 ; i<=n ; i++)
        result = result*i;

    return result;
}

int main(){
    // printf("result : %d\n", factorial(4));

    printf("result_iter : %d\n", factorial_iter(3));
}