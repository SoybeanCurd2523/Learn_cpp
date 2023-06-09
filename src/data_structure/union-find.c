#include <stdio.h>

int getParent(int parent[], int x) // 부모를 찾는 함수. 재귀적임
{
    if(parent[x] == x) return x; // 자기 부모가 자기면 자기를 반환

    // printf("xxxx");

    return parent[x] = getParent(parent, parent[x]); // 자기 부모가 자기가 아니면, 자기 부모를 인수로 대입
}

int unionParent(int parent[], int a, int b)
{
    a = getParent(parent, a);
    b = getParent(parent, b);

    // printf("a : %d", a);
    // printf("b : %d", b);

    if(a<b) parent[b] = a; // 부모가 다르다면, 더 작은 쪽으로 합침
    else parent[a] = b;
}

int findParent(int parent[], int a, int b)
{
    a = getParent(parent, a);
    b = getParent(parent, b);
    if(a==b) return 1; // 두 노드의 부모가 같으면 1을 반환, 다르면 0을 반환
    else return 0;
}


// parent[x] = y  :  y를 x의 부모에 대입한다.
int main()
{
    int parent[11];
    for(int i=1 ; i<=10 ; i++) // 1부터 10까지 열 개의 노드를 만듬
        parent[i] = i; // 이 노드들의 부모는 자기 자신이다.

    // printf("parent[%d] = %d\n", 1, getParent(parent, 1));
    // printf("parent[%d] = %d\n", 2, getParent(parent, 2));

    unionParent(parent, 1, 2);

    // printf("parent[%d] = %d\n", 1, getParent(parent, 1));
    // printf("parent[%d] = %d\n", 2, getParent(parent, 2));

    unionParent(parent, 2, 3);

    // printf("parent[%d] = %d\n", 2, getParent(parent, 2));
    // printf("parent[%d] = %d\n", 3, getParent(parent, 3));
    unionParent(parent, 3, 4);
    unionParent(parent, 5, 6);
    unionParent(parent, 6, 7);
    unionParent(parent, 7, 8);

    printf("parent[%d] = %d\n", 1, getParent(parent, 1));
    printf("parent[%d] = %d\n", 5, getParent(parent, 5));
    printf("parent[%d] = %d\n", 6, getParent(parent, 6));

    printf("1과 5는 연결되어 있나요? %d\n", findParent(parent, 1, 5));
    unionParent(parent, 1, 5);

    printf("parent[%d] = %d\n", 1, getParent(parent, 1));
    printf("parent[%d] = %d\n", 5, getParent(parent, 5));
    // printf("parent[%d] = %d\n", 6, getParent(parent, 6));
    printf("parent[6] = %d\n", parent[6]);
    
    printf("1과 5는 연결되어 있나요? %d\n", findParent(parent, 1, 5));

    printf("\n\n\n");
    return 0;
}