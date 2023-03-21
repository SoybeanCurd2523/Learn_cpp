#include <stdio.h>
#include <stdlib.h>
// 책을 보자
// #define  N 10 // 배열 인덱스

// typedef struct Poly // 다항식
// {
//     int degree; // 다항식의 차수
//     int coef[N]; // 다항식 계수
// }Poly;

// Poly addPoly(Poly A, Poly B){
//     Poly C;
//     int Apos = 0, Bpos = 0, Cpos = 0; // 화살표가 가르키는 항의 배열 인덱스
//     int degA = A.degree; // 화살표가 가르키는 항의 차수
//     int degB = B.degree;

//     C.degree = (degA >= degB) ? degA : degB; // 3항 연산자
    
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
    
// }

// void printPoly(Poly P){
//     int i,j;
//     for(i=0, j=P.degree ; i<=P.degree ; i++, j--)
//         printf("%2dx^%d +", P.coef[i], j);

//     printf("\b\b   \n");
// }

// int main(){

//     Poly a, b, c;
    
//     scanf("%d %d", &a.degree, &b.degree);

//     for(int i=0; i<= a.degree ; i++)
//         scanf("%d", &a.coef[i]);
    
//     for(int i=0; i<= b.degree ; i++)
//         scanf("%d", &b.coef[i]);
        
//     printPoly(a);
//     printPoly(b);

//     c = addPoly(a, b);
//     printf("===============================");
//     printPoly(c);
//     return 0;
// }


#define N 20

typedef struct Poly // 다항식
{
    int coef; 
    int expon;
}Poly;

Poly terms[N] = {{8,3}, {7,1}, {1,0}, {10,3}, {3,2}, {1,0}};
int avail = 6;

char compare(int exponA, int exponB){
    if(exponA > exponB) return '>';
    else if(exponA == exponB) return '=';
    else return '<';
}

void addPoly(int As, int Ae, int Bs, int Be, int *Ce){
    while (As <= Ae && Bs <= Be)
    {
        switch (compare(terms[As].expon, terms[Bs].expon))
        {
        case '>':
            attach(terms[As].coef, terms[As].expon);
            As++;
            break;
        
        case '=':
            int tempCoef = terms[As].coef + terms[Bs].coef;
            if(tempCoef != 0)
                attach(tempCoef, terms[As].expon);

            break;
        case '<':
            attach(terms[Bs].coef, terms[Bs].expon);
            Bs++;
            break;
        default:
            break;
        }
    }
    
}
void printPoly(int s, int e){
    int i,j;
    for(i=s ; i<=e ; i++)
        printf("%2dx^%d +", terms[i].coef, terms[i].expon);

    printf("\b\b   \n");
}

int main(){
    int As=0, Ae=2, Bs=3, Be=5, Cs=avail, Ce; // A의 start, A의 end

    printPoly(As, Ae);
    printPoly(Bs, Be);
    
    addPoly(As, Ae, Bs, Be, &Ce);

    return 0;
}
