// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h> // strlen 쓰려고

// #define N 100 // 배열의 사이즈

// typedef struct { // 이름이 안나왔으면 연결된 표현법이 아니다
//     char data[N];
//     int top; // 가장 최근에 입력된 자료를 가르키는 인덱스이다.
// }StackType; // stack을 쓰기 위해서 새로운 데이터 타입을 만듦 

// void init(StackType *S)
// {
//     S->top = -1;
// }

// int isEmpty(StackType *S){
//     return S->top == -1;
// }

// int isFull(StackType *S){
//     return S->top == N-1; // 여기서 == 쓰는거 주의
// }

// void push(StackType *S, char c){
//     if(isFull(S))
//         printf("Full\n");
//     else{
//         S->top++;
//         S->data[S->top] = c;
//     }
// }

// char pop(StackType *S){
//     if(isEmpty(S)){  // 이 함수가 이미 메인에서 S를 주소로 받아왔다.
//         printf("Empty\n");
//         return -1;
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

// // int evaluate(char exp[]){
// //     StackType S;
// //     init(&S);
    
// //     int op1, op2, value; // 연산자 2개, 정수형 변수 1개
// //     char c;

// //     int n=strlen(exp);
// //     push(&S, op1 + op2);

// //     for(int i=0 ; i<n ; i++){
// //         c = exp[i];

// //         if(c != '+' && c != '-' && c != '*' && c != '/') // c가 연산자가 아니면(즉, 숫자면)
// //         {
// //             value = c - '0'; // 재가 48이라, 3의 ascii 코드인 51-48 이니 3이 된다.
// //             push(&S, value);
// //         }
// //         else{ // 연산자이면
// //             op2 = pop(&S);
// //             op1 = pop(&S);

// //             switch (c)
// //             {
// //             case '+':
// //                 push(&S, op1 + op2);
// //                 break;
            
// //             case '-':
// //                 push(&S, op1 - op2);
// //                 break;   

// //             case '*':
// //                 push(&S, op1 * op2);
// //                 break;        

// //             case '/':
// //                 push(&S, op1 / op2);
// //                 break;

// //             default:
// //                 break;
// //             }
// //         }
// //     }
// //     return pop(&S);
// // }


///////////

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


int prec(char op){
    switch(op){
    case '(': case ')':
        return 0;
    
    case '+': case '-':
        return 1;

    case '*': case '/':
        return 2;
    }
}

void convert(char exp[]){
    StackType S;
    init(&S);
    char c, t;
    int n = strlen(exp);

    for(int i=0 ; i<n ; i++){
        c=exp[i];
        switch (c)
        {
        case '+':
        case '-':
        case '*':
        case '/':
            while (!isEmpty(&S) && prec(c) <= prec(peek(&S)))
                printf("%c", pop(&S));

            push(&S,c);
            break;

        case '(':
            push(&S,c);
            break;

        case ')':
            t = pop(&S);
            while (t!= '('){
                printf("%c", t);
                t = pop(&S);
            }
            break;

        default:
            printf("%c", c);
            break;
        }
    }
    while (!isEmpty(&S))
        printf("%c", pop(&S));

    printf("\n");
}

int main(){
    char exp[N]; // 문자열 배열
    scanf("%s", exp); // 배열은 이름이 주소니까 & 필요없다.

    convert(exp); // 중위표기식을 후위표기식으로

    // printf("%d\n", evaluate(exp));

    return 0;
}





////////////



// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h> // strlen 쓰려고

// #define N 100 // 배열의 사이즈

// typedef struct { // 이름이 안나왔으면 연결된 표현법이 아니다
//     char data[N];
//     int top; // 가장 최근에 입력된 자료를 가르키는 인덱스이다.
// }StackType; // stack을 쓰기 위해서 새로운 데이터 타입을 만듦 

// void init(StackType *S)
// {
//     S->top = -1;
// }

// int isEmpty(StackType *S){
//     return S->top == -1;
// }

// int isFull(StackType *S){
//     return S->top == N-1; // 여기서 == 쓰는거 주의
// }

// void push(StackType *S, char c){
//     if(isFull(S))
//         printf("Full\n");
//     else{
//         S->top++;
//         S->data[S->top] = c;
//     }
// }

// char pop(StackType *S){
//     if(isEmpty(S)){  // 이 함수가 이미 메인에서 S를 주소로 받아왔다.
//         printf("Empty\n");
//         return -1;
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

// // int evaluate(char exp[]){
// //     StackType S;
// //     init(&S);
    
// //     int op1, op2, value; // 연산자 2개, 정수형 변수 1개
// //     char c;

// //     int n=strlen(exp);
// //     push(&S, op1 + op2);

// //     for(int i=0 ; i<n ; i++){
// //         c = exp[i];

// //         if(c != '+' && c != '-' && c != '*' && c != '/') // c가 연산자가 아니면(즉, 숫자면)
// //         {
// //             value = c - '0'; // 재가 48이라, 3의 ascii 코드인 51-48 이니 3이 된다.
// //             push(&S, value);
// //         }
// //         else{ // 연산자이면
// //             op2 = pop(&S);
// //             op1 = pop(&S);

// //             switch (c)
// //             {
// //             case '+':
// //                 push(&S, op1 + op2);
// //                 break;
            
// //             case '-':
// //                 push(&S, op1 - op2);
// //                 break;   

// //             case '*':
// //                 push(&S, op1 * op2);
// //                 break;        

// //             case '/':
// //                 push(&S, op1 / op2);
// //                 break;

// //             default:
// //                 break;
// //             }
// //         }
// //     }
// //     return pop(&S);
// // }

// int prec(char op){
//     switch(op){
//     case '(': case ')':
//         return 0;
    
//     case '+': case '-':
//         return 1;

//     case '*': case '/':
//         return 2;
//     }
// }

// void convert(char exp[]){
//     StackType S;
//     init(&S);
//     char c, t;
//     int n = strlen(exp);

//     for(int i=0 ; i<n ; i++){
//         c=exp[i];
//         switch (c)
//         {
//         case '+':
//         case '-':
//         case '*':
//         case '/':
//             while (!isEmpty(&S) && prec(c) <= prec(peek(&S)))
//                 printf("%c", pop(&S));

//             push(&S,c);
//             break;

//         case '(':
//             push(&S,c);
//             break;

//         case ')':
//             t = pop(&S);
//             while (t!= '('){
//                 printf("%c", t);
//                 t = pop(&S);
//             }
//             break;

//         default:
//             push(&S,c);
//             break;
//         }
//     }
//     while (!isEmpty(&S))
//         printf("%c", pop(&S));

//     printf("\n");
// }

// int main(){
//     char infix[N], postfix[N]; // 문자열 배열
//     scanf("%s", infix); // 배열은 이름이 주소니까 & 필요없다.

//     convert(infix, postfix); // 중위표기식을 후위표기식으로

//     printf("%d\n", evaluate(exp));

//     return 0;
// }
//코드는 복사, 실행화면은 캡쳐







