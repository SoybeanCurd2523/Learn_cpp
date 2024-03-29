// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h> // strlen 쓰려고

// #define N 100 // 배열의 사이즈

// typedef struct { // 이름이 안나왔으면 연결된 표현법이 아니다
//     char data[N]; // 스택은 1차원 배열이다. 가장 먼저 들어온 요소는 stack[0]에, 가장 최근 요소는 stack[top]에 저장.
//     int top; // 가장 최근에 입력된 자료를 가르키는 인덱스이다.
// }StackType; // stack을 쓰기 위해서 새로운 데이터 타입을 만듦 

// void init(StackType *S) // 스택이 공백상태면은 top은 -1
// {
//     S->top = -1;
// }

// int isEmpty(StackType *S){ // 스택이 공백상태인지 검사
//     return S->top == -1; // 공백상태이면 1을 반환, 아니면 0 반환1
// }

// int isFull(StackType *S){ // 스택이 포화상태인지 검사. 
//     // printf("abcd : %d\n", (S->top == N-1)); 
//     return S->top == N-1; // 여기서 == 쓰는거 주의. 포화상태이면(배열의 끝까지 다차면) 1을 반환, 아니면 0 반환
// }

// void push(StackType *S, char c){
//     if(isFull(S)) // 포화상태가 아니어야 push를 한다.
//         printf("Full\n");
//     else{
//         S->top++;
//         S->data[S->top] = c;
//     }
// }

// char pop(StackType *S){
//     if(isEmpty(S)){  // 공백상태가 아니어야 pop을 한다. // 이 함수가 이미 메인에서 S를 주소로 받아왔다.
//         printf("Empty\n");
//         return -1; // 의미 없는 값
//     }
//     char c= S->data[S->top];
//     S->top--;
//     return c;
// }

// char peek(StackType *S){
//     if(isEmpty(S)){  // 이 함수가 이미 메인에서 S를 주소로 받아왔다.
//         printf("Empty\n");
//         return -1;
//     }
//     return S->data[S->top];
// }

// void print(StackType *S){
//     for(int i=0 ; i<= S->top ; i++){
//         printf("%c", S->data[i]);
//     }
//     printf("\n");
// }

// int main(){
//     StackType S;
//     init(&S);
//     push(&S, 'c');
//     push(&S, 'a');
//     push(&S, 't');
//     push(&S, 's');
    
//     print(&S);

//     pop(&S);

//     // printf("pop : %c\n", pop(&S)); // printf함수는 이미 있는거고 print는 우리가 만든거다.

//     print(&S);

//     printf("peek : %c\n", peek(&S));
//     print(&S);

//     return 0;
// }













// // 스택의 응용 : 괄호 검사
#include <stdio.h>
#include <stdlib.h>
#include <string.h> // strlen 쓰려고

#define N 100 // 배열의 사이즈

typedef struct { // 이름이 안나왔으면 연결된 표현법이 아니다
    char data[N];
    int top; // 가장 최근에 입력된 자료를 가르키는 인덱스이다.
}StackType; // stack을 쓰기 위해서 새로운 데이터 타입을 만듦 

void init(StackType *S)
{
    S->top = -1;
}

int isEmpty(StackType *S){
    return S->top == -1;
}

int isFull(StackType *S){
    return S->top == N-1; // 여기서 == 쓰는거 주의
}

void push(StackType *S, char c){
    if(isFull(S))
        printf("Full\n");
    else{ 
        S->top++;
        S->data[S->top] = c;
    }
}

char pop(StackType *S){
    if(isEmpty(S)){  // 이 함수가 이미 메인에서 S를 주소로 받아왔다.
        printf("Empty\n");
        return -1;
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

// 입력되는 배열에 괄호가 남아있는지를 검사하는 함수.
// 스택에 괄호가 남아있으면 0(거짓) 반환, 그렇지 않으면 1(참) 반환.
int check(StackType *S, char str[]){

    char c, t;
    int n = strlen(str); // 배열의 길이 확인
    
    for(int i=0 ; i<n ; i++){
        c = str[i];

        if(c == '(' || c == '{' || c == '[') // 왼쪽 괄호를 만나면 스택에 삽입함(push)
            push(S, c);
        else if( c== ')' || c == '}' || c == ']'){ // 오른쪽 괄호를 만나면
            if(isEmpty(S))
                return 0; 
            else{ // 스택이 비어있지 않다면
                t = pop(S); // top 괄호를 삭제하고
                if( (t!='(' && c==')') || (t!='{' && c=='}') || (t!='[' && c==']')){ // 짝이 맞지 않는다면
                    // printf("abcd");
                    return 0; // 거짓
                }
            }   
        }
    }
    return isEmpty(S); // 스택이 공백상태이면 1을 반환. 즉 괄호가 안 남아있으므로 참을 반환
}

int main(){
    StackType S;
    init(&S);

    char str[N];
    scanf("%s", str); // 배열의 이름은 주소이기에 &str이 아니다.

    if(check(&S, str))
        printf("OK\n");
    else    
        printf("NO\n");
    return 0;
}

