#include <stdio.h>
#include <stdlib.h>

#define N 10 // 정점의 개수. 최대 10개까지 쓰겠다
// 인접 행렬 방법

typedef struct
{
    int n;// 전체 정점의 개수
    int adjMat[N][N]; // 인접 행렬
}GraphType;

void init(GraphType *G)
{
    G->n = 0;
    for(int i=0; i<N ; i++)
        for(int j=0 ; j<N ; j++)
            G->adjMat[i][j] = 0; // 처음에는 인접행렬이 없으므로 다 0으로 초기화 
}

void makeVertex(GraphType *G)
{
    G->n++; // n을 증가함으로서 정점을 활성화
}

void insertEdge(GraphType *G, int u, int v)
{
    if(u >= G->n || v >= G->n) // 없는 정점을 연결하라는 거니까
        printf("error.\n");
    else    
        G->adjMat[u][v] = G->adjMat[v][u] = 1; // 무방향 그래프니까
}

void print(GraphType *G)
{
    for(int i=0 ; i< G->n ; i++){
        for(int j=0 ; j < G->n ; j++)
            printf(" %d",G->adjMat[i][j]);
        printf("\n");
    }
}

int main()
{
    GraphType G;
    init(&G);

    int n;
    scanf("%d", &n); // 정점의 개수를 입력받음. 밑에서 정점을 5개 쓰므로 5를 터미널에 입력해야.

    for(int i=0 ; i<n ; i++)
        makeVertex(&G);

    insertEdge(&G, 0, 1); insertEdge(&G, 0, 2); insertEdge(&G, 0, 4);
    insertEdge(&G, 1, 2); insertEdge(&G, 2, 3); insertEdge(&G, 2, 4);
    insertEdge(&G, 3, 4); print(&G);

    
    return 0;
}