#include <stdio.h>
#include <stdlib.h>
#include <limits.h> // INF_MAX 심볼릭 상수 사용하려고
#include <algorithm> // min 함수 사용하려고

#define TRUE 1
#define FALSE 0
#define MAX_VERTICES 100
#define INF 1000000

typedef struct GraphType{
    int n; // 정점의 개수
    int weight[MAX_VERTICES][MAX_VERTICES]; // 가중치 인접 행렬
}GraphType;

int distance[MAX_VERTICES]; // 시작 정점으로부터의 최단 경로 거리
int found[MAX_VERTICES]; // 방문한 정점 표시

int choose(int distance[], int n, int found[]) // 인자 : distance 배열, 정점 개수, found 배열
{
    int i, min, minpos;
    min = INT_MAX;
    minpos = -1;

    for(i=0 ; i<n ; i++)
        if(distance[i] < min && !found[i]) // 방문하지 않은 정점 중에서 distance 배열의 최솟값을 찾고 그것의 인덱스를 반환
        {
            min = distance[i];
            minpos = i;
        }

    printf("minpos : %d\n", minpos);
    return minpos;
}

void print_status(GraphType *g)
{
    static int step = 1;
    printf("STEP %d: ", step++);
    printf("distance ");
    for(int i=0 ; i<g->n ; i++)
    {
        if(distance[i] == INF)
            printf("*");
        else    
            printf("%2d ", distance[i]); // distance 배열 출력. 무한대는 *별로
    }
    printf("\n");
    printf("found: ");
    for(int i=0 ; i<g->n ; i++)
        printf("%2d ", found[i]); // found 배열 출력

    printf("\n\n");
}

void dijkstra(GraphType *g, int start) // 시작 정점
{
    int i, u, w;
    for(i=0 ; i<g->n ; i++)
    {
        distance[i] = g->weight[start][i];
        found[i] =FALSE;
    }
    found[start] = TRUE;
    distance[start] = 0;

    for(i=0 ; i<g->n-1 ; i++)
    {
        print_status(g);

        u = choose(distance, g->n, found);
        found[u] = TRUE;

        for(w=0 ; w<g->n ; w++)
            if(!found[w])
                distance[w] = std::min(distance[w], distance[u] + g->weight[u][w]);
                // if(distance[u] + g->weight[u][w] < distance[w])
                    // distance[w] = distance[u] + g->weight[u][w];
                
    }
}

int main()
{
    
    // GraphType g = {7, // 정점 개수 7개
    //     {{ 0, 7, INF, INF, 3, 10, INF }, // 가중치 인접 행렬
    //     {  7, 0, 4, 10, 2, 6, INF },
    //     { INF, 4, 0, 2, INF, INF, INF },
    //     { INF, 10, 2, 0, 11, 9, 4 },
    //     { 3, 2, INF, 11, 0, INF, 5 },
    //     { 10, 6, INF, 9, INF, 0, INF },
    //     { INF, INF, INF, 4, 5, INF, 0} }
    // };

    GraphType g = {8, // 정점 개수 7개
        {{ 0, 7, INF, 5, INF, 2, INF, INF }, // 가중치 인접 행렬
        {  7, 0, 6, INF, 2, INF, INF, 1 },
        { INF, 6, 0, 2, INF, INF, 2, 8 },
        { 5, INF, 2, 0, INF, 5, INF, INF },
        { INF, 2, INF, INF, 0, 2, INF, 4 },
        { 2, INF, INF, 5, 2, 0, 4, INF },
        { INF, INF, 2, INF, INF, 4, 0, 4},
        { INF, 1, 8, INF, 4, INF, 4, 0} }
    };

    dijkstra(&g, 0); // 0번 정점부터 시작

    return 0;
}