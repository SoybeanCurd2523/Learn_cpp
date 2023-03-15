#include <stdio.h>

//call-by-value : 값만 전달
//call-by-reference : 참조

// 밑에 매개변수에서 int arr[4] 는 int *arr와 같다.
void printArr(int *arr){ // call-by-reference. arr포인터가 &arr[0]을 받은 것.
    for(int i=0 ; i<4 ; i++){
        arr[i]*=2; // arr[i] = *(arr+i)
    }
}
int main(){
    int arr[4]={1,2,3,4};

    printArr(arr); // arr = &arr[0]. 실제 값이 아니라 주소값이 넘어감. call-by-reference

    for(int i=0 ; i<4 ; i++){
        printf("%d ", arr[i]);
    }
}

