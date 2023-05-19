#include <iostream>
using namespace std;

#define ID_LEN    20 // id의 길이
#define MAX_SPD   200 // 최대 속도
#define FUEL_STEP 2 // 한번 가속시마다 감소하는 연료량
#define ACC_STEP  10 // 가속되는 량
#define BRK_STEP  10 // 멈추는 속도, 감속하는 량


// 구조체 안에 함수를 삽입했다.
// 구조체 내에 선언된 함수에 직접접근이 가능해졌다.

struct Car{
    char gameID[ID_LEN]; // 소유자 ID
    int fuelGauge; // 연료량
    int curSpeed; // 현재 속도

    void ShowCarState(){ // 현재 상태 출력
    cout << "소유자 ID : " << gameID << endl;
    cout << "연료량 : " << fuelGauge << "%" << endl;
    cout << "현재 속도 : " << curSpeed << "km/s" << endl << endl;
    }

    void Accel(){ // 가속
        if(fuelGauge <= 0) 
            return;
        else    
            fuelGauge -= FUEL_STEP;

        if(curSpeed + ACC_STEP >= MAX_SPD){
            curSpeed = MAX_SPD;
            return;
        }

        curSpeed += ACC_STEP;
    }

    void Break(){ // 정지
        if(curSpeed < BRK_STEP){
            curSpeed = 0;
            return;
        }

        curSpeed -= BRK_STEP;
    }

};



int main(){
    Car run99 = {"run99", 100, 0};
    run99.Accel();
    run99.Accel();
    run99.ShowCarState();
    run99.Break();
    run99.ShowCarState();

    Car sped77 = {"sped77", 100, 0};
    sped77.Accel();
    sped77.Break();
    sped77.ShowCarState();
    return 0;
}