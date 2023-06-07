#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 50

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
    
    for(int i=0 ; i<4 ; i++)
        insert_vertex(g, i);

    insert_edge(g, 0, 1);
    insert_edge(g, 1, 0);
    insert_edge(g, 0, 2);
    insert_edge(g, 2, 0);
    insert_edge(g, 0, 3);
    insert_edge(g, 3, 0);
    insert_edge(g, 1, 2);
    insert_edge(g, 2, 1);
    insert_edge(g, 2, 3);
    insert_edge(g, 3, 2);

    print_adj_list(g);
    free(g);
    return 0;
}
