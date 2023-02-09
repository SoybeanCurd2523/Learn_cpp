#include <iostream>
using namespace std;

/*
int *a;
a = &num1;
*/
void swap(int *a, int *b){
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void swap(char *a, char *b){
    char tmp = *a;
    *a = *b;
    *b = tmp;
}

void swap(double *a, double *b){
    double tmp = *a;
    *a = *b;
    *b = tmp;
}


int main(){
    int num1=20, num2=30;
    swap(&num1, &num2);
    cout << num1 << ' ' << num2 << endl;

    char ch1='a', ch2='z';
    swap(&ch1, &ch2);
    cout << ch1 << ' ' << ch2 << endl;

    double dbl1 = 1.111, dbl2 = 5.555;
    swap(&dbl1, &dbl2);
    cout << dbl1 << ' ' << dbl2 << endl;
    return 0;
}



