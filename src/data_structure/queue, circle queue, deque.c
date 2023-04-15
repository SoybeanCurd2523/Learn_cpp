// // 내가 쓴 원형 큐
// #include <stdio.h>
// #include <stdlib.h>
// #include <time.h>

// #define MAX_QUEUE_SIZE 100

// typedef char element;

// typedef struct 
// {
//     int front, rear;
//     element data[MAX_QUEUE_SIZE];
// }QueueType;

// void init(QueueType *Q){
//     Q->front = 0;
//     Q->rear = 0;
// }

// int isFull(QueueType *Q){
//     if( (Q->rear + 1) % MAX_QUEUE_SIZE == Q->front)
//         return 1;
//     else    
//         return 0;
// }

// int isEmpty(QueueType *Q){
//     if(Q->front == Q->rear)
//         return 1;
//     else    
//         return 0;
// }

// void enqueue(QueueType *Q, element e){
//     if(isFull(Q)){
//         printf("full\n");
//         return;
//     }
//     else{
//         Q->rear = (Q->rear + 1) % MAX_QUEUE_SIZE;
//         Q->data[Q->rear] = e;
//     }
// }

// // dequeue는 맨 앞에 있는(가장 front쪽에 있는) 원소를 제거하고 반환하는 거라면, front 위치 변함
// // peek은 맨 앞에 있는(가장 front쪽에 있는) 원소를 읽어서 반환하는것이다. front 위치 안변함
// element peek(QueueType *Q){ 
//     if(isEmpty(Q)){
//         printf("Empty");
//         return 0;
//     }
//     return Q->data[ (Q->front + 1) % MAX_QUEUE_SIZE];
// }

// element dequeue(QueueType *Q){
//     if(isEmpty(Q)){
//         printf("empty\n");
//         return 0;
//     }
//     else{
//         Q->front = (Q->front + 1) % MAX_QUEUE_SIZE;
//         return Q->data[Q->front];
//     }
// }

// void print(QueueType *Q){
//     printf("front : %d, rear : %d\n", Q->front, Q->rear);

//     for(int i=Q->front + 1 ; i<= Q->rear ; i++)
//         printf("%c ", Q->data[i]);

//     printf("\n");
// }

// int main(){
//     QueueType Q;
//     init(&Q);
//     srand(time(NULL));

//     for(int i=0 ; i<7 ; i++)
//         enqueue(&Q, rand()%26 + 65);
    
//     print(&Q);

//     getchar();
//     printf("deleted : %c \n", dequeue(&Q)); print(&Q);
//     printf("deleted : %c \n", dequeue(&Q)); print(&Q);
//     printf("deleted : %c \n", dequeue(&Q)); print(&Q);

//     getchar();

//     printf("peeked : %c\n", peek(&Q)); print(&Q);

//     return 0;
// }


// // 내가 쓴 선형 큐
// #include <stdio.h>
// #include <stdlib.h>

// #define MAX_QUEUE_SIZE 100

// typedef char element;

// typedef struct 
// {
//     int front;
//     int rear;
//     element data[MAX_QUEUE_SIZE];
// }QueueType;

// void init(QueueType *Q){
//     Q->front = -1;
//     Q->rear = -1;
// }

// int isFull(QueueType *Q){
//     if(Q->rear == MAX_QUEUE_SIZE - 1)
//         return 1;
//     else    
//         return 0;
// }

// int isEmpty(QueueType *Q){
//     if(Q->rear == Q->front)
//         return 1;
//     else    
//         return 0;
// }

// void enqueue(QueueType *Q, element e){
//     if(isFull(Q)){
//         printf("full\n");
//         return;
//     }
//     else{
//         Q->rear++;
//         Q->data[Q->rear] = e;
//     }
// }

// element dequeue(QueueType *Q){
//     if(isEmpty(Q)){
//         printf("empty\n");
//         return -1;
//     }
//     else{
//         Q->front++;
//         return Q->data[Q->front];
//     }
// }

// void print(QueueType *Q){
//     printf("front : %d, rear : %d\n", Q->front, Q->rear);
//     for(int i=Q->front + 1 ; i<= Q->rear ; i++)
//         printf("%c ", Q->data[i]);
    
