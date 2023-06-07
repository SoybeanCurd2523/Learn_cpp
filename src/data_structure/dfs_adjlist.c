// 인접 리스트로 표현된 그래프에 대한 깊이우선탐색 프로그램

#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 50
#define TRUE 1
#define FALSE 0

typedef struct GraphNode
{
    int vertex; // 정점
    struct GraphNode *link; // 다음 정점까지 포인터. 자기참조구조체
}GraphNode;

typedef struct GraphType
{
    int n; // 정점의 개수
    GraphNode* adj_list[MAX_VERTICES];
}GraphType;

int visited[MAX_VERTICES]; // 정점 방문 여부 기록

void init(GraphType *g)
{
    g->n = 0;
    for(int i=0 ; i < MAX_VERTICES ; i++)
        g->adj_list[i] = NULL; // 포인터 배열
}

void insert_vertex(GraphType *g, int v) // v번째 정점 삽입 연산
{
    g->n++;
}

void insert_edge(GraphType *g, int u, int v) // 정점u에 간선(u,v)를 삽입하는 연산
{
    GraphNode *node;
    node = (GraphNode*)malloc(sizeof(GraphNode)); // 노드 동적 할당
    node->vertex = v; // 노드의 정점에 대입
    node->link = g->adj_list[u]; // 노드가 다음으로 가르키는 곳은, 정점의 배열 포인터가 가르키는 곳?
    g->adj_list[u] = node; // 정점의 포인터 배열이 이 노드를 가르키도록 함. 즉, 항상 맨앞에 삽입함
}

void dfs_list(GraphType *g, int v) // v : 시작정점
{   
    GraphNode *w;
    visited[v] = TRUE;
    printf("정점 %d -> ", v);

    for(w = g->adj_list[v] ; w != NULL ; w = w->link)
    {   
        if(visited[w->vertex == FALSE])
            dfs_list(g, w->vertex);
    }
}

void print_adj_list(GraphType *g)
{
    for(int i=0 ; i < g->n ; i++)
    {
        GraphNode *p = g->adj_list[i];
        printf("정점 %d의 인접 리스트", i);
        while(p != NULL)
        {
            printf("-> %d ", p->vertex);
            p=p->link;
        }
        printf("\n");
    }
}

int main()
{
    GraphType *g;
    g = (GraphType*)malloc(sizeof(GraphType));
    init(g);
    
    for(int i=0 ; i<7 ; i++)
        insert_vertex(g, i);

    insert_edge(g, 0, 2);
    insert_edge(g, 0, 1);

    insert_edge(g, 1, 4);
    insert_edge(g, 1, 3);

    insert_edge(g, 2, 6);
    insert_edge(g, 2, 5);

    printf("깊이우선탐색\n");
    dfs_list(g, 0);

    free(g);

    printf("\n\n\n");
    return 0;
}
