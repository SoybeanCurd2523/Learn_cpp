#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 100

typedef struct{
    char data[N];
    int top;
}StackType;

void init(StackType *S){
    S->top = -1;
}

int isEmpty(StackType *S){
    return S->top == -1;
}
int isFull(StackType *S){
    return S->top == N-1;
}


char pop(StackType *S){
    if(isEmpty){
        printf("Empty\n");
        return -1;
    }
    else{
        char c = S->data[S->top];
        S->top--;
        return c;
    }


}
void push(StackType *S, char c){
    if(isFull(S))
        printf("full\n");
    else{
        S->top++;
        S->data[S->top] = c;
    }
}

void print(StackType *S){
    for(int i=0 ; i<=S->top ; i++){
        printf("%c", S->data[i]);
    }
    printf("\n");
}

int main(){
    StackType S;
    init(&S);
    push(&S, 'c');
    printf("top : %d\n", S.top);
    push(&S, 'a');
    printf("top : %d\n", S.top);
    print(&S);

    printf("pop : %c\n", pop(&S));
    printf("top : %d\n", S.top);
    print(&S);

    return 0;
}