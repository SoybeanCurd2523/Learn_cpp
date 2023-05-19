// 내가 쓴 이중 연결 리스트
#include <stdio.h>
#include <stdlib.h>

typedef char element;

typedef struct DListNode
{
    element data;
    struct DListNode *prev; // 자기잠초'구조체'
    struct DListNode *next;
}DListNode;

typedef struct DListType
{
    int size;
    DListNode *H; // 헤더 노드. 포인터 아님.
    DListNode *T; // 테일 노드. 포인터 아님.
}DListType;

DListNode* getNode(){
    DListNode *node = (DListNode*)malloc(sizeof(DListNode));
    node->prev = NULL;
    node->next = NULL;
    return node;
}

void init(DListType *DL){
    DL->H = getNode();
    DL->T = getNode();
    /////////
    DL->H->next = DL->T;
    DL->T->prev = DL->H;
    ///////////
    DL->size = 0;
}

void insertFirst(DListType *DL, element e){
    DListNode *node = getNode();
    DListNode *p = DL->H;

    node->data = e;
    node->prev = p;
    node->next = p->next;

    p->next->prev = node;
    p->next = node;

    DL->size++;
}

void insertLast(DListType *DL, element e){
    DListNode *node = getNode();
    DListNode *p = DL->T;

    node->data = e;
    node->prev = p->prev;
    node->next = p;

    p->prev->next = node;
    p->prev = node;

    DL->size++;
}

void insertPosition(DListType *DL, element e, int pos){
    if(pos < 1 || pos > DL->size)
        printf("invalid pos.\n");
    else if(pos == 1)
        insertFirst(DL, e);
    else if(pos == DL->size)
        insertLast(DL, e);
    else{
        DListNode *node = getNode();
        DListNode *p = DL->H;

        for(int i=1 ; i<pos ; i++)
            p = p->next;
        
        node->data = e;
        node->prev = p;
        node->next = p->next;

        p->next->prev = node;
        p->next = node;

        DL->size++;
    }
}

element deleteFirst(DListType *DL){
    DListNode *q = DL->H;
    DListNode *p = q->next;

    element e = p->data;

    q->next = p->next;
    p->next->prev = q;

    free(p);
    DL->size--;
    return e;
}

element deleteLast(DListType *DL){
    DListNode *q = DL->T;
    DListNode *p = q->prev;

    element e = p->data;

    p->prev->next = q;
    q->prev = p->prev;

    free(p);
    DL->size--;
    return e;
}

element deletePosition(DListType *DL, int pos){
    if(pos < 1 || pos > DL->size){
        printf("invalid pos.\n");
        return -1;
    }
    else if(pos == 1)
        deleteFirst(DL);
    else if(pos == DL->size)
        deleteLast(DL);
    else{
        DListNode *p = DL->H;
        DListNode *q;
        for(int i=0 ; i<pos ; i++){
            q = p;
            p = p->next;
        }
        element e = p->data;
        q->next = p->next;
        p->next->prev = q;
        DL->size--;
        free(p);
        return e;
    }
}

element search(DListType *DL, element _data){
    DListNode *p = DL->H->next;

    while(p != DL->T){
        if(p->data == _data)
            return p->data;
        p=p->next;
    }

    printf("no match.\n");
    return -1;
}

// DListNode* search(DListType *DL, element _data){
//     DListNode *p = DL->H->next;

//     while(p != DL->T){
//         if(p->data == _data)
//             return p;
//         p=p->next;
//     }

//     printf("no match.\n");
//     return p;
// }

void print(DListType *DL){
    DListNode *p;
    // printf("size : %d\n", DL->size);

    for(p = DL->H->next ; p != DL->T ; p = p->next)
        printf("%c => ", p->data);
    
    printf("\b\b\b  \n");
}




int main(){
    DListType DL;
    init(&DL);

    insertFirst(&DL, 'A'); print(&DL);
    insertLast(&DL, 'B'); print(&DL);
    insertLast(&DL, 'C'); print(&DL);
    insertLast(&DL, 'D'); print(&DL);

    getchar();

    insertPosition(&DL, 'E', 2); print(&DL);
    insertPosition(&DL, 'F', 4); print(&DL);
    insertPosition(&DL, 'G', DL.size); print(&DL);

    printf("searched : %c\n", search(&DL, 'A'));

    // DListNode *node = search(&DL, 'e');
    // printf("data : %c, next : %p, prev : %p\n", node->data, node->prev, node->next);
    getchar();

    printf("deleted : %c\n", deleteFirst(&DL)); print(&DL);
    printf("deleted : %c\n", deleteLast(&DL)); print(&DL);

    getchar();

    printf("deleted : %c\n", deletePosition(&DL, 2)); print(&DL);
    printf("deleted : %c\n", deletePosition(&DL, 1)); print(&DL);
    printf("deleted : %c\n", deletePosition(&DL, DL.size)); print(&DL);

    return 0;
}
