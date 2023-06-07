#include <stdio.h>

#define N 10

typedef struct{
    int n; // 정점의 개수    
    int adjMat[N][N];
}GraphType;

void init(GraphType *G)
{
    G->n = 0;
    for(int i=0; i<N ; i++)
        for(int j=0 ; j<N ; j++)
            G->adjMat[i][j] = 0;
}

void makeVertex(GraphType *G)
{
    G->n++;
}

void insertVertex(GraphType *G, int u, int v)
{
    if(u >= G->n || v >= G->n)
        return;

    G->adjMat[u][v] = G->adjMat[v][u] = 1;
}

void printVertex(GraphType *G)
{
    for(int i=0 ; i<G->n ; i++)
    {
        for(int j=0 ; j<G->n ; j++)
            printf(" %d", G->adjMat[i][j]);
        printf("\n");
    }
}

int cal_Degree(GraphType *G, int v)
{
    int degree = 0;
    for(int i=0 ; i<G->n ; i++)
    {   
        if(G->adjMat[v][i] == 1)
        {
            degree++;
        }
    }
    return degree;
}

int main()
{
    GraphType G;
    init(&G);

    int n = 4;
    for(int i=0 ; i< n ; i++)
        makeVertex(&G);

    insertVertex(&G, 0, 1);
    insertVertex(&G, 0, 2);
    insertVertex(&G, 0, 3);

    insertVertex(&G, 2, 1);
    insertVertex(&G, 2, 3);

    printVertex(&G);
    
    printf("정점 %d의 차수 : %d", 0, cal_Degree(&G, 0));

    printf("\n\n\n");
    return 0;
}