#include <stdio.h>
#include <stdlib.h>

typedef char element;

typedef struct ListNode{
    element data;
    struct ListNode *next;
}ListNode;

typedef struct ListType{
    ListNode *tail;
    int size; // 전체 연결리스트의 지금 현시점의 매달려있는 노드의 개수
}ListType;

void init(ListType *L){
    L->tail = NULL;
    L->size = 0;
}

/* 원형 리스트 : 마지막 노드가 null이 아니라 첫번째 노드를 가르킴
L->tail : last node
L->tail->next : first node
*/

void insertLast(ListType *L, element e){
    ListNode *node = (ListNode*)malloc(sizeof(ListNode)); 
    node->data = e;
    node->next = NULL;

    if(L->size == 0){
        L->tail = node;
        node->next = L->tail; // 자기가 자기를 가르키는 것
    }
        
    else{
        node->next = L->tail->next;
        L->tail->next = node;
        L->tail = node;
    }
    L->size++;
}

void insertFirst(ListType *L, element e){
    ListNode *node = (ListNode*)malloc(sizeof(ListNode)); 
    node->data = e;

    if(L->size == 0){
        L->tail = node;
        node->next = L->tail; // 자기가 자기를 가르키는 것
    }
        
    else{
        node->next = L->tail->next;
        L->tail->next = node;
    }
    L->size++;
}

void insert(ListType *L, int pos, element e){
    if(pos == 1)
        insertFirst(L, e);
    else if(pos == L->size)
        insertLast(L, e);
    else{
        ListNode *node = (ListNode*)malloc(sizeof(ListNode));
        ListNode *p = L->tail;

        for(int i=1 ; i<pos ; i++)
            p = p->next;
        
        node->data = e;
        node->next = p->next;
        p->next = node;
    }
    L->size++;
}

element deleteFirst(ListType *L){ // 리턴값 있어야 함

    ListNode *p = L->tail;
    ListNode *q = L->tail->next;

    element e = q->data;
    p->next = q->next;

    if(p == q)
        L->tail = NULL;
    
    free(q);
    L->size--;

    return e;
}

element deleteLast(ListType *L){ // 리턴값 있어야 함

    ListNode *p = L->tail;
    ListNode *q = L->tail->next;

    element e = p->data;
    
    if(p->next == L->tail)
        L->tail = NULL;
    else{
        while(q->next != p)
            q=q->next;
        
        q->next = p->next;
        L->tail;
    }
    
    free(q);
    L->size--;

    return e;
}


void print(ListType *L){
    ListNode *p = L->tail;

    do{ // 조건이 나중에 처리되는 방법 : do-while문
        printf("%c=> ", p->next->data);
        p = p->next;
    }while(p != L->tail);

    printf("\b\b\b  \n");
}


int main(){
    ListType L;
    init(&L);

    insertLast(&L, 'A'); print(&L);
    insertLast(&L, 'B'); print(&L);
    insertLast(&L, 'C'); print(&L); getchar();

    insertFirst(&L, 'D'); print(&L);
    insertFirst(&L, 'E'); print(&L); getchar();

    insert(&L, 1, 'F'); print(&L);
    insert(&L, 4, 'G'); print(&L);
    insert(&L, 7, 'H'); print(&L); getchar();

    printf("[%c] is deleted. \n", deleteFirst(&L)); print(&L);
    printf("[%c] is deleted. \n", deleteLast(&L)); print(&L);

    return 0;
}



/* 원형 리스트 : 마지막 노드가 null이 아니라 첫번째 노드를 가르킴


L->tail : last node
L->tail->next : first node
*/