#include <iostream>
#include <cstring> // strcpy
using namespace std;

// namespace CAR_CONST에 구조체 Car에서 사용하는 상수들을 모두 모다 놓았다.
namespace CAR_CONST{
    enum{
        ID_LEN    = 20,
        MAX_SPD   = 200,
        FUEL_STEP = 2,
        ACC_STEP  = 10,
        BRK_STEP  = 10
    };
}

class Car{
private:
    char gameID[CAR_CONST::ID_LEN]; // 소유자 ID
    int fuelGauge; // 연료량
    int curSpeed; // 현재 속도

public:
    void InitMembers(char * ID, int fuel);
    void ShowCarState(); // 현재 상태 출력
    void Accel(); // 가속
    void Break(); // 정지
};

void Car::InitMembers(char * ID, int fuel){
    strcpy(gameID, ID);
    fuelGauge = fuel;
    curSpeed = 0;
}

void Car::ShowCarState(){ // 현재 상태 출력
    cout << "소유자 ID : " << gameID << endl;
    cout << "연료량 : " << fuelGauge << "%" << endl;
    cout << "현재 속도 : " << curSpeed << "km/s" << endl << endl;
}


void Car::Accel(){
    if(fuelGauge <= 0) 
        return;
    else    
        fuelGauge -= CAR_CONST::FUEL_STEP;

    if(curSpeed + CAR_CONST::ACC_STEP >= CAR_CONST::MAX_SPD){
        curSpeed = CAR_CONST::MAX_SPD;
        return;
    }

    curSpeed += CAR_CONST::ACC_STEP;
}

void Car::Break(){ // 정지
    if(curSpeed < CAR_CONST::BRK_STEP){
        curSpeed = 0;
        return;
    }

    curSpeed -= CAR_CONST::BRK_STEP;
}

int main(){
    Car run99;
    run99.InitMembers("run99", 100);
    run99.Accel();
    run99.Accel();
    run99.ShowCarState();
    run99.Break();
    run99.ShowCarState();

    return 0;
}