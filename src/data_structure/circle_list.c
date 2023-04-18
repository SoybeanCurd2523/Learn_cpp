// 내가 쓴 원형 리스트
#include <stdio.h>
#include <stdlib.h>

 typedef char element;

 typedef struct ListNode{
    element data;
    struct ListNode *next;
 }ListNode;

typedef struct ListType{
    ListNode *tail; // 마지막 노드를 가르키는 포인터
    int size;
}ListType;

void init(ListType *L){
    L->size = 0;
    L->tail = NULL;
}

void insertFirst(ListType *L, element e){

    ListNode *node = (ListNode*)malloc(sizeof(ListNode)); // 동적 할당.
    node->data = e;
    if(L->size == 0){
        L->tail = node;
        node->next = L->tail;
    }
    else{
        node->next = L->tail->next;
        L->tail->next = node;
    }
    L->size++;
}

void insertLast(ListType *L, element e){

    ListNode *node = (ListNode*)malloc(sizeof(ListNode)); // 동적 할당.
    node->data = e;
    if(L->size == 0){
        L->tail = node;
        node->next = L->tail;
    }
    else{
        node->next = L->tail->next;
        L->tail->next = node;
        L->tail = node;
    }
    L->size++;
}

void insert(ListType *L, element e, int pos){
    if(pos < 1 || pos > L->size)
        printf("invalid pos.\n");
    else if(pos == 1)
        insertFirst(L, e);
    else if(pos == L->size)
        insertLast(L, e);
    else{
        ListNode *node = (ListNode*)malloc(sizeof(ListNode));
        ListNode *p = L->tail;

        node->data = e;
        for(int i=1 ; i<pos ; i++)
            p=p->next;

        node->next = p->next;
        p->next = node;

        L->size++;
    }
}

element deleteFirst(ListType *L){
    if(L->size == 0){
        L->tail = NULL;
        return -1;
    }
    else{
        ListNode *p = L->tail->next;
        element e = p->data;

        L->tail->next = p->next;
        free(p);
        L->size--;
        return e;
    }
}

element deleteLast(ListType *L){
    if(L->size == 0){
        L->tail = NULL;
        return -1;
    }
    else{
        ListNode *p = L->tail;
        ListNode *q;

        for(int i=0 ; i< L->size ; i++){
            q = p;
            p = p->next; 
        }

        element e = p->data;
        q->next = p->next;
        L->tail = q;
        free(p);

        L->size--;
        return e;
    }
}

element deletePosition(ListType *L, int pos){
    if(L->size == 0){
        L->tail = NULL;
    }
    else if(pos < 1 || pos > L->size){
        printf("invalied pos.\n");
        return 0;
    }
    else if(pos == 1)
        deleteFirst(L);
    else if(pos == L->size)
        deleteLast(L);
    else{
        ListNode *p = L->tail;
        ListNode *q;

        for(int i=0 ; i< pos ; i++){
            q = p;
            p = p->next; 
        }

        element e = p->data;
        q->next = p->next;
        free(p);

        L->size--;
        return e;
    }
}

element search(ListType *L, element _data){
    ListNode *p = L->tail->next;
    
    do
    {
        if(p->data == _data)
            return p->data;
        p=p->next;
    } while (p != L->tail);
    printf("no match.\n");
    return -1;
}

// ListNode* search(ListType *L, element _data){
//     ListNode *p = L->tail->next;
    
//     do
//     {
//         if(p->data == _data)
//             return p;
//         p=p->next;
//     } while (p != L->tail);

//     printf("no match.\n");
//     p->data = '\0';
//     p->next = NULL;
//     return p;
// }

int get_size(ListType *L){
    int cnt = 0;
    ListNode *p = L->tail->next;
    for( ; p != L->tail ; p=p->next)
        cnt++;

    return cnt+1;
}

void print(ListType *L){
    // printf("size : %d\n", L->size);
    ListNode *p = L->tail;
    do{
        p=p->next;
        printf("%c => ", p->data);
    }while(p != L->tail);

    printf("\n");
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

    insert(&L, 'E', 2); print(&L);
    insert(&L, 'G', 3); print(&L);
    insert(&L, 'F', 4); print(&L);

    // printf("searched : %c\n", search(&L, 'E'));

    // ListNode *node = search(&L, 'A');
    // printf("data(int) : %d, next :%p\n", node->data, node->next);

    // printf("L->size :%d, get_size : %d\n", L.size, get_size(&L));
    getchar();

    printf("deleted : %c\n", deleteFirst(&L)); print(&L);
    printf("deleted : %c\n", deleteFirst(&L)); print(&L);

    getchar();

    printf("deleted : %c\n", deleteLast(&L)); print(&L);
    printf("deleted : %c\n", deleteLast(&L)); print(&L);

    getchar();

    printf("deleted : %c\n", deletePosition(&L, 3)); print(&L);
    printf("deleted : %c\n", deletePosition(&L, L.size)); print(&L);

    return 0;
}
 