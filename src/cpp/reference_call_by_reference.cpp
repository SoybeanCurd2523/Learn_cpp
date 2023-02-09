#include <iostream>

using namespace std;

// 참조자를 이용한 call_by_reference     <->  주소값을 이용한 call_by_reference
// 참조자는 선언과 동시에 변수로 초기화되어야 한다.
// void SwapByRef2(int &ref1, int &ref2){ // int &ref1 = val1, int &ref2 = val2;
//     int tmp = ref1;
//     ref1 = ref2;
//     ref2 = tmp;
// } // call-by-reference

// void AddOne(int &ref){
//     ref += 1;
// }

// void ChangeSign(int &ref){
//     ref *= -1;
// }

// int main(){
//     int val1 = 10;
//     int val2 = 20;

//     ChangeSign(val1);
//     // AddOne(val1);
//     // SwapByRef2(val1, val2);
//     cout << "val1 : " << val1 << endl;
//     cout << "val2 : " << val2 << endl;

//     return 0;
// }


void SwapPointer(int *(&pref1), int *(&pref2)){ // ptr1과 ptr2가 가르키는 대상이 바뀌는 함수  - num1과 num2의 값은 바뀌지 않는다.
    int *ptr = pref1;
    /*
    int *ptr;
    ptr = pref1;
    */
    pref1 = pref2;
    pref2 = ptr;
}


int main(){
    int num1 = 5;
    int *ptr1 = &num1;
    /*
    int *ptr1;
    ptr1 = &num1;
    */
    int num2 = 10;
    int *ptr2 = &num2;

    SwapPointer(ptr1, ptr2);

    cout << "num1 : " << num1 << endl;
    cout << "num2 : " << num2 << endl;
    cout << "*ptr1 : " << *ptr1 << endl;
    cout << "*ptr2 : " << *ptr2 << endl;
    return 0;
}