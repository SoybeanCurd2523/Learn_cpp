// 인접 리스트로 표현된 그래프에 대한 너비우선탐색 프로그램

#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0
#define MAX_QUEUE_SIZE 10

typedef int element;

typedef struct{
    int front, rear;
    element queue[MAX_QUEUE_SIZE];
}QueueType;

void init_queue(QueueType *q)
{
    q->front = q->rear = 0; // 원형 큐 초기화
}

element is_empty(QueueType *q)
{
    return q->front == q->rear; // 큐 공백이면 1 반환, 아니면 0 반환
}

element is_full(QueueType *q)
{
    return q->front == (q->rear + 1) % MAX_QUEUE_SIZE;
}

void enqueue(QueueType *q, element e)
{
    q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
    q->queue[q->rear] = e;
}

element dequeue(QueueType *q)
{
    q->front = (q->front + 1) % MAX_QUEUE_SIZE;
    return q->queue[q->front];
}

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

int visited[MAX_VERTICES]; // 정점 방문 여부 기록



void init_graph(GraphType *g)
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

void bfs_adjlist(GraphType *g, int v)
{
    QueueType q;
    init_queue(&q);

    visited[v] = TRUE;
    printf("%d 방문 -> ", v);

    enqueue(&q, v);

    while(!is_empty(&q))
    {
        v = dequeue(&q);
        for(GraphNode *w = g->adj_list[v] ; w!=NULL ; w=w->link)
        {
            if(visited[w->vertex] == FALSE)
            {
                visited[w->vertex] = TRUE;
                printf("%d 방문 -> ", w->vertex);
                enqueue(&q, w->vertex);
            }
        }
    }
}

int main()
{
    GraphType *g;
    g = (GraphType*)malloc(sizeof(GraphType));

    init_graph(g);

    for(int i=0 ; i<6 ; i++)
        insert_vertex(g, i);

    insert_edge(g, 0, 4);
    insert_edge(g, 0, 2);
    
    insert_edge(g, 2, 5);
    insert_edge(g, 2, 3);
    insert_edge(g, 2, 1);

    insert_edge(g, 4, 5);

    printf("너비우선탐색\n");

    bfs_adjlist(g, 0);

    printf("\n\n\n");
    free(g);

    return 0;
}