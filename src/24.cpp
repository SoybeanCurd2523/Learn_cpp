// 포인터 (pointer) : 변수의 주소를 저장하는 변수

#include <stdio.h>

// int main(){
//     int a = 20;

//     int *ptr_a;

//     ptr_a = &a;

//     printf("a의 값 : %d\n", a);
//     printf("a의 주솟값 : %d\n", &a);
//     printf("ptr_a에 저장된 값 : %d\n", ptr_a);
//     printf("ptr_a가 가리키는 변수의 값 : %d\n", *ptr_a);
// // a의 값 : 20
// // a의 주솟값 : -10132
// // ptr_a에 저장된 값 : -10132
// // ptr_a가 가리키는 변수의 값 : 20
// }



// int main(){
//     int a=10;
//     int b=20;

//     int *ptr;
    
//     ptr = &a;
//     printf("ptr이 가리키는 변수에 저장된 값 : %d\n", *ptr);

//     ptr = &b;
//     printf("ptr이 가리키는 변수에 저장된 값 : %d\n", *ptr);
// // ptr이 가리키는 변수에 저장된 값 : 10
// // ptr이 가리키는 변수에 저장된 값 : 20
// }


// int main(){
//     int a=10;
//     int *ptr;
//     ptr = &a;

//     printf("a의 값 : %d\n", a);
//     *ptr = 20;
//     printf("a의 값 : %d\n", a);
// // a의 값 : 10
// // a의 값 : 20
// }


int main(){
    int a = 10;     
    int *ptr;
    ptr = &a;

    int **ptr_ptr;
    ptr_ptr = &ptr;

    printf("a = %d\n", a);
    printf("&a = %d\n", &a);

    printf("ptr = %d\n", ptr);
    printf("*ptr = %d\n", *ptr);
    printf("&ptr = %d\n", &ptr);

    printf("ptr_ptr = %d\n", ptr_ptr);
    printf("*ptr_ptr = %d\n", *ptr_ptr);
    printf("**ptr_ptr = %d\n", **ptr_ptr);
// a = 10
// &a = -10140
// ptr = -10140
// *ptr = 10
// &ptr = -10136
// ptr_ptr = -10136
// *ptr_ptr = -10140
// **ptr_ptr = 10
}