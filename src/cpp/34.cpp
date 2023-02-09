// prototype : 원형, 시제품

#include <stdio.h>
 
void walk(int );
void rotate(int );
void drawSquare();


 int main(){    
    drawSquare();

 }

//걷기 
void walk(int distance){
    printf("%d cm를 걸었습니다.\n", distance);
}

//돌기
void rotate(int angle){
    printf("%d도 회전했습니다.\n", angle);
}

void drawSquare(){
    for(int i=1; i<= 4; i++){
        walk(10);
        rotate(90);
    }
}

