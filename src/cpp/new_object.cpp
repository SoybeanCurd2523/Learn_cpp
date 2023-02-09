#include <iostream>
using namespace std;

class Car{
public:
    Car(int n){ // 생성자
        cout << "Car is making" << endl;
        cout << "n :" << n << endl;
    }
};

int main(){
    Car *new_car1 = new Car(3);
    // Car new_car1(3);
    delete new_car1;
    return 0;
}