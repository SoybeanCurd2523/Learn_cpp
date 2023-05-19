#include <stdio.h> // 표준입출력
#include <stdlib.h> // 동적 메모리 할당, 난수 발생 등

// int main(){

//     int a, b;

//     scanf("%d %d", &a, &b); //a는 변수의 이름. & ampersand      %d는 형식지정자

//     printf("%d + %d = %d\n", a, b, a+b); //문자열을 출력  문자 '' 이지만 문자열 "" 끝에 \0 포함

//     printf("Hi");

//     printf("\n"); // escape sequence
//     return 0;
// }

// c언어기본문법 문제1
int main(){
    int price, cnt, money; // 햄버거 1개의 가격, 구매하려는 햄버거 개수, 내 지갑에 있는 돈
    int total;

    scanf("%d %d %d", &price, &cnt, &money);

    total = price * cnt;

    if(total >= money){
        printf("모자란 금액 : %d\n", total - money);
    }
    else{
        printf("금액이 모자라지 않습니다.\n");
    }

    return 0;
}