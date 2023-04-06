// #include <stdio.h>
// #include <stdlib.h>
// // 책을 보자
// #define  N 10 // 배열의 크기

// typedef struct Poly // 다항식
// {
//     int degree; // 다항식의 차수. x^3 + 2*x + 1 에서 3이다.
//     int coef[N]; // 다항식 계수. coef[0] : 최고차항의 계수... coef[degree] : 상수항의 계수
// }Poly;

// Poly addPoly(Poly A, Poly B){
//     Poly C;
//     int Apos = 0, Bpos = 0, Cpos = 0; // Apos : 화살표가 가르키는 항의 배열 인덱스
//     int degA = A.degree; // degA : 화살표가 가르키는 항의 차수
//     int degB = B.degree;

//     C.degree = (degA >= degB) ? degA : degB; // 3항 연산자. C의 차수는 둘중에 큰놈의 차수로
    
//     while (Apos <= A.degree && Bpos <= B.degree)
//     {
//         if(degA > degB){
//             C.coef[Cpos] = A.coef[Apos];
//             Apos++;
//             Cpos++;
//             degA--;
//         }
//         else if(degA == degB){
//             C.coef[Cpos] = A.coef[Apos] + B.coef[Bpos];
//             Apos++;
//             Bpos++;
//             Cpos++;
//             degA--;
//             degB--;
//         }
//         else{
//             C.coef[Cpos] = B.coef[Bpos];
//             Bpos++;
//             Cpos++;
//             degA--;
//         }
//     }
//     return C;
//     // 다항식 3개를 만든다.
// }

// void printPoly(Poly P){ // call-by-value
//     int i,j;
//     for(i=0, j=P.degree ; i<=P.degree ; i++, j--)
//         printf("%2dx^%d +", P.coef[i], j);

//     printf("\b\b   \n");
// }

// int main(){

//     Poly a, b, c; // 다항식 3개를 만든다.
    
//     scanf("%d %d", &a.degree, &b.degree);

//     for(int i=0; i<= a.degree ; i++) // 반복문을 돌면서 다항식 a의 모든 계수를 배열에 저장
//         scanf("%d", &a.coef[i]);
    
//     for(int i=0; i<= b.degree ; i++)
//         scanf("%d", &b.coef[i]);
        
//     printPoly(a);   // call-by-value
//     printPoly(b);

//     c = addPoly(a, b);
//     printf("===============================");
//     printPoly(c);
//     return 0;
// }

// ////////////////
// //// input : 
// //// 4 3
// //// 1 2 3 4 5
// //// 6 7 8 9
// //// output : 
// //// 4 3
// //// 1 2 3 4 5
// //// 6 7 8 9
// ////  1x^4 + 2x^3 + 3x^2 + 4x^1 + 5x^0   
// ////  6x^3 + 7x^2 + 8x^1 + 9x^0   
// //// ======= 1x^4 + 8x^3 +10x^2 +12x^1 +14x^0   
// //////////////////




#include <stdio.h>
#include <stdlib.h>

#define N 20 //기호 상수

typedef struct Poly // 다항식을 (계수, 차수) 형식으로 배열에 저장
{
    int coef; // 계수
    int expon; // 차수
}Poly;

Poly terms[N] = {{8, 3}, {7, 1}, {1, 0}, {10, 3}, {3, 2}, {1, 0}}; // 다항식을 직접 생성한다. 입력받지 않고
int avail = 6;

char compare(int exponA, int exponB) // a와 b의 차수를 비교해서 비교 연산 문자 리턴
{
    if(exponA > exponB)
        return '>';
    else if(exponA == exponB)
        return '=';
    else
        return '<';
}

void attatch(int coef, int expon) // a+b 인 c 생성
{
    terms[avail].coef = coef;
    terms[avail].expon = expon;
    avail++;
}

void add(int As, int Ae, int Bs, int Be, int Cs, int *Ce)
{
    while(As <= Ae && Bs <= Be)
    {
        switch(compare(terms[As].expon, terms[Bs].expon))
        {
            case '>':{
                attatch(terms[As].coef, terms[As].expon);
                As++;
                break;
            }
                
            case '=':{
                int tempCoef = terms[As].coef + terms[Bs].coef;
                if(tempCoef != 0){
                    attatch(tempCoef, terms[As].expon);
                    As++;  
                    Bs++;
                }
                break;
            }
                
            case '<':{
                attatch(terms[Bs].coef, terms[Bs].expon);
                Bs++;
                break;
            }
        }
    }
    
    for(; As <= Ae; As++)
        attatch(terms[As].coef, terms[As].expon);
    for(; Bs <= Be; Bs++)
        attatch(terms[Bs].coef, terms[Bs].expon);    
        
    *Ce = avail - 1;    
}

void printPoly(int s, int e)
{
    for(int i = s; i <= e; i++)
        printf("%2dx^%d +", terms[i].coef, terms[i].expon);
    printf("\b\b  \n");    
}

int main()
{
    int As = 0, Ae = 2, Bs = 3, Be = 5, Cs = avail, Ce;
    printPoly(As, Ae);
    printPoly(Bs, Be);
    
    add(As, Ae, Bs, Be, Cs, &Ce);
    printf("=========================\n");
    printPoly(Cs, Ce);
    
    return 0;
}
