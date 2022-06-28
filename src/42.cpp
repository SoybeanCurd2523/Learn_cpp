#include <stdio.h>

// struct Time{ // 구조체
//     int h, m, s; // 멤버 변수
// };

// int totalSec(Time t){ 
//     return 3600*t.h + 60*t.m + t.s;
// }

// int main(){
//     Time t = { 1, 22, 48 };
//     printf("%d\n", totalSec(t));
// }


// struct Time{ // 구조체
//     int h, m, s; // 멤버 변수

//     int totalSec(){ // 멤버 함수(멤버 메소드)
//         return 3600*h + 60*m + s;    // 그냥 일반 변수를 사용하는 것처럼 구조체의 이름 없이 사용 가능
//     }
// };

// int main(){
//     Time t = { 1, 22, 48 };
//     printf("%d\n", t.totalSec());  
// }


struct Point
{
    int x, y;

    void moveRight() { x++; }
    void moveLeft() { x--; }
    void moveUp() { y++; }
    void moveDown() { y--; }
};

int main(){
    Point p = { 2, 5 };

    p.moveDown();
    p.moveRight();

    printf("(%d, %d)\n", p.x, p.y);
}
