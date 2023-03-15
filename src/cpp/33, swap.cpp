// call-by-value 값에 의한 호출
// call-by-reference 참조에 의한 호출

#include <stdio.h>

// void swap(int x, int y){   // call-by-value 값만 넘겨준다. 즉, 값이 바뀌지 않는다.
//     int tmp = x;
//     x = y;
//     y = tmp;
// }

// int main(){
//     int a, b;
//     scanf("%d %d", &a, &b);
    
//     swap(a, b);

//     printf("a = %d, b = %d\n", a, b);

// }




// // int *x;
// // x = &a;
// // a의 주소를 x라는 포인터에 넘겨줌

// void swap(int *x, int *y){   // call-by-reference 주소값을 전달한다
//     printf("x : %d\n", x); // 주소값
//     printf("*x : %d\n", *x); // x가 가르키는 것. 즉, a

//     int tmp = *x;
//     *x = *y;
//     *y = tmp;
// }


// int main(){
//     int a, b;
//     scanf("%d %d", &a, &b);
    
//     swap(&a, &b);

//     printf("a = %d, b = %d\n", a, b);
// }





// void swap(int &x, int &y){   // reference 변수

//     int tmp = x;
//     x = y;
//     y = tmp;
// }


// int main(){
//     int a, b;
//     scanf("%d %d", &a, &b);
    
//     swap(a, b);

//     printf("a = %d, b = %d\n", a, b);

// }


void swap(int *a){   // call-by-reference 주소값을 전달한다
    printf("a : %d\n", *a);
    // printf("*x : %d\n", *x);
}


int main(){
    int a[3] = {1, 2, 3};
    // int a=2;
    
    
    swap(&a);
}