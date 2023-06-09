#include <stdio.h>
#include <stdlib.h> // qsort() 함수를 사용하기 위해 필요

#define TRUE 1
#define FALSE 0

#define MAX_VERTICES 100 // 최대 정점의 개수
#define INF 1000 // 무한대

int parent[MAX_VERTICES]; // 부모 노드

void set_init(int n) // 인자 : 정점의 개수
{
    for(int i=0 ; i<n ; i++)
        parent[i] = -1; // 모든 정점의 부모를 -1로 초기화
}

int set_find(int curr) // curr가 속하는 집합을 찾는다.
{
    if(parent[curr] == -1) // 만약 루트가 부모라면
        return curr; // 자기 자신을 반환
    
    while(parent[curr] != -1)  // 루트가 부모가 아니라면
        curr = parent[curr]; // curr을 curr의 부모의 번호로 업데이트. 자기 추종하는 것들은 parent 배열을 직접 바꾸지는 않고, setfind 함수에서 탐색만 하는듯?
    
    return curr;
}

void set_union(int a, int b) // 두 개의 원소가 속한 집합을 합친다.
{
    int root1 = set_find(a);
    int root2 = set_find(b);

    printf("root1 : %d\n", root1);
    printf("root2 : %d\n", root2);
    if(root1 != root2)
        parent[root1] = root2; // root1의 부모에 root2를 대입 // 여기가 parent[] 배열의 값을 진짜 바꾸는 곳이다
}

struct Edge{
    int start, end, weight; // 간선의 시작 정점, 끝 정점, 가중치
};

typedef struct GraphType
{
    int n; // 간선의 개수
    int nvertex; // 정점의 개수
    struct Edge edges[2*MAX_VERTICES]; // GraphType 구조체 안에 Edge 구조체의 배열이 있음을 나타냅니다. 
}GraphType;

void init_graph(GraphType *g)
{
    g->n = g->nvertex = 0; // 간선의 개수와 정점의 개수를 0으로 초기화

    for(int i=0 ; i < 2*MAX_VERTICES ; i++)
    {
        g->edges[i].start = 0; 
        g->edges[i].end = 0;
        g->edges[i].weight = INF; // 모든 간선의 시작 정점을 0으로, 끝 정점을 0으로, 가중치를 무한대로 초기화
    }
}

void insert_edge(GraphType *g, int start, int end, int w) // 시작 정점, 끝 정점, 가중치
{
    g->edges[g->n].start = start; // g->n은 처음에 0번. 그러니까 0번 간선부터 
    g->edges[g->n].end = end;
    g->edges[g->n].weight = w;
    g->n++; // 간선의 개수 증가
}

int compare(const void* a, const void* b)
{
    struct Edge* x = (struct Edge*)a;
    struct Edge* y = (struct Edge*)b;
    return (x->weight - y->weight);
}

void kruskal(GraphType *g)
{
    int edge_accepted = 0; // 현재까지 선택된 간선의 수
    int uset, vset; // 정점 u와 정점 v의 집합 번호
    struct Edge e;

    set_init(g->nvertex); // 집합 초기화
    qsort(g->edges, g->n, sizeof(struct Edge), compare); // 간선들의 배열인 edges를 가중치의 오름차순으로 정렬함

    printf("크루스칼 최소 신장 트리 알고리즘 \n");

    int i=0;
    while(edge_accepted < (g->nvertex - 1)) // 선택된 간선의 수 < 정점의 개수 -1   . 스패닝 트리
    {
        e = g->edges[i]; // 가중 가중치가 낮은 간선(edge 배열의 0번 인덱스) 부터
        for(int i=0 ; i< g->nvertex; i++)
            printf("parent[%d] = %d\n", i, parent[i]); 
            
        printf("e.start :%d\n", e.start);
        printf("e.end :%d\n", e.end);
        printf("e.weight:%d\n", e.weight);
        uset = set_find(e.start); // 간선의 시작 정점 대입, 집합의 번호
        vset = set_find(e.end); // 간선의 끝 정점, 집합의 번호

        printf("uset : %d\n", uset);
        printf("vset : %d\n", vset);

        if(uset != vset) // 서로 속한 집합이 다르면
        {
            printf("간선 (%d, %d) %d 선택 \n", e.start, e.end, e.weight);
            edge_accepted++; // 선택된 간선의 수 증가
            set_union(uset, vset); // 두개의 집합을 합친다.
        }
        i++; // 간선 배열의 인덱스 증가
    }
}


int main() {
    GraphType *g;
    g = (GraphType*)malloc(sizeof(GraphType));
    init_graph(g);

    g->nvertex = 8; // 정점의 개수를 7개로 설정

    // insert_edge(g, 0, 1, 29); // 시작정점 : 0, 끝 정점 : 1, 가중치 : 29
    // insert_edge(g, 1, 2, 16);
    // insert_edge(g, 2, 3, 12);
    // insert_edge(g, 3, 4, 22);
    // insert_edge(g, 4, 5, 27);
    // insert_edge(g, 5, 0, 10);
    // insert_edge(g, 6, 1, 15);
    // insert_edge(g, 6, 3, 18);
    // insert_edge(g, 6, 4, 25);



    insert_edge(g, 0, 7, 1);
    insert_edge(g, 1, 5, 2);
    insert_edge(g, 3, 7, 3);
    insert_edge(g, 1, 2, 4);
    insert_edge(g, 4, 5, 5);
    insert_edge(g, 0, 3, 6);
    insert_edge(g, 2, 5, 7);
    insert_edge(g, 4, 7, 8);
    insert_edge(g, 5, 6, 9);
    insert_edge(g, 0, 1, 10);
    insert_edge(g, 2, 3, 11);
    insert_edge(g, 6, 7, 12);

    for(int i=0 ; i< g->nvertex; i++)
        printf("parent[%d] = %d\n", i, parent[i]); 

    kruskal(g);

    for(int i=0 ; i< g->nvertex; i++)
        printf("parent[%d] = %d\n", i, parent[i]); 

    free(g);

    printf("\n\n\n");
    return 0;
}
