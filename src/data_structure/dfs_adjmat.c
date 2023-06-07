// 인접 행렬로 표현된 그래프에 대한 깊이우선탐색 프로그램

#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0
#define N 50

typedef struct{
    int n; // 정점의 개수    
    int adjMat[N][N];
}GraphType;

int visited[N]; // dfs 시 정점 방문 여부를 기록하기 위한 배열. FALSE로 초기화되고, 정점이 방문될 때마다 해당 정점의 visited 배열값은 TRUE로 변경된다.

void init(GraphType *G) // 인접행렬의 모든 원소를 0으로 초기화
{
    G->n = 0;
    for(int i=0; i<N ; i++)
        for(int j=0 ; j<N ; j++)
            G->adjMat[i][j] = 0;
}

void insert_vertex(GraphType *G, int v) // 정점을 추가하기
{
    G->n++;
}

void insert_edge(GraphType *G, int u, int v) // 간선을 추가하기
{
    G->adjMat[u][v] = G->adjMat[v][u] = 1;
}

void dfs_adjmat(GraphType *G, int v) // 깊이우선탐색. 인자 : 그래프, 시작 정점
{
    int w;
    visited[v] = TRUE; // 방문한 정점 기록하기
    printf("정점 %d -> ", v);

    for(w = 0 ; w < G->n ; w++) // 모든 정점에 대해서. 0번 정점, 1번정점 ..... 오름차순
        if(G->adjMat[v][w] == 1 && visited[w] == FALSE) // 정점 v부터 w까지 간선이 존재하고, 정점 w를 방문하지 않았다면
            dfs_adjmat(G, w); // 정점 w에서 dfs 다시 시작
}

void print_vertex(GraphType *G) 
{
    for(int i=0 ; i<G->n ; i++)
    {
        for(int j=0 ; j<G->n ; j++)
            printf(" %d", G->adjMat[i][j]);
        printf("\n");
    }
}

int main()
{
    GraphType G;
    init(&G);

    for(int i=0 ; i < 7 ; i++)
        insert_vertex(&G, i);

    insert_edge(&G, 0, 1);
    insert_edge(&G, 0, 2);

    insert_edge(&G, 1, 3);
    insert_edge(&G, 1, 4);

    insert_edge(&G, 2, 5);
    insert_edge(&G, 2, 6);

    printf("깊이우선탐색\n");
    dfs_adjmat(&G, 0);
// 깊이우선탐색
// 정점 0 -> 정점 1 -> 정점 3 -> 정점 4 -> 정점 2 -> 정점 5 -> 정점 6 -> 

    printf("\n\n\n");
    return 0;
}