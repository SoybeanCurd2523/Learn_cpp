#include <stdio.h>

// #define PI 3.14159
// #define PRINT_HELLO printf("Hello");


// int main(){
//     PRINT_HELLO
// }



// #define SQUARE(X) X*X   // X를 매개변수로 갖는다

// int main(){
//     int a;
//     scanf("%d", &a);

//     printf("%d\n", 100 / SQUARE(a));
//     // SQUARE(a)는 a*a로 대체되므로,
//     // 100/SQUARE(a) = 100 / a * a = 100이다.
//     // 이를 해결하기 위해서는 100 / (SQUARE(a))를 쓰거나,
//     // 매크로를 만들때부터 괄호를 치자    #define SQUARE(X) (X*X)
// }



// #define MAX(A,B) ( ((A)>(B)) ? (A) : (B) )
// // int max(int a, int b){
// //     // if(a>b) return a;
// //     // return b;
    
// //     return (a>b) ? a : b;  // 삼항 연산자  ? :
// // }

// int main(){
//     int a=5, b=10;
//     printf("%d\n", MAX(a,b));
// }



#define FOR(I,S,E) for(int I=S ; I<=E ; I++)
#define LOOP while(true)

int main(){
    FOR(i, 1, 10){
        printf("%d ", i);
    }

    // LOOP{
    //     printf("*");
    // }
}