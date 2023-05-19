#include <iostream>
using namespace std;

#define ID_LEN    20 // id의 길이
#define MAX_SPD   200 // 최대 속도
#define FUEL_STEP 2 // 한번 가속시마다 감소하는 연료량
#define ACC_STEP  10 // 가속되는 량
#define BRK_STEP  10 // 멈추는 속도, 감속하는 량

struct Car{
    char gameID[ID_LEN]; // 소유자 ID
    int fuelGauge; // 연료량
    int curSpeed; // 현재 속도
};

void ShowCarState(const Car &car){ // 현재 상태 출력
    cout << "소유자 ID : " << car.gameID << endl;
    cout << "연료량 : " << car.fuelGauge << "%" << endl;
    cout << "현재 속도 : " << car.curSpeed << "km/s" << endl << endl;
}

void Accel(Car &car){ // 가속
    if(car.fuelGauge <= 0) 
        return;
    else    
        car.fuelGauge -= FUEL_STEP;

    if(car.curSpeed + ACC_STEP >= MAX_SPD){
        car.curSpeed = MAX_SPD;
        return;
    }

    car.curSpeed += ACC_STEP;
}

void Break(Car &car){ // 정지
    if(car.curSpeed < BRK_STEP){
        car.curSpeed = 0;
        return;
    }

    car.curSpeed -= BRK_STEP;
}

int main(){
    Car run99 = {"run99", 100, 0};
    Accel(run99);
    Accel(run99);
    ShowCarState(run99);
    Break(run99);
    ShowCarState(run99);

    Car sped77 = {"sped77", 100, 0};
    Accel(sped77);
    Break(sped77);
    ShowCarState(sped77);
    return 0;
}