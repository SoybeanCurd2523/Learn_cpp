#include <stdio.h>
#include <stdlib.h>


// // 문제2
// int main(){

//     int score;
//     scanf("%d", &score);

//     if(score < 0 || score > 100)
//         printf("wrong input\n");
//     else{
//         if(score >= 90 && score <=100)
//             printf("A\n");
//         else if(score >= 80 && score <90)
//             printf("B\n");
//         else if(score >= 70 && score < 80)
//             printf("C\n");
//         else    
//             printf("D or F\n");
//     }

//     return 0;
// }

// // 문제3
// int main(){

//     int score;
//     scanf("%d", &score);

//     if(score < 0 || score > 100)
//         printf("wrong input\n");
//     else{
//         switch (score/10) // 정수 혹은 문자, 0~100점수를 0~10으로 바꿔버림
//         {
//         case 10:
//         case 9:
//             printf("A\n");
//             break;
        
//         case 8:
//             printf("B\n");
//             break;
            
//         case 7:
//             printf("C\n");
//             break;

//         default:
//             printf("D or F\n");
//             break;
//         }
//     }
//     return 0;
// }

// // 문제4
// int main(){
//     int n;
//     scanf("%d", &n);

//     while(n != 0){
//         printf("%d\n", n%10); // 나머지
//         n = n/10;
//     }
//     // printf("%d", n / 10); // 몫

// }

// // 문제5
// int main(){
//     int n;
//     scanf("%d", &n);

//     int evenSum = 0; // even : 짝수, odd : 홀수
//     int oddSum = 0; // 초기화 필요

//     // for(int i=1 ; i<=n ; i++){ //초깃값, 조건식, 증감식
//     //     if(i%2 == 0) // 짝수
//     //         evenSum+=i;
//     //     else if(i%2 == 1) //홀수
//     //         oddSum+=i;
//     // }

//     int i=1;
//     while(i<=n){ // while에는 조건식밖에 여기에 못들어감
//         if(i%2 == 0) // 짝수
//             evenSum+=i;
//         else if(i%2 == 1) //홀수
//             oddSum+=i;
        
//         i++;
//     }
//     printf("%d\n", evenSum);
//     printf("%d\n", oddSum);
// }

// // 문제6

// void sumOfWeight(int g){
//     int count = 0;

// // 무차별대입법
//     for(int i = 1; i<=10; i++){  //2g 추의 개수
//         for(int j=1 ; j<=10 ; j++){ // 3g 추의 개수
//             for(int k=1 ; k<=10 ; k++){ // 5g 추의 개수
//                 if(2*i + 3*j + 5*k == g){
//                     printf("%d %d %d\n", i, j, k);
//                     count++;
//                 }
//             }
//         }
//     }
//     if(count == 0)
//         printf("0\n");
//     else    
//         printf("%d\n", count);
// }

// int main(){
//     int g;
//     scanf("%d", &g);
//     sumOfWeight(g);

//     return 0;
// }

// 문제7
#include <time.h> // 난수
#define N 10 // 기호 상수

 // 난수 %10 = 난수의 범위 0~9까지 한정
 // 난수 % 100 = 난수의 범위 0~100까지 한정
 // 난수 %100 + 1 = 난수의 범위 1~101까지 한정(임의의 양의 정수. 1부터니까)

void makeArray(int A[]){
    for(int i=0 ; i<N ; i++){ //배열이 나오면 무조건 for이 나온다.
        A[i] = rand() % 100 +1; // 임의의 양의 정수가 나온다.
    }   
}

void printArray(int A[]){ // 주소를 전달해 준다
    for(int i=0 ; i<N ; i++){
        printf("%d ", A[i]);
    }
    printf("\n");
}

int findMax(int A[]){
    int max = A[1]; // 배열의 첫번째 값을 최댓값으로 가정
    for (int i = 0; i < N; i++)
        if(A[i] > max)
            A[i] = max;
        
    return max;
}

int main(){
    int A[N];

    srand(time(NULL));

    makeArray(A);
    printArray(A);

    printf("Max : %d\n", findMax(A));
    return 0;
}       