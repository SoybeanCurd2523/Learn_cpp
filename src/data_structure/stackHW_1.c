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

char peek(StackType *S){
    if(isEmpty(S)){  // 이 함수가 이미 메인에서 S를 주소로 받아왔다.
        printf("Empty\n");
        return -1;
    }
    return S->data[S->top];
}

void print(StackType *S){
    for(int i=0 ; i<= S->top ; i++){
        printf("%c", S->data[i]);
    }
    printf("\n");
}

int prec(char op){ // 연산자 우선순위 계산
    switch(op)
    {
        case '(': case ')':
            return 0;
        case '+': case '-':
            return 1;
        case '*': case '/':
            return 2;
    }
}

int evaluate(char postfix[]) //후위표기식 계산
{
    StackType S;
    init(&S);
    
    int op1, op2, value;
    char c;
    
    int n = strlen(postfix);
    
    for(int i = 0; i < n; i++)
    {
        c = postfix[i];
        
        if(c != '+' && c != '-' && c != '*' && c != '/')
        {
            value = c - '0';
            push(&S, value);
        }
        else
        {
            op2 = pop(&S);
            op1 = pop(&S);
            
            switch(c)
            {
                case '+':
                    push(&S, op1 + op2);
                    break;
                case '-':
                    push(&S, op1 - op2);
                    break;
                case '*':
                    push(&S, op1 * op2);
                    break;
                case '/':
                    push(&S, op1 / op2);
                    break;
            }
        }
    }
    return pop(&S);
}
 

void convert(char exp[], char cexp[]) // 중위표기식을 후위표기식으로 바꾸는 함수
{
    int i=0, j=0;
    StackType S;
    init(&S);
    
    char c, c2, t;
    int n = strlen(exp);
    
    for(int i = 0; i < n; i++)
    {
        c = exp[i];
        c2 = exp[i+1];
        switch(c)
        {
            case '+': case '-': case '*': case '/': // 연산자의 경우
                while(!isEmpty(&S) && prec(c) <= prec(peek(&S))){
                    cexp[j] = pop(&S);
                    j++;
                }
                push(&S, c);
                break;
                
            case '(': // 괄호의 경우
                push(&S, c);
                break;
            
            case ')':
                t = pop(&S);
                while(t != '(')
                {
                    cexp[j] = t;
                    j++;
                    t = pop(&S);
                }
                break;
            
            default:
                cexp[j] = c;
                j++;
                if (c2 != '+' && c2 != '-' && c2 != '*' && c2 != '/' && c2 != ' ' && c2 != '\0' &&
                c2 != '(' && c2 != ')'){
                    cexp[j] = c2;
                    j++;
                    i++;
                }
                break;
        }
    }
}

int main()
{
 char infix[N], postfix[N];
 scanf("%s", infix);

 convert(infix, postfix);
 printf("%d\n", evaluate(postfix));

 return 0;
}



