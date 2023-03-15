#include <stdio.h>
#include <stdlib.h>

// // 문제1
// int sumRec(int n){
//     if(n==1)
//         return 1;
//     else{
//         return n + sumRec(n-1);
//     }
// }
// int main(){
//     int n;
//     scanf("%d", &n);

//     printf("%d\n", sumRec(n));
//     return 0;
// }

// // 문제3

// void InverseOrder(int n){ // 내림차순
//     if(n>=10){
//         printf("%d\n", n%10);
//         InverseOrder(n/10);
//     }
//     else{
//         printf("%d\n", n);
//     }
// }
// int main(){
//     int n;
//     scanf("%d", &n); // 3408

//     InverseOrder(n);
//     // printf("%d\n", n%10); // 8
//     // printf("%d\n", n/10);// 340
// }


// // 문제2

// void ForwardOrder(int n){ // 오름차순
//     if(n>=10){
//         ForwardOrder(n/10);
//         printf("%d\n", n%10);
//     }
//     else{
//         printf("%d\n", n);
//     }
// }
// int main(){
//     int n;
//     scanf("%d", &n); // 3408

//     ForwardOrder(n);
//     // printf("%d\n", n%10); // 8
//     // printf("%d\n", n/10);// 340
// }


// 문제3

int N;
void Maxarr(int &arr[]){
    printf("%d", N);
}

int main(){

    scanf("%d", &N);

    int arr[N] = {0};
    for(int i=0 ; i<N; i++){
        scanf("%d", &arr[i]);
    }
    // printf("%d\n", Maxarr(&arr));
    Maxarr(arr);
}