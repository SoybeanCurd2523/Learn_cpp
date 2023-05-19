#include <stdio.h>
#include <stdlib.h>

// // void swap(int x, int y){ // call-by-value
// //     printf("x : %d, y : %d\n", x, y);
// //     int tmp = x;
// //     x = y;
// //     y = tmp;
// //     printf("x : %d, y : %d\n", x, y);
// // }

// void swap(int *x, int *y){ // call-by-reference. 난 포인터 변수라 너는 주소를 줘야되
//     printf("*x : %d, *y : %d\n", *x, *y);
//     int tmp = *x;
//     *x = *y;
//     *y = tmp;
//     printf("*x : %d, *y : %d\n", *x, *y);
// }

// int main(){
//     int a, b;

//     a = 10;

//     // printf("%p %p\n", &a, &b); // 메모리 주소. 어떤 값을 저장하든 주소값은 4바이트-> 주소를 넘겨주는 call by reference가 효율적

//     scanf("%d %d", &a, &b);

//     printf("a : %d, b : %d\n", a, b);
    
//     // swap(a,b); //call-by-value

//     swap(&a, &b); //call-by-reference

//     printf("a : %d, b : %d\n", a, b);

//     return 0;
// }


// 배열: 자료형이 같은 변수들 보관
// 구조체: 다양한 자료형의 변수들 보관. 클래스와 달리 멤버 변수만 있고 멤버 메소드 없다.
// 배열의 이름은 주소이고(arr = &arr[0]) 그래서 외부함수에 전달할때는 배열이름만 넣고 그 함수에서 *로 받으면 되지만,
//  클래스 이름은 주소가 아니라 값이라서 & 붙여서 전달하고 그 함수에서 * 로 받아야
// struct Test
// {
//     int id;
//     int money;
// };


typedef struct Test
{
    int id;
    int money;
}Test; // 일반적으로 구조체 이름과 typedef 이름은 같게 한다

// void makeAccount(Test T){
//     scanf("%d %d", &T.id, &T.money);
//     printf("%d : %d\n", T.id, T.money);
// }

void add(Test *T, int amount){
    // (*T).money += amount;
    T->money += amount;
    printf("%d : %d\n", T->id, T->money);
}

int main(){

    Test a;
     // makeAccount(a);

    scanf("%d %d", &a.id, &a.money);
    printf("%d : %d\n", a.id, a.money);

    int amount;
    scanf("%d", &amount);

    add(&a, amount);

    printf("%d : %d\n", a.id, a.money);
    return 0;
}
// 1~6 중 코드, 결과 화면 캡쳐
// 5번 하노이탑은 시스템 스택
// 보고서 형식으로 한 파일로1
