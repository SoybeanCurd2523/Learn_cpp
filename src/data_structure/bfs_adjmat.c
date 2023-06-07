// 인접 행렬로 표현된 그래프에 대한 너비우선탐색 프로그램

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

#define N 50

typedef struct{
    int n; // 정점의 개수    
    int adjMat[N][N];
}GraphType;

int visited[N]; // dfs 시 정점 방문 여부를 기록하기 위한 배열. FALSE로 초기화되고, 정점이 방문될 때마다 해당 정점의 visited 배열값은 TRUE로 변경된다.

void init_graph(GraphType *G) // 인접행렬의 모든 원소를 0으로 초기화
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

void bfs_adjmat(GraphType *g, int v)
{
    QueueType q;
    init_queue(&q); // 큐 초기화

    visited[v] = TRUE; // 정점 v 방문 표시
    printf("%d 방문 -> ", v); 
    enqueue(&q, v); // 시작 정점을 큐에 저장
    
    while(!is_empty(&q))
    {
        v = dequeue(&q); // 큐의 정점 추출
        for(int w=0 ; w<g->n ; w++) // 인접 정점 탐색
        {
            if(g->adjMat[v][w] == 1 && visited[w] == FALSE)
            {
                visited[w] = TRUE; // 방문 표시
                printf("%d 방문 -> ", w);
                enqueue(&q, w); // 방문한 정점을 큐에 저장
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

    insert_edge(g, 0, 2);
    insert_edge(g, 0, 4);

    insert_edge(g, 2, 1);
    insert_edge(g, 2, 3);
    insert_edge(g, 2, 5);

    insert_edge(g, 4, 5);

    // insert_edge(g, 0, 1);
    // insert_edge(g, 0, 2);
    // insert_edge(g, 0, 3);

    // insert_edge(g, 1, 2);
    // insert_edge(g, 1, 4);

    // insert_edge(g, 0, 1);



    printf("너비우선탐색\n");

    bfs_adjmat(g, 0);

    printf("\n\n\n");
    free(g);

    return 0;
}