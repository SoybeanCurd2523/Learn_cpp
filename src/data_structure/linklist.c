// 내가 안보고 만들어본 단순 연결 리스트
#include <stdio.h>
#include <stdlib.h>

typedef char element;

typedef struct ListNode{
    element data;
    struct ListNode *next;
}ListNode;

typedef struct ListType{
    int size;
    ListNode *head;
}ListType;

void init(ListType *L){
    L->head = NULL;
    L->size = 0;
}

void insertFirst(ListType *L, element e){
    ListNode *node = (ListNode*)malloc(sizeof(ListNode));
    node->data = e;
    node->next = L->head;
    L->head = node;
    L->size++;
}

void insertLast(ListType *L, element e){
    ListNode *node = (ListNode*)malloc(sizeof(ListNode));

    ListNode *p = L->head;
    for(int i=0 ; i < L->size - 1 ; i++){
        p = p->next;
    }
    p->next = node;
    node->data = e;
    node->next = NULL;
    
    L->size++;
}

void insert(ListType *L, element e, int pos){
    if(pos < 1 || pos > L->size){
        printf("invalid position. \n");
        return;
    }
    if(pos == 1)
        insertFirst(L, e);
    
    else if(pos == L->size)
        insertLast(L, e);
    else{
        ListNode *node = (ListNode*)malloc(sizeof(ListNode));
        ListNode *p = L->head;
        for(int i=1 ; i<pos-1 ; i++){
            p = p->next;
        }
        node->data = e;
        node->next = p->next;
        p->next = node;
        L->size++;
    }
}

void print(ListType *L){
    for(ListNode *p = L->head ; p != NULL ; p=p->next)
        printf("%c => ", p->data);
    
    printf("\b\b\b   \n");
}

element deleteFirst(ListType *L){
    ListNode *p;
    p = L->head;

    element e;
    e = p->data;

    L->head = p->next;

    free(p);
    L->size--;
    return e;
}

element deletePosition(ListType *L, int pos){
    element e;
    if(pos < 1 || pos > L->size){
        printf("invalid position. \n");
        return -1;
    }

    if(pos == 1)
        e = deleteFirst(L);
   
    else{// int isEmpty(QueueType *Q){
//     if(Q->rear == Q->front)
//         return 1;
//     else    
//         return 0;
// }
        ListNode *p = L->head;
        ListNode *q;

        for(int i=1 ; i< pos ; i++){
            q = p;
            p = p->next;
        }
        e = p->data;
        q->next = p->next;
        p->next = NULL;
        free(p);
        L->size--;
        return e;
    }
}


int main(){
    ListType L;
    init(&L);

    insertFirst(&L, 'A'); print(&L);
    insertFirst(&L, 'B'); print(&L);

    getchar();

    insertLast(&L, 'C'); print(&L);
    insertLast(&L, 'D'); print(&L);

    getchar();

    insert(&L, 'F', 2); print(&L);
    insert(&L, 'G', 3); print(&L);
    
    getchar();

    printf("deleted : %c\n", deleteFirst(&L)); print(&L);
    printf("deleted : %c\n", deleteFirst(&L)); print(&L);

    getchar();

    printf("deleted : %c\n", deletePosition(&L, 3)); print(&L);
    printf("deleted : %c\n", deletePosition(&L, 2)); print(&L);

    return 0;
}
