#include <stdio.h>

// call-by-value : 값만 전달




// call-by-reference : 참조

// void printArr(int *arr){  // int arr[4] 랑 같은 표현임
//     for(int i = 0; i < 4 ; i++){
//         arr[i] *= 2;
//     }
// }

// int main(){
//     int arr[4] = { 1, 2, 3, 4 };
//     printArr(arr);

//     for(int i=0;i<4;i++){
//         printf("%d\n", arr[i]);
//     }
// }

void printArr(int arr[2][3]){ // int arr[2][3](*arr)[3]
    for(int i=0;i<2;i++){
        for(int j=0;j<3;j++){
            printf("%d", arr[i][j]);
        }
        printf("\n");
    }
}

int main(){
    int arr[2][3] = {{1,2,3,}, {4,5,6}};
    printArr(arr); 
}