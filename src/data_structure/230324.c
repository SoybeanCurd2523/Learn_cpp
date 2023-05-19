#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 3

void makeMatrix(int A[N][N]){ // 일차원배열은 *A도 가능, 근데 이차원배열은 불가능
    for(int i=0 ; i<N ; i++) // 행
        for(int j=0 ; j<N ; j++) // 열
            if(rand()%2 == 0) //50%의 확률로.
                A[i][j] = rand() % 10; // 한 자리 숫자
            else
                A[i][j] = -(rand()%10);
}

void printMatrix(int A[N][N]){
    for(int i=0 ; i<N ; i++){
        for(int j=0 ; j<N ; j++){
            printf("%3d ", A[i][j]);
        }
        printf("\n");
    }
}

void transposeMatrix(int A[N][N]){
    for(int i=0 ; i<N ; i++){
        for(int j=0 ; j<N ; j++){
            printf("%3d ", A[j][i]);
        }
        printf("\n");
    }
}

void mulMatrix(int A[N][N], int B[N][N], int C[N][N]){
    for(int i=0 ; i<N ; i++){
        for(int j=0 ; j<N ; j++){
            C[i][j] = 0;
            for(int k=0 ; k<N ; k++){
                C[i][j] = C[i][j] + A[i][k]*B[k][j];
            }
        }
    }
}

int main(){
    int A[N][N], B[N][N], C[N][N]; // 행렬(이차원 배열) 선언
    srand(time(NULL));

    makeMatrix(A); // 배열의 이름은 주소
    makeMatrix(B);

    printMatrix(A);
    printf("\n");

    printMatrix(B);
    printf("\n");

    transposeMatrix(A); // 전치행렬
    printf("\n");

    transposeMatrix(B);
    printf("\n");

    mulMatrix(A,B,C); // 행렬곱. C=AxB
    printMatrix(C);
    printf("\n");

    return 0;
}