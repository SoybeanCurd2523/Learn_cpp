// 단순 연결 리스트
// 230605 기말준비중 그래프가 나와서 다시 복습
#include <stdio.h>
#include <stdlib.h>

typedef char element;

typedef struct ListNode
{
    element data;
    struct ListNode *next;
}ListNode;

typedef struct ListType
{
    ListNode *head;
    int size;
}ListType;

void init(ListType *L)
{
    L->head = NULL;
    L->size = 0;
}

void insertFirst(ListType *L, element e)
{
    ListNode *node = (ListNode*)malloc(sizeof(ListNode));
    node->data = e;
    node->next = L->head;

    L->head = node;
    L->size++;
}

void insertLast(ListType *L, element e)
{
    ListNode *node = (ListNode*)malloc(sizeof(ListNode));

    node->data = e;
    node->next = NULL;

    if(L->size == 0)
        L->head = node;
    else{
        ListNode *p;
        for(p = L->head ; p->next != NULL ; p=p->next);

        p->next = node;
    }
    L->size++;
}

element deleteFirst(ListType *L)
{
    ListNode *p = L->head;
    element e = p->data;
    L->head = p->next;
    free(p);
    L->size--;

    return e;
}

element deletePosition(ListType *L, int pos)
{
    ListNode *p = L->head;
    ListNode *q;
    element e;

    if(pos==1)
        e = deleteFirst(L);
    else{
        for(int i = 1 ; i<pos ; i++){
            q = p;
            p=p->next;
        }
        e = p->data;
        q->next = p->next;
        free(p);
        L->size--;
    }
    return e;
}

void print(ListType *L){
    ListNode *p;
    for(p = L->head ; p!= NULL ; p=p->next)
        printf("%c => ", p->data);
    
    printf("\b\b\b     \n");
}

int main(){
    ListType L;
    init(&L);

    insertFirst(&L, 'A');
    insertFirst(&L, 'B');
    insertFirst(&L, 'C');

    print(&L); getchar();

    insertLast(&L, 'D');

    print(&L); getchar();

// 그러나 실제로 삭제된 노드의 데이터를 이용할 필요가 없다면, 이를 특정 변수에 대입하지 않고 그냥 호출만 해도 문제 없습니다. 
// 함수의 반환값을 사용하지 않는 것은 문법적으로 아무런 문제가 없습니다.

    deleteFirst(&L);

// 이 경우 삭제된 노드의 데이터는 무시됩니다. 이는 프로그래머의 의도에 따라 달라질 수 있으며, 반환값을 사용하려면 반환값을 어떤 변수에 저장해야 합니다. 
// 그렇지 않으면 반환값은 사라지게 됩니다.
    print(&L); getchar();

    deletePosition(&L, 2);

    print(&L);

    return 0;
}

