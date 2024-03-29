#include <iostream>
using namespace std;

// 3-1
// void MovePos(int x, int y); // 점의 좌표이동
// void AddPoint(const Point &pos) // 점의 좌표증가. 두 좌표를 더하기
// void ShowPosition(); // 현재 x,y좌표정보 출력

struct Point{
    int xpos;
    int ypos;

    void MovePos(int x, int y){
        xpos += x;
        ypos += y;
    }

    void AddPoint(const Point &pos){
        xpos += pos.xpos;
        ypos += pos.ypos;
    }

    void ShowPosition(){
        printf("[%d, %d]\n", xpos, ypos);
    }
};

int main(void){
    Point pos1 = {12, 4};
    Point pos2 = {20, 30};

    pos1.MovePos(-7, 10);
    pos1.ShowPosition(); // [5, 14] 출력

    pos1.AddPoint(pos2);
    pos1.ShowPosition(); // [25, 44] 출력
    
    return 0;
}