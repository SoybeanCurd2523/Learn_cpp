#include <stdio.h>
#include <stdlib.h>

#define N 10
#define TRUE 1
#define FALSE 0

/*
이 코드는 그래프 데이터 구조를 구현하고 있습니다. 이 그래프는 연결 리스트를 사용하여 구현되었으며, 각 노드는 정점(Vertex)과 간선(Edge)을 나타냅니다.

구조체 정의:

Edge는 두 정점과 가중치를 저장합니다. 간선 구조체는 다른 간선에 대한 포인터를 가지고 있어, 간선의 연결 리스트를 형성합니다.
IncidentEdge는 발생하는 간선을 나타내며, 이름, 가중치 그리고 해당 간선의 다음 IncidentEdge에 대한 포인터를 가집니다.
Vertex는 정점의 이름, 방문 여부, 해당 정점에서 발생하는 간선에 대한 포인터(iHead), 그리고 다음 정점에 대한 포인터를 가지고 있습니다.
GraphType은 정점과 간선의 헤드 포인터, 그리고 정점과 간선의 수를 저장합니다.
함수 정의:

init 함수는 그래프를 초기화합니다. 모든 포인터를 NULL로 설정하고, 정점과 간선의 수를 0으로 설정합니다.
makeVertex 함수는 새로운 정점을 만들고, 이를 그래프의 정점 연결 리스트에 추가합니다.
makeIncidentEdge 함수는 주어진 정점에 대한 새로운 IncidentEdge를 만들고, 이를 해당 정점의 IncidentEdge 리스트에 추가합니다.
findVertex 함수는 그래프에서 주어진 이름의 정점을 찾아 반환합니다.
insertEdge 함수는 두 정점 사이에 새로운 간선을 추가합니다. 이 간선은 그래프의 간선 리스트에 추가되며, 두 정점의 IncidentEdge 리스트에도 추가됩니다.
print 함수는 그래프의 모든 정점과 해당 정점에서 발생하는 모든 간선을 출력합니다.
메인 함수:

init 함수를 호출하여 그래프를 초기화하고, makeVertex 함수를 호출하여 정점을 만듭니다.
insertEdge 함수를 호출하여 정점 사이에 간선을 추가합니다.
print 함수를 호출하여 그래프의 내용을 출력합니다.
*/
typedef char element;

typedef struct Edge
{
    char v1, v2;
    int weight;
    struct Edge *next;
}Edge;

typedef struct IncidentEdge
{
    char aName; 
    Edge *e;
    struct IncidentEdge *next;
}IncidentEdge;

typedef struct Vertex
{
    char vName;
    int isVisit;
    IncidentEdge *iHead;
    struct Vertex* next;
}Vertex;

typedef struct
{
    Vertex *vHead;
    Edge *eHead;
    int eCount, vCount;
}GraphType;

void init(GraphType *G)
{
    G->vHead = NULL;
    G->eHead = NULL;
    G->vCount = G->eCount = 0;
}

void makeVertex(GraphType *G, char vName)
{
    Vertex *v = (Vertex*)malloc(sizeof(Vertex));
    v->vName = vName;
    v->isVisit = FALSE;
    v->iHead = NULL;
    v->next = NULL;
    
    G->vCount++;

    Vertex *p = G->vHead;
    
    if(p == NULL)
        G->vHead = v;
    else
    if(u >= G->n || v >= G->n) // 없는 정점을 연결하라는 거니까. n=4이면 정점은 0번 ~ 3번 정점만 있다.
        printf("error.\n");
    else    
        G->adjMat[u][v] = G->adjMat[v][u] = 1; // 무방향 그래프니까 대칭행렬이다
    {
        while(p->next != NULL)
            p = p->next;
            
        p->next = v;    
    }
}

void makeIncidentEdge(Vertex *v, char aName, Edge *e)
{
    IncidentEdge *p = (IncidentEdge*)malloc(sizeof(IncidentEdge));
    p->aName = aName;
    p->e = e;
    p->next = NULL;

    IncidentEdge* q = v->iHead;
    if(q == NULL)
        v->iHead = p;
    else
    {
        while(q->next != NULL)
            q = q->next;
            
        q->next = p;    
    }
}

Vertex* findVertex(GraphType *G, char vName)
{
    Vertex *v = G->vHead;
    
    while(v->vName != vName)
        v = v->next;
        
    return v;    
}

void insertEdge(GraphType *G, char v1, char v2, int w)
{
    Edge *e = (Edge*)malloc(sizeof(Edge));
    e->weight = w;
    e->v1 = v1;
    e->v2 = v2;
    e->next = NULL;

    G->eCount++;
    
    Edge *q = G->eHead;
    if(q == NULL)
        G->eHead = e;
    else
    {
        while(q->next != NULL)
            q = q->next;
        q->next = e;
    }
    Vertex *v = findVertex(G, v1);
    makeIncidentEdge(v, v2, e);
    
    v = findVertex(G, v2);
    makeIncidentEdge(v, v1, e);
}

void print(GraphType *G)
{
    Vertex *p = G->vHead;
    IncidentEdge *q;
    
    for(; p != NULL; p = p->next)
    {
        printf("[%c] : ", p->vName);
        for(q = p->iHead; q != NULL; q = q->next)
            printf("[%c, %d] ", q->aName, q->e->weight);
        printf("\n");    
    }
}

int main()
{
    GraphType G;
    init(&G);
    
    makeVertex(&G, 'a'); makeVertex(&G, 'b'); makeVertex(&G, 'c');
    makeVertex(&G, 'd'); makeVertex(&G, 'e'); makeVertex(&G, 'f');
    makeVertex(&G, 'g');
        
    insertEdge(&G, 'a', 'b', 29); insertEdge(&G, 'a', 'f', 10); 
    insertEdge(&G, 'b', 'c', 16); insertEdge(&G, 'b', 'g', 15); 
    insertEdge(&G, 'c', 'd', 12); 
    insertEdge(&G, 'd', 'e', 22); insertEdge(&G, 'd', 'g', 18); 
    insertEdge(&G, 'e', 'f', 27); insertEdge(&G, 'e', 'g', 25); 
    
    print(&G); printf("\n");

    return 0;
}