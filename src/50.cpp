#include <iostream>

using namespace std;

// int main(){
//     // int a = 10; //c언어 스타일
//     int a(10); //c++ 스타일

//     int b(a+5);

//     cout << "a = " << a << endl;
//     cout << "b = " << b << endl;
// }


// 범위 기반 for문

// int main(){
//     int arr[10] = { 3, 1, 4, 1, 5, 9, 2, 6, 5, 3 };

//     // for(int i=0 ; i<10 ; i++){
//     //     cout << arr[i] << endl;
//     // }

//     // for(int n : arr ){ // arr의 각 칸을 n으로 놓는다
//     //     cout << n << endl;
//     // }

//     for(int &n : arr){ // reference 변수
//         n++;
//         cout << n << ' ';
//     }
// }




// void swap(int &a, int &b){
//     int tmp = a;
//     a = b;
//     b = tmp;
// }

// int main(){
//     int a(5);
//     int &p = a; // reference 변수
//     p = 10; // p가 가르키고 있는 a의 값이 변한다.

//     cout << p << endl;
//     cout << a << endl;
// }


int main(){

    int a(5);
    int &r1 = a;
    // int &r2 = 3;
    // int &r3 = a*a; // a*a는 메모리에 저장되있지 않다. a는 저장되있긴함

    int &&r4 = 5; // && 하면 된다.
}