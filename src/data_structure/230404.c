// #include <stdio.h>
// #include <stdlib.h>
// #include <time.h>

// #define N 100

// typedef char element; // 애만 바꿔주면 int형 배열, float형 배열 등 으로 한번에 바꿀 수 있다.

// typedef struct
// {
//     element data[];
//     int front;
//     int rear;
// }QueueType;

// void init(QueueType *Q){
//     Q->front = Q->rear = -1;
// }

// int isFull(QueueType *Q){
//     return Q->rear = N-1;
// }

// int isEmpty(QueueType *Q){
//     return Q->front == Q->rear;
// }

// void enqueue(QueueType *Q, element e){
//     if(isFull(Q))
//         printf("Full\n");
//     else{
//         Q->rear++;
//         Q->data[Q->rear] = e;
//     }
// }

// void print(QueueType *Q){
//     printf("Front : %d - Rear : %d\n", Q->front, Q->rear);
//     for(int i=Q->front+1 ; i<= Q->rear ; i++){
//         printf("[%c] ", Q->data[i]);
//     }
//     printf("\n");
// }

// element dequeue(QueueType *Q){
//     if(isEmpty(Q)){
//         printf("Empty");
//         return 0;
//     }
//     Q->front++;
//     return Q->data[Q->front];
// }

// int main(){
//     QueueType Q;
//     init(&Q);
//     srand(time(NULL));

//     for(int i=0 ; i<7 ; i++){
//         enqueue(&Q, rand() % 26 + 65); // 알파벳 대문자 A~Z의 아스키코드
//     }
    
//     print(&Q); getchar();

//     for(int i=0 ; i<4 ; i++){
//         printf("[%c]", dequeue(&Q)); // 알파벳 대문자 A~Z의 아스키코드
//     }
//     printf("\n");

//     return 0;
// }





#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 10

typedef char element; // 애만 바꿔주면 int형 배열, float형 배열 등 으로 한번에 바꿀 수 있다.

typedef struct
{
    element data[];
    int front;
    int rear;
}QueueType;

void init(QueueType *Q){
    Q->front = Q->rear = 0;
}

int isFull(QueueType *Q){
    return Q->front == (Q->rear+1)%N;
}

int isEmpty(QueueType *Q){
    return Q->front == Q->rear;
}

void enqueue(QueueType *Q, element e){
    if(isFull(Q))
        printf("Full\n");
    else{
        Q->rear = (Q->rear+1)%N;
        Q->data[Q->rear] = e;
    }
}

void print(QueueType *Q){
    printf("Front : %d - Rear : %d\n", Q->front, Q->rear);
    for(int i=Q->front+1 ; i<= Q->rear ; i++){
        printf("[%c] ", Q->data[i]);
    }
    printf("\n");
}

element dequeue(QueueType *Q){
    if(isEmpty(Q)){
        printf("Empty");
        return 0;
    }
    Q->front++;
    return Q->data[Q->front];
}

element peek(QueueType *Q){
    if(isEmpty(Q)){
        printf("Empty");
        return 0;
    }
    Q->front++;
    return Q->data[Q->front];
}

int main(){
    QueueType Q;
    init(&Q);
    srand(time(NULL));

    for(int i=0 ; i<7 ; i++){
        enqueue(&Q, rand() % 26 + 65); // 알파벳 대문자 A~Z의 아스키코드
    }
    
    print(&Q); getchar();

    for(int i=0 ; i<4 ; i++){
        printf("[%c]", dequeue(&Q)); // 알파벳 대문자 A~Z의 아스키코드
    }
    printf("\n");

    return 0;
}