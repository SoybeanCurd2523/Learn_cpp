#include <stdio.h>

// // 1. 다음 프로그램의 출력 결과는?

// typedef int Point[2];

// typedef Point *PointPtr; 

// int main(){
//     Point p = { 3, 4 }; // int p[2] = { 3, 4 };
//     PointPtr pp = &p; 
//     /* 
//     Point *pp = &p;
//     ----
//     Point *pp;
//     pp = &p;
//     -----
//     (*pp) = p; 
//     (*pp)[0] = p[0] = 3;
//     (*pp)[1] = p[1] = 4;
//     **pp = *(*pp) = *p = *(&p[0]) = p[0] = 3;
//     */

//     printf("%d %d %d\n", **pp, (*pp)[0], (*pp)[1]);
// // 3 3 4
// }


// // 2. 빈칸에 들어갈 코드는?

// struct Point
// {
//     int x, y;
// };

// void pSwap(Point *p){
//     // x좌표와 y좌표를 교환
//     int tmp = p->x; // p->x = (*p).x
//     p->x = p->y;
//     p->y = tmp;
// }

// int main(){
//     Point pos = { 3, 4 };
    
//     pSwap(&pos);

//     printf("(%d, %d)\n", pos.x, pos.y);
// }


// 3. 코드에서 pSwap함수를 Point구조체에 집어넣어 보세요.

struct Point
{
    int x, y;

    void pSwap(){
        int tmp = x;
        x = y;
        y = tmp;
    }
};

int main(){
    Point pos = { 3, 4 };
    
    pos.pSwap();

    printf("(%d, %d)\n", pos.x, pos.y);
}
