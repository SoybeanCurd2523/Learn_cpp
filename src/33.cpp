// call-by-value
// call-by-reference

#include <stdio.h>

// void swap(int &x, int &y){
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

void swap(int *x, int *y){
    printf("x : %d\n", x);
    printf("*x : %d\n", *x);

    int tmp = *x;
    *x = *y;
    *y = tmp;
}



int main(){
    int a, b;
    scanf("%d %d", &a, &b);
    
    swap(&a, &b);

    printf("a = %d, b = %d\n", a, b);

}