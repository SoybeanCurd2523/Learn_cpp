// 구조체

#include <stdio.h>

// typedef struct{int x, y;} Point;
struct Point {int x, y;};

int main(){


    Point p;
    p.x = 3;
    p.y = 4;

    printf("(%d, %d)\n", p.x, p.y);
    printf("%d", sizeof(p));
}