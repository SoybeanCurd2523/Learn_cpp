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


// // 문제4
// // arr+i = &arr[i]

// int Maxarr(int *arr, int n){

//     if(n == 1)
//         return *arr; // *arr = *(&arr[0]) = arr[0]

//     else{

//         if(*(arr+n-1) > Maxarr(arr, n-1)) // *(arr + n - 1) = arr[n-1]
//             return *(arr+n-1);
//         else
//             return Maxarr(arr, n-1);
//     }
// }

// int main(){
//     int n;
//     scanf("%d", &n);

//     int arr[n] = {0};
//     for(int i=0 ; i<n; i++){
//         scanf("%d", &arr[i]);
//     }

//     printf("Max : %d\n", Maxarr(arr, n));
// }


// 문제6
// 재귀 사용하면 a<b인 경우도 재귀 한번 지나면 a와 b가 바뀌게 되므로, tmp를 이용해 a와 b를 바꿀 필요 없다.
int gcd(int a, int b){
    if(b==0)
        return a;
    else
        return gcd(b, a%b);
}

int main(){
    int a, b;
    scanf("%d %d", &a, &b);

    printf("%d\n", gcd(a,b));

    return 0;
}