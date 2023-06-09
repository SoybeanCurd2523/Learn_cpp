#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0
#define MAX_VERTICES 100
#define INF 1000L // 무한대. 1000L은 1000이라는 값을 가진 long 타입의 정수 리터럴

typedef struct GraphType{
    int n; // 정점의 개수
    int weight[MAX_VERTICES][MAX_VERTICES];
}GraphType;

// 이 배열은 해당 노드가 이미 최소 신장 트리에 포함되었는지 여부를 나타냅니다. 
// 노드가 트리에 포함되면 해당 노드의 selected 배열의 값이 TRUE로 설정되고, 아직 포함되지 않았다면 FALSE로 남아있습니다.
int selected[MAX_VERTICES];



/*
distance 배열은 "현재까지 만들어진 신장 트리"에서 "아직 트리에 포함되지 않은 노드"로 가는 간선들 중에서 가장 가까운 거리를 저장하는 것입니다. distance[4] = 27이라는 것은, 현재까지 만들어진 신장 트리에서 4번 노드로 가는 가장 가까운 간선의 가중치가 27이라는 의미입니다. 이것은 반드시 0번 노드에서 4번 노드로 직접 가는 경로를 의미하지는 않습니다.

시작 노드는 0번 노드지만, 신장 트리가 확장될수록 0번 노드가 아닌 다른 노드에서 4번 노드로 가는 간선 중 가장 가중치가 작은 것을 고려하게 됩니다.

예를 들어, 0-5-4라는 경로가 있을 때, 가장 처음에는 0에서 4로 가는 간선이 없으므로 distance[4]는 무한대로 설정됩니다. 그런데 5번 노드가 트리에 추가되면, 5에서 4로 가는 간선을 고려하게 되고, 이 간선의 가중치가 27이라면 distance[4]는 27로 업데이트되게 됩니다.

즉, distance[i]는 "현재까지 만들어진 신장 트리에서 i번 노드로 가는 가장 가까운 거리"를 의미하며, 이때의 "가까운 거리"는 하나의 간선에 대한 가중치입니다. 이 점이 Prim 알고리즘의 핵심 부분입니다. 신장 트리가 확장될수록, 즉 더 많은 노드들이 트리에 포함될수록, distance 배열은 계속해서 업데이트됩니다.*/
int distance[MAX_VERTICES]; 


/*
get_min_vertex 함수는 현재 구성된 트리에서 아직 선택되지 않은(즉, 아직 트리에 포함되지 않은) 정점들 중에서 distance 값이 가장 작은 정점의 인덱스를 반환합니다. 
이 distance 값은 시작 정점이 아닌, 현재까지 구성된 트리에서 해당 정점까지의 가중치를 의미합니다. */
int get_min_vertex(int n) // 인자 : 총 정점의 개수
{   // 그래프에 포함되지 않은 정점 중에서 가중치가 가장 작은 정점을 반환한다?
    int v, i;
    for(i=0 ; i<n ; i++)
        if(!selected[i]) // 만약 그 정점이 아직 선택되지 않았다면
        {
            v = i; // 정점을 v에 저장 하고 반복문 탈출
            // printf("v : %d", v);
            break;
        }

    for(i=0 ; i<n ; i++)
        if(!selected[i] && distance[i] < distance[v]) 
        {
            v = i;
            // printf("vv : %d", v);
        }

    printf("v : %d", v);
    return (v);
}

/*

prim 함수는 Prim의 최소 신장 트리 알고리즘을 구현한 함수입니다. 이 알고리즘은 주어진 그래프에서 가중치의 합이 최소가 되는 신장 트리를 찾는 방법입니다.

다음은 prim 함수의 주요 작동 원리입니다:

함수는 먼저 모든 노드에 대한 거리(distance)를 무한대(INF)로 설정합니다. 시작 노드(s)의 거리는 0으로 설정합니다. 이는 시작 노드에서 그 자체로의 거리가 0이기 때문입니다.

그래프의 모든 노드에 대해 다음을 수행합니다:

먼저 get_min_vertex 함수를 사용하여 아직 선택되지 않은 노드 중에서 시작 노드로부터의 거리가 가장 짧은 노드 u를 찾습니다.

만약 u의 거리가 무한대라면, 그래프의 모든 노드가 이미 선택된 것이므로 함수를 종료합니다.

그렇지 않다면, 노드 u를 신장 트리에 추가하고 (selected[u] = TRUE), 이를 출력합니다.

노드 u에 인접한 모든 노드 v에 대해, v가 아직 선택되지 않았고 u를 통해 v로 가는 거리가 현재 알려진 v로의 거리보다 짧다면, v로의 거리를 업데이트합니다.
*/
void prim(GraphType* g, int s)
{
    int i,u,v;

    for(u=0 ; u<g->n ; u++)
        distance[u] = INF; // 다른 노드까지의 거리를 무한대로 초기 설정
    distance[s]= 0; // 자기 자신과의 거리는 0이다

    for(i=0 ; i<g->n ; i++) // 정점의 총 개수만큼 반복 
    {
        u = get_min_vertex(g->n);
        selected[u] = TRUE; // 선택했다고 표시
        if(distance[u] == INF)
            return;

        printf("정점 %d 추가\n", u);

        for(v=0 ; v<g->n ; v++) // 정점의 총 개수만큼 반복
            if(g->weight[u][v] != INF)
                if(!selected[v] && g->weight[u][v] < distance[v])
                    distance[v] = g->weight[u][v];

        for(int i=0 ; i<g->n ; i++)
            printf("distance[%d] = %d\n", i, distance[i]);
    }
}

int main()
{
    // GraphType g = {7, 
    // {{ 0, 29, INF, INF, INF, 10, INF },
    // {  29, 0, 16, INF, INF, INF, 15 },
    // { INF, 16, 0, 12, INF, INF, INF },
    // { INF, INF, 12, 0, 22, INF, 18 },
    // { INF, INF, INF, 22, 0, 27, 25 },
    // { 10, INF, INF, INF, 27, 0, INF },
    // { INF, 15, INF, 18, 25, INF, 0} }
    // };

    GraphType g = {8,
    {{ 0, 10, INF, 6, INF, INF, INF, 1 },
    { 10, 0, 4, INF, INF, 2, INF, INF },
    { INF, 4, 0, 11, INF, 7, INF, INF },
    { 6, INF, 11, 0, INF, INF, INF, 3 },
    { INF, INF, INF, INF, 0, 5, INF, 8 },
    { INF, 2, 7, INF, 5, 0, 9, INF },
    { INF, INF, INF, INF, INF, 9, 0, 12 },
    { 1, INF, INF, 3, 8, INF, 12, 0} }
    };

    prim(&g, 0);

    printf("\n\n\n");
    return 0;
}