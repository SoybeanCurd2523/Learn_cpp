#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 10
#define FALSE 0
#define TRUE 1

#define SWAP(x, y, t) ((t) = (x), (x) = (y), (y) = (t)) // 매크로 함수

void printPass(int A[], int i)
{
    printf(" %d pass >> ", i);
    for(int i=0 ; i<N ; i++)
        printf(" %d", A[i]);
    printf("\n");
}

void insertionSort(int A[]) // 삽입 정렬
{
    printf("before sort : ");
    for(int i=0 ; i<N ; i++)
        printf("%d ", A[i]);
    printf("\n");

    printf("\n<<<<<<<<<<<insertion sort>>>>>>>>>>>>\n");

    for(int i=1 ; i<N-1 ; i++)
    {
        int key = A[i];

        int j = i-1;

        while(j >= 0 && A[j] > key)
        {
            A[j+1] = A[j];
            j--;
        }
        A[j+1] = key;

        printPass(A, i);
    }
}

void bubbleSort(int A[]) // 버블 정렬
{
    printf("bubble sort : ");
    for(int i=0 ; i<N ; i++)
        printf("%d ", A[i]);
    printf("\n");

    printf("\n<<<<<<<<<<<bubble sort>>>>>>>>>>>>\n");

    for(int i=1 ; i<N-1 ; i++)
    {
        int temp, flag = FALSE;

        for(int j=1 ; j<=N-i ; j++)
        {
            if(A[j-1] > A[j])
            {   
                flag = TRUE;
                SWAP(A[j-1], A[j], temp);
            }
        }
        if(flag == FALSE) // 플래그(깃발) 상태변화변수 적절히 사용하면 좋음
            break;
            
        printPass(A, i);
    }
}



int main()
{
    int A[N];
    srand(time(NULL));

    for(int i=0 ; i<N ; i++)
    {
        A[i] = rand() % 99;
    }
    // insertionSort(A);

    bubbleSort(A);

    return 0;
}

// 쉘 정렬은 gap 사용 구현 해보기, 합병 정렬
// 특히 퀵 정렬은 문제가 여러가지. 연습해봐야
// 합병 정렬이 퀵 정렬과 다른점 : 항상 반씩 자름
// 기수정렬 XXX
// gateway32@gmail.com