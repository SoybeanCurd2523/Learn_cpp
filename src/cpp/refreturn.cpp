#include <iostream>
using namespace std;

int& RefReturnFuncOne(int &ref){
    ref++;
    return ref;
}

// int main(){
//     int num1 = 1;
//     int &num2 = RefReturnFuncOne(num1);

//     num1++;
//     num2++;

//     cout << "num1 : " << num1 << endl;
//     cout << "num2 : " << num2 << endl;
    
//     return 0;
// }


int main(){
    int num1 = 1;
    int num2 = RefReturnFuncOne(num1);

    num1+=1;
    num2+=100;

    cout << "num1 : " << num1 << endl;
    cout << "num2 : " << num2 << endl;
    
    return 0;
}


/*
int num1 =1;  
int &ref = num1; // 인자의 전달과정에서 일어난 일
int &num2 = ref; // 함수의 반환과 반환 값의 저장에서 일어난 일
함수의 반환으로 참조자는 소멸된다.
*/