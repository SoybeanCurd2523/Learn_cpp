#include <stdio.h>

#define N 100

typedef int element;

typedef struct
{
    element heap[N]; // 완전이진트리의 역할을 할 배열을 만든다. 일차원배열
    int heapSize; // 가장 말단에 있는 애의 위치를 가리키는 동시에 전체 요소의 개수를 나타냄
}HeapType;

void init(HeapType *H)
{
    H->heapSize = 0;
}

void upHeap(HeapType *H)
{
    int i=H->heapSize; // 말단 노드의 인덱스
    element key = H->heap[i]; // 말단 노드의 키

    while( (i != 1) && (key > H->heap[i/2]) ) // 말단 노드의 키가 부모 노드의 키보다 클 때
    {
        H->heap[i] = H->heap[i/2];
        i/=2; // 인덱스  i가 절반으로 감소(자식노드에서 부모노드로) 하며 진행됨
    }
    H->heap[i] = key;
}

void downHeap(HeapType *H)
{
    element key = H->heap[1];
    int parent = 1, child = 2;

    while(child <= H->heapSize)
    {
        if( (child < H->heapSize) && (H->heap[child+1] > H->heap[child]) ) // 두 자식 노드 중에서 더 큰 값을 갖는 자식 노드를 찾습니다.
            child++;
        
        if(key >= H->heap[child])
            break;
        
        H->heap[parent] = H->heap[child];
        parent = child;
        child *= 2;
    }
    H->heap[parent] = key;
}

void insertItem(HeapType *H, element key)
{
    H->heapSize++; // 루트의 배열에서 인덱스는 0이 아니라 1임
    H->heap[H->heapSize] = key;
    upHeap(H);
}

element deleteItem(HeapType *H)  //  힙에서 삭제는 최대값(즉, 루트 노드)를 삭제하는 것이다.
{
    element key = H->heap[1]; // 루트 노드의 키값 저장
    H->heap[1] = H->heap[H->heapSize];
    H->heapSize--;
    downHeap(H);

    return key; // 루트 노드 키값 반환
}

void printHeap(HeapType *H)
{
    for(int i=1; i<=H->heapSize ; i++)
        printf("%d ", H->heap[i]);

    printf("\n");
}

int main(){
    HeapType H;
    init(&H);

    insertItem(&H, 9); insertItem(&H, 7); insertItem(&H, 6); 
    insertItem(&H, 5); insertItem(&H, 4); insertItem(&H, 3);
    insertItem(&H, 2); insertItem(&H, 2); insertItem(&H, 1);
    insertItem(&H, 3); 

    printHeap(&H);
    getchar();

    // insertItem(&H, 8);
    // printHeap(&H);

    deleteItem(&H);
    printHeap(&H);

    return 0;
}

/*
힙 : 완전이진트리. 일차원 배열로 구현
key(부모노드) >= key(자식노드)
왼쪽 자식 인덱스 = 부모 노드 인덱스 * 2
오른쪽 자식 인덱스 = 부모 노드 인덱스 *2 + 1
부모 인덱스 = 자식 인덱스 / 2
힙사이즈 = 전체 노드의 개수 = 말단 노드의 인덱스
*/