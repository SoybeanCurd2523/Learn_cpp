#include <iostream>
using namespace std;

int main(){
    int num = 12;
    int *ptr= &num;
    cout << "*ptr : " << *ptr << endl;
    int **dptr = &ptr;
    cout << "**dptr : " << **dptr << endl;

    int &ref = num; // 참조자(reference)
    int *(&pref) = ptr; // 포인터 변수도 변수이기 때문에 참조자의 선언이 가능하다.
    int **(&dpref) = dptr;

    cout << "ref : " << ref << endl; 
    cout << "*pref : " << *pref << endl;
    cout << "**dpref : " << **dpref << endl;
}