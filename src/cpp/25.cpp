#include <stdio.h>

// int main(){
//     int a=10;
//     int *ptr_a = &a; 
//     /*
//     int a=10;
//     int *ptr_a;
//     ptr_a = &a;
//     */

//    printf("ptr_a의 값 : %d\n", ptr_a);
//    printf("ptr_a + 1 의 값 : %d\n", ptr_a+1);
// // ptr_a의 값 : -10132
// // ptr_a + 1 의 값 : -10128
// }


// int main(){
//     int arr[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

//     printf("arr의 값 : %d\n", arr);

//     for(int i=0; i<10;i++){
//         printf("&arr[%d] = %d\n", i, &arr[i]);
//         printf("arr+%d = %d\n", i, arr+i);
//     }
// // arr의 값 : -10160   // arr = &arr[0] 이다.
// // &arr[0] = -10160   // arr+i = &arr[i]  이다.
// // arr+0 = -10160
// // &arr[1] = -10156
// // arr+1 = -10156
// // &arr[2] = -10152
// // arr+2 = -10152
// // &arr[3] = -10148
// // arr+3 = -10148
// // &arr[4] = -10144
// // arr+4 = -10144
// // &arr[5] = -10140
// // arr+5 = -10140
// // &arr[6] = -10136
// // arr+6 = -10136
// // &arr[7] = -10132
// // arr+7 = -10132
// // &arr[8] = -10128
// // arr+8 = -10128
// // &arr[9] = -10124
// // arr+9 = -10124
// }


int main(){
    int arr[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

    for(int i=0; i<10; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");

    for(int i=0; i<10; i++){
        printf("%d ", *(arr+i));  
        // arr+i = &arr[i] 이므로, *(arr+i) = *(&arr[i]) = arr[i] 이다.
    }
    printf("\n");

    for(int *ptr = arr; ptr < arr+10 ; ptr++){
    // for(int *ptr = &arr[0]; ptr< &arr[10] ; ptr++){
        printf("%d ", *ptr);
    }
    printf("\n");
// 1 2 3 4 5 6 7 8 9 10 
// 1 2 3 4 5 6 7 8 9 10 
// 1 2 3 4 5 6 7 8 9 10 
}