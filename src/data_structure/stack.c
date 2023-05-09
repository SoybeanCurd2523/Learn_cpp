#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STACK_SIZE 100
typedef char element;

typedef struct{
    element data[MAX_STACK_SIZE];
    int top; // 가장 최근에 삽입된 데이터를 가르키는 변수
}StackType;

void init(StackType *S){
    S->top = -1;
}

int isFull(StackType *S){
    if(S->top == MAX_STACK_SIZE - 1) return 1;
    else return 0;
}

int isEmpty(StackType *S){
    if(S->top == -1) return 1;
    else return 0;
}

void push(StackType *S, element e){
    if(isFull(S))
        printf("full\n");
    else{
        S->top++;
        S->data[S->top] = e;
    }
}

element pop(StackType *S){
    if(isEmpty(S)){
        printf("empty\n");
        return -1;
    }
    else{
        element e = S->data[S->top];
        S->top--;
        return e;
    }
}

element peek(StackType *S){
    if(isEmpty(S)){
        printf("empty\n");
        return -1;
    }
    else{
        element e = S->data[S->top];
        return e;
    }
}


void print(StackType *S){
    printf("top : %d\n", S->top);
    for(int i=0 ; i <= S->top ; i++)
        printf("%c => ", S->data[i]);
    
    printf("\b\b\b  \n");
}

int check_matching(StackType *S, char str[]){
    int size = strlen(str);

    for(int i=0 ; i<= size - 1 ; i++){
        char ch = str[i];
        
        if(ch == '(' || ch == '{' || ch == '[')
            push(S, ch);
        else if(ch == ')' || ch == '}' || ch == ']'){
            if(isEmpty(S))
                return 0;
            else{
                char mych = pop(S);
                if( (mych == '(' && ch != ')') || (mych == '{' && ch != '}') || (mych == '[' && ch != ']') )
                    return 0;
            }
        } 
    }
    return isEmpty(S);
}

int evaluate(char postfix[])
{
    StackType S;
    init(&S);
    
    int op1, op2, value;
    char c;
    
    int n = strlen(postfix);
    
    for(int i = 0; i < n; i++)
    {
        c = postfix[i];
        
        if(c != '+' && c != '-' && c != '*' && c != '/') // 피연산자이면
        {
            value = c - '0'; // 문자형을 정수형으로
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

int prec(char op){ // 연산자 우선순위
    switch (op)
    {
    case '(': case ')':
        return 0;
    
    case '+': case '-':
        return 1;

    case '*': case '/':
        return 2;
    }
}

void convert(char exp[]){ // 중위표기식을 후위표기식으로

    StackType S;
    init(&S);

    char c, t;
    int n = strlen(exp);

    for(int i=0 ; i<= n-1 ; i++){
        c = exp[i];
        switch (c)
        {
        case '+': case '-': case '*': case '/':
            {
                while(!isEmpty(&S) && prec(peek(&S)) >= prec(c))
                {
                    t = pop(&S);
                    printf("%c", t);
                }
                push(&S, c);
                break;
            }
        
        case '(':
            push(&S, c);
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
    while(!isEmpty(&S)){
        t = pop(&S);
        printf("%c", t);
    }
    printf("\n");

}

int main(){
    // StackType S;
    // init(&S);
    // push(&S, 'A'); print(&S); 
    // push(&S, 'B'); print(&S);
    // push(&S, 'C'); print(&S);

    // printf("pop : %c\n", pop(&S)); print(&S);
    // printf("peek :%c\n", peek(&S)); print(&S);
    
    // char str[] = "{a[(i+1)]=0;}";
    // char str[MAX_STACK_SIZE];
    // scanf("%c", str);

    // if(check_matching(&S, str) == 1) printf("matching. \n");
    // else printf("no matching. \n");
    // printf("top : %d\n", S.top);

    char exp[MAX_STACK_SIZE];
    scanf("%s", exp); // %c가 아니라 문자열을 입력받을때는 %s 주의

    // printf("postfix evaluate: %d\n", evaluate(exp));
    convert(exp);
    // print(&S);
    return 0;
}

