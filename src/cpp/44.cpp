// 상수 : 변하지 않는 수
// 변수 : 변할 수 있는 수
// 상수 만들기 - const, 매크로(#define), enum

#include <stdio.h>

// #define PI 3.141592

// int main(){
//     // const float PI = 3.141592;

//     printf("pi = %.2f\n", PI);
// }


enum EGameState{     
    GAMESTATE_MAINMENU,  // 자료형 안적음, 값 할당 안하면 자동으로 순서매겨줌, 중간에 값을 지정하면 앞뒤에값 순서맞춰줌
    GAMESTATE_PLAYING,
    GAMESTATE_PAUSED,
    GAMESTATE_GAMEOVER 
};

int main(){
    int currState = 0;

    while(true){
        switch (currState)
        {
        case GAMESTATE_MAINMENU:            
            break;
        
        case GAMESTATE_PLAYING:
            break;
        
        case GAMESTATE_PAUSED:
            break;
            
        case GAMESTATE_GAMEOVER:
            break;
            
        default:
            break;
        }
    }
}