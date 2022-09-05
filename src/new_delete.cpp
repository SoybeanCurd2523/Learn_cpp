#include <iostream>
using namespace std;

int main(void){
    // int *p = new int; // int 크기의 공간을 할당하여 그 주소값을 p에 집어 넣었다.
    // *p = 10; // p의 위치에 할당된 공간에 값을 집어넣고 출력하기

    // cout << *p << endl;
    // delete p; // p에 할당된 공간이 해제된다.

    // cout << *p << endl;

/////////////////////////
    int arr_size;
    cout << "array size: ";
    cin >> arr_size;

    // int *list = new int[arr_size];
    // for(int i=0 ; i<arr_size ; i++){
    //     cin >> list[i];
    // }

    // int *list = new int[arr_size] {}; // 동적 할당과 동시에 0으로 초기화하기.

    int *list = new int[arr_size] {10, 20, 30};
    
    for(int i=0 ; i<arr_size ; i++){
        cout << i << "th element of list : " << list[i] << endl;
    }

    delete[] list;

    return 0;
}