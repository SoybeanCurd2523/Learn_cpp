// #include <stdio.h>
// #include <stdlib.h>
// #include <time.h>

// #define N 10

// typedef char element;

// typedef struct
// {
//     element data[N];
//     int front, rear;
// }DequeType;

// void init(DequeType *D)
// {
//     D->front = D->rear = 0;
// }

// int isEmpty(DequeType *D)
// {
//     return D->rear == D->front;
// }

// int isFull(DequeType *D)
// {
//     return D->front == (D->rear + 1) % N;
// }

// void addFront(DequeType *D, element e)
// {
//     if(isFull(D))
//         printf("Full\n");
//     else
//     {
//         D->data[D->front] = e;
//         D->front = (D->front - 1 + N) % N;
//     }
// }

// void addRear(DequeType *D, element e)
// {
//     if(isFull(D))
//         printf("Full\n");
//     else
//     {
//         D->rear = (D->rear + 1) % N;
//         D->data[D->rear] = e;
//     }
// }

// element deleteFront(DequeType *D)
// {
//     if(isEmpty(D))
//     {
//         printf("Empty.\n");
//         return 0;
//     }
    
//     D->front = (D->front + 1) % N;
//     return D->data[D->front];
// }

// element deleteRear(DequeType *D){
//     if(isEmpty(D))
//     {
//         printf("Empty.\n");
//         return 0;
//     }

//     int pos = D->rear;
//     D->rear = (D->rear - 1 + N) % N;
//     return D->data[pos];
// }

// element GetFront(DequeType *D)
// {
//     if(isEmpty(D))
//     {
//         printf("Empty.\n");
//         return 0;
//     }
    
//     return D->data[(D->front+1) % N];
// }

// element getRear(DequeType *D){
//     if(isEmpty(D))
//     {
//         printf("Empty.\n");
//         return 0;
//     }
//     return D->data[D->rear];
// }

// void print(DequeType *D)
// {
//     printf("F : %d, R : %d\n", D->front, D->rear);
    
//     int i = D->front;
//     while(i != D->rear)
//     {
//         i = (i + 1) % N;
//         printf("%c ", D->data[i]);
//     }
//     printf("\n");    
// }

// int main()
// {
//     DequeType D;
//     init(&D);
//     srand(time(NULL));
    
//     for(int i = 0; i < 3; i++)
//         addRear(&D, rand() % 26 + 65);
//     print(&D);   getchar();

//     for(int i = 0; i < 4; i++)
//         addFront(&D, rand() % 26 + 65);
//     print(&D);   getchar();

//     for(int i = 0; i < 2; i++)
//         deleteRear(&D);
//     print(&D);   getchar();

//     for(int i = 0; i < 3; i++)
//         deleteFront(&D);
//     print(&D);   getchar();

//     return 0;
// }



// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>

// #define N 10

// typedef char element;

// typedef struct
// {
//     element data[N];
//     int front, rear;
// }DequeType;

// void init(DequeType *D)
// {
//     D->front = D->rear = 0;
// }

// int isEmpty(DequeType *D)
// {
//     return D->rear == D->front;
// }

// int isFull(DequeType *D)
// {
//     return D->front == (D->rear + 1) % N;
// }

// void addFront(DequeType *D, element e)
// {
//     if(isFull(D))
//         printf("Full\n");
//     else
//     {
//         D->data[D->front] = e;
//         D->front = (D->front - 1 + N) % N;
//     }
// }

// void addRear(DequeType *D, element e)
// {
//     if(isFull(D))
//         printf("Full\n");
//     else
//     {
//         D->rear = (D->rear + 1) % N;
//         D->data[D->rear] = e;
//     }
// }

// element deleteFront(DequeType *D)
// {
//     if(isEmpty(D))
//     {
//         printf("Empty.\n");
//         return 0;
//     }
    
//     D->front = (D->front + 1) % N;
//     return D->data[D->front];
// }

// element deleteRear(DequeType *D){
//     if(isEmpty(D))
//     {
//         printf("Empty.\n");
//         return 0;
//     }

//     int pos = D->rear;
//     D->rear = (D->rear - 1 + N) % N;
//     return D->data[pos];
// }

// element GetFront(DequeType *D)
// {
//     if(isEmpty(D))
//     {
//         printf("Empty.\n");
//         return 0;
//     }
    
//     return D->data[(D->front+1) % N];
// }

// element getRear(DequeType *D){
//     if(isEmpty(D))
//     {
//         printf("Empty.\n");
//         return 0;
//     }
//     return D->data[D->rear];
// }

// void print(DequeType *D)
// {
//     printf("F : %d, R : %d\n", D->front, D->rear);
    
//     int i = D->front;
//     while(i != D->rear)
//     {
//         i = (i + 1) % N;
//         printf("%c ", D->data[i]);
//     }
//     printf("\n");    
// }

// int getCount(DequeType *D){
//     int count = D->rear - D->front;
//     if(count < 0)
//         count+=N;

//     return count;
// }

// int main()
// {
//     DequeType D;
//     init(&D);
    
//     char str[N];

//     scanf("%s", &str);

//     for(int i=0 ; i<strlen(str) ; i++){
//         addRear(&D, str[i]);
//     }
//     int equal = 1; // flag 변수. 상태 정보 기억

//     while(getCount(&D) > 1&& equal == 1){
//         char first = deleteFront(&D);
//         char last = deleteRear(&D);
//         if(first != last)
//             equal = 0;
//     }

//     if(equal == 1)
//         printf("YES\n"); // 회문이다
//     else
//         printf("No\n");

//     return 0;
// }






#include <stdio.h>
#include <stdlib.h>

#define N 10

typedef char element;

typedef struct
{
    element data[N];
    int size;
}ListType;

void init(ListType *L)
{
    L->size = 0;
}

int isEmpty(ListType *L)
{
    return L->size == 0;
}

int isFull(ListType *L)
{
    return L->size == N;
}

void insertLast(ListType *L, element e)
{
    if(isFull(L))
        printf("Full\n");
    else{
        L->data[L->size] = e;
        L->size++;
    }
}

void insert(ListType *L, int pos, element e)
{
    if(!isFull(L) && pos >= 0 && pos <= L->size){
        for(int i= L->size-1 ; i>= pos ; i--)
            L->data[i+1] = L->data[i];

        L->data[pos] = e;
        L->size++;
    }
}

element delete(ListType *L, int pos)
{
    if(isEmpty(&L) || pos <0 || pos>=L->size){
        printf("Error\n");
        return -1;
    }
    element data = L->data[pos];
    for (int i = pos ; i < (L->size-1) ; i++)
    {
        L->data[i] = L->data[i+1];
    }

    L->size--;
    return data;
}

void print(ListType *L)
{
      for (int i = 0; i < L->size; i++)
      {
        printf("%c ", L->data[i]);
      }
      printf("\n");
}

int main()
{
    ListType L;
    init(&L);

    insertLast(&L, 'A'); print(&L);
    insertLast(&L, 'B'); print(&L);
    insertLast(&L, 'C'); print(&L);
    getchar();

    insert(&L, 0, 'D'); print(&L);
    insert(&L, 2, 'F'); print(&L);
    getchar();

    printf("%c is deleted.\n", delete(&L, 3)); print(&L);
    return 0;
}