#include <stdio.h>
#include <stdlib.h>

//factorial
// int iFact(int n){ // iteration factorial
//     int r=1; // 곱의 결과는 1로 초기화. 반대로 합의 결과는 0으로 초기화.

//     for(int i=1 ; i<=n ; i++){ // n번 프로세서에서 연산. 빠름
//         r*=i;
//     }
//     return r;
// }

// int rFact(int n){ //recursive factorial
//     if(n == 1)
//         return 1;
//     else
//         return n*rFact(n-1);// n번 연산
//                             // n번 함수호출 -> 메인 메모리에서 연산. 느림
//                             // 대부분의 경우 반복문이 효율적이긴 함.
// }

// int main(){
//     int n;
//     scanf("%d", &n);

//     printf("%d %d \n", iFact(n), rFact(n));
//     return 0;
// }

//power
// int iPower(int x, int n){
//     int r=1;
//     for(int i=1 ; i<=n ; i++){
//         r*=x; 
//     }
//     return r;
// }

// int rPower(int x, int n){
//     if(n==0)
//         return 1;
//     else if(n%2 == 0)
//         return rPower(x*x, n/2);
//     else    
//         return x*rPower(x*x, (n-1)/2);
// }

// int main(){
//     int x, n;
//     scanf("%d %d", &x, &n);

//     printf("%d %d \n", iPower(x, n), rPower(x, n));

//     return 0;
// }


//fibonacci
// int count;
// int rFib(int n){
//     count++;
//     if(n==0)
//         return 0;
//     else if(n==1)
//         return 1;
//     else    // n=2,3,4...
//         return rFib(n-1) + rFib(n-2);
// }

// int main(){
//     int n;
//     scanf("%d", &n);

//     printf("%d %d\n", count, rFib(n));

//     return 0;
// }


//hanoi
void hanoi(int n,char from, char tmp, char to){ // 템플릿 느낌
    if(n==1) // 원반이 하나 남았을 때
        printf("Disk %d : Move from %c to %c. \n", n, from, to); // 가장 큰 원반을 첫번째에서 세번째로
    else{ // 원반이 두개이상 남았을 때
        hanoi(n-1, from, to, tmp); // n-1개를 첫번째 기둥에서 세번째를 거쳐서 두번째로 
        printf("Disk %d : Move from %c to %c. \n", n, from, to);
        hanoi(n-1, tmp, from, to); //n-1개를 두번째에서 첫번째를 거쳐 세번째로
    }
}

int main(){
    hanoi(4, 'A', 'B', 'C');
    return 0;
}
// 과제 1,2,3,4,5,6
// 소스코드 복사, 실행화면 캡쳐, 보고서 형식으로, 시스템스택을 적어서