//     printf("\n");
// }

// int main(){
//     QueueType Q;
//     init(&Q);

//     enqueue(&Q, 'a'); print(&Q);
//     enqueue(&Q, 'b'); print(&Q);
//     enqueue(&Q, 'c'); print(&Q);

//     getchar();

//     printf("deleted : %c\n", dequeue(&Q)); print(&Q);
//     printf("deleted : %c\n", dequeue(&Q)); print(&Q);
//     printf("deleted : %c\n", dequeue(&Q)); print(&Q);

//     return 0;
// }


// 원형 덱

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_DEQUE_SIZE 10

typedef char element;

typedef struct
{
    element data[MAX_DEQUE_SIZE];
    int front, rear;
}DequeType; // 덱

void init(DequeType *D){
    D->front = D->rear = 0;
}

int isEmpty(DequeType *D){
    return D->front == D->rear;
}

int isFull(DequeType *D){
    return (D->rear + 1) % MAX_DEQUE_SIZE == D->front;
}

void addFront(DequeType *D, element e){ // deleteRear와 addFront는 원형큐에서와 다르게 반대 방향의 회전이 필요
    if(isFull(D))                       // 삽입하고 front 옮김.    반시계 방향
        printf("full\n");
    else{
        D->data[D->front] = e; // 기존에 front가 가르키던 인덱스에 원소 대입
        // 만약 기존 front가 0 이라면, -1이(음수) 되서는 안되므로, 아래 연산으로 N-1의 위치로 가게 함
        D->front = (D->front - 1 + MAX_DEQUE_SIZE) % MAX_DEQUE_SIZE;
    }
}

void addRear(DequeType *D, element e){ // 원형큐의 enqueue. rear 옮기고 삽입.   시게방향
    if(isFull(D))
        printf("full\n");
    else{
        D->rear = (D->rear + 1) % MAX_DEQUE_SIZE;
        D->data[D->rear] = e;
    }
}

element deleteFront(DequeType *D){ // 원형큐의 dequeue. front 옮기고 반환.   시계방향
    if(isEmpty(D)){   
        printf("empty\n");
        return 0;
    }
    else{
        D->front = ( D->front + 1) % MAX_DEQUE_SIZE;
        return D->data[D->front];
    }
}

element deleteRear(DequeType *D){ // deleteRear와 addFront는 원형큐에서와 다르게 반대 방향의 회전이 필요
    if(isEmpty(D)){               // 기존 rear 저장해놓고, rear 옮기고, 기존 rear로 반환.   반시계 방향
        printf("empty\n");
        return 0;
    }
    else{
        int pos = D->rear;
        D->rear = (D->rear -1 + MAX_DEQUE_SIZE) % MAX_DEQUE_SIZE;
        return D->data[pos];
    }  
}

element GetFront(DequeType *D){ // 원형큐의 peek
    if(isEmpty(D)){
        printf("empty\n");
        return 0;
    }
    return D->data[ (D->front + 1) % MAX_DEQUE_SIZE];
}

element GetRear(DequeType *D){
    if(isEmpty(D)){
        printf("empty\n");
        return 0;
    }
    return D->data[D->rear];
}

void print(DequeType *D)
{
    printf("F : %d, R : %d\n", D->front, D->rear);
    
    int i = D->front;
    while(i != D->rear)
    {
        i = (i + 1) % MAX_DEQUE_SIZE;
        printf("%c ", D->data[i]);
    }
    printf("\n");    
}

int main(){
    DequeType D;
    init(&D);

    srand(time(NULL));

    addRear(&D, 'A');
    addRear(&D, 'B');
    addRear(&D, 'C');

    print(&D); getchar();

    addFront(&D, 'D');
    addFront(&D, 'E');
    addFront(&D, 'F');
    addFront(&D, 'G');

    print(&D); getchar();

    printf("deleted : %c\n", deleteFront(&D));
    printf("deleted : %c\n", deleteFront(&D));
    printf("deleted : %c\n", deleteFront(&D));

    print(&D); getchar();

    printf("deleted : %c\n", deleteRear(&D));

    print(&D);
    return 0;
}