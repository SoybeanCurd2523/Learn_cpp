#include <stdio.h>
#include <stdlib.h>

typedef char element;

typedef struct ListNode{
    element data;
    struct ListNode *next;
}ListNode;

typedef struct ListType{
    ListNode *head;
    int size; // 전체 연결리스트의 지금 현시점의 매달려있는 노드의 개수
}ListType;

void init(ListType *L){
    L->head = NULL;
    L->size = 0;
}

void insertFirst(ListType *L, element e){
    ListNode *node = (ListNode*)malloc(sizeof(ListNode)); // 노드를 동적으로 생성
    node->data = e;
    node->next = L->head;
    L->head = node;
    L->size++;
}

void insertLast(ListType *L, element e){
    ListNode *node = (ListNode*)malloc(sizeof(ListNode)); 
    node->data = e;
    node->next = NULL;

    if(L->size == 0)
        L->head = node;
    else{
        ListNode *p;
        for(p=L->head ; p->next != NULL ; p=p->next);
        
        p->next = node;
    }
    
    L->size++;
}

void insert(ListType *L, int pos, element e){
    if(pos == 1)
        insertFirst(L, e);
    else if(pos == L->size +1)
        insertLast(L, e);
    else{
        ListNode *node = (ListNode*)malloc(sizeof(ListNode));
        ListNode *p = L->head;

        for(int i=1 ; i<pos-1 ; i++)
            p = p->next;
        
        node->data = e;
        node->next = p->next;
        p->next = node;
    }
    L->size++;
}

void print(ListType *L){
    ListNode *p;
    for(p=L->head ; p!= NULL ; p=p->next)
        printf("%c=> ", p->data);

    printf("\b\b\b  \n");
}

void deleteFirst(ListType *L){
    ListNode *node = (ListNode*)malloc(sizeof(ListNode));
    if(L->head == NULL) return;
    node = L->head;
    L->head = node->next;

    free(node);
}

void deleteLast(ListType *L){
    ListNode *node = (ListNode*)malloc(sizeof(ListNode));
    node = L->head;
    if(node->next == NULL){
        free(node);
        L->head = NULL;
    }
    else{
        while(node->next->next != NULL){
            node = node->next;
        }
        free(node->next);
        node->next = NULL;
    }
}

void deletePosition(ListType *L, int pos){
    ListNode *node = (ListNode*)malloc(sizeof(ListNode));
    node = L->head;

    ListNode *p;

    if(pos < 0 || L->size < pos)    
        return;
    else{
        for(int i=2 ; i<pos ; i++)
            node = node->next;
        
        p = node->next;
        node->next = node->next->next;
        free(p);
    }
}

int main(){
    ListType L;
    init(&L);

    insertLast(&L, 'E'); print(&L);

    insertFirst(&L, 'A'); print(&L);
    insertFirst(&L, 'B'); print(&L); getchar();

    insertLast(&L, 'C'); print(&L);
    insertLast(&L, 'D'); print(&L); getchar();

    insert(&L, 1, 'F'); print(&L);
    insert(&L, 4, 'G'); print(&L);
    insert(&L, 8, 'H'); print(&L);

    deleteFirst(&L); print(&L);
    deleteLast(&L); print(&L);
    deletePosition(&L, 3); print(&L);
}