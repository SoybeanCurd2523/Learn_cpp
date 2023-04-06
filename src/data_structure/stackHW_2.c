#include <stdio.h>
#include <stdlib.h>
#include <string.h> // strlen 쓰려고

#define N 100 // 배열의 사이즈

typedef struct { // 이름이 안나왔으면 연결된 표현법이 아니다
    char data[N]; // 스택은 1차원 배열이다. 가장 먼저 들어온 요소는 stack[0]에, 가장 최근 요소는 stack[top]에 저장.
    int top; // 가장 최근에 입력된 자료를 가르키는 인덱스이다.
}StackType; // stack을 쓰기 위해서 새로운 데이터 타입을 만듦 

void init(StackType *S) // 스택이 공백상태면은 top은 -1
{
    S->top = -1;
}

int isEmpty(StackType *S){ // 스택이 공백상태인지 검사
    return S->top == -1; // 공백상태이면 1을 반환, 아니면 0 반환
}

int isFull(StackType *S){ // 스택이 포화상태인지 검사. 
    // printf("abcd : %d\n", (S->top == N-1)); 
    return S->top == N-1; // 여기서 == 쓰는거 주의. 포화상태이면(배열의 끝까지 다차면) 1을 반환, 아니면 0 반환
}

void push(StackType *S, char c){
    if(isFull(S)) // 포화상태가 아니어야 push를 한다.
        printf("Full\n");
    else{
        S->top++;
        S->data[S->top] = c;
    }
}

char pop(StackType *S){
    if(isEmpty(S)){  // 공백상태가 아니어야 pop을 한다. // 이 함수가 이미 메인에서 S를 주소로 받아왔다.
        printf("Empty\n");
        return -1; // 의미 없는 값
    }
    char c= S->data[S->top];
    S->top--;
    return c;
}

int palindrome(char exp[]){
    StackType S;
    init(&S);

    for(int i=0 ; exp[i] !=0 ; i++){
        if(exp[i] >= 65 && exp[i] <= 90) // 대문자이면 소문자로 취급
            exp[i] += 32;
        push(&S, exp[i]);
    }
    for(int i=0 ; exp[i] != 0 ; i++){
        if(exp[i] != pop(&S)) return 0;
        return 1;   
    }
}

int main(){
    char exp[N];
    scanf("%s", exp);
    if(palindrome(exp))
        printf("true\n");
    else
        printf("false\n");
    
    return 0;
}