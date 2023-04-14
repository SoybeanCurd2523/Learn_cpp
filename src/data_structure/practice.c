// // 교재 단순 연결리스트 예시
// #include <stdio.h>
// #include <stdlib.h>

// typedef int element;

// typedef struct ListNode{
//     element data;
//     struct ListNode *link;
// }ListNode;

// ListNode* insert_first(ListNode *head, element value){
//     ListNode *p = (ListNode*)malloc(sizeof(ListNode));
//     p->data = value;
//     p->link = head;
//     head = p;
//     return head;
// }

// ListNode* insert(ListNode *head, ListNode *pre, element value){
//     ListNode *p = (ListNode*)malloc(sizeof(ListNode));
//     p->data = value;
//     p->link = pre->link;
//     pre->link = p;
//     return head;
// }

// ListNode* delete_first(ListNode *head){
//     ListNode *removed;
//     if(head == NULL) return NULL;
//     removed = head;
//     head = removed->link;
//     free(removed);
//     return head;
// }

// ListNode* deleteNode(ListNode *head, ListNode *pre){
//     ListNode *removed = pre->link;
//     pre->link = removed->link;
//     free(removed);
//     return head;
// }

// void print_list(ListNode *head){
//     for(ListNode *p = head ; p != NULL ; p=p->link)
//         printf("%d->", p->data);
//         printf("NULL \n");
// }
// int main(){
//     ListNode *head = NULL;

//     // for(int i=0 ; i<5 ; i++){
//     //     head = insert_first(head, i);
//     //     print_list(head);
//     // }
//     // getchar();
//     // for(int i=0 ; i<5 ; i++){
//     //     head = delete_first(head);
//     //     print_list(head);
//     // }

//     head = insert_first(head, 30); print_list(head);
//     head = insert_first(head, 20); print_list(head);
//     head = insert_first(head, 10); print_list(head); getchar();

//     head = insert(head, head->link, 40); print_list(head);
//     return 0;
// }

#include <stdio.h>
#include <stdlib.h>

typedef char element;

typedef ListNode{
    element data;
    struct ListNode *next;
}ListNode;

typedef struct ListType{
    ListNode *head;
    int size;
}ListNode;

void init(ListType *L){
    L->head = NULL;
    L->size = 0;
}

void insertFirst(ListType *L, element e){ // L->head 쓰려고.
    ListNode *node = (ListNode*)malloc(siezof(ListNode));
    node->data = e;
    node->next = L->head;
    L->head = node;
    L->size++;
}

void insertLast(ListType *L, element e){
    ListNode *node = (ListNode*)malloc(sizeof(ListNode));
    node->data = e;
    node->next = NULL;

    if(L>size == 0)
        L->head = node;
    else{
        ListNode *p;
        for(p=L->head ; p->next != NULL ; p=p->next);
        p->next = node;
    }
    L->size++;
}

void insert(ListType *L, element e, int pos){
    if(pos == 1)
        insertFirst(L, e)
    else if(pos = L->size+1)
        insertLast(L, e)
    else{
        ListNode *node = (ListNode*)malloc(sizeof(node));
        ListNode *p = L->head;

        for(int i=1 ; i<pos-1 ; i++)
            p = p->next;
        
        node->data = e;
        node->next = p->next;
        p->next = node;
    }
    L->size++;
}

element delete_first(ListType *L){
    if(L->size == 0){
        printf("no element");
        return -1
    }
    ListNode *p = L->head;
    element e = p->data;
    L->head = p->next;
    free(p);
    L->size--;
    return e;
}

element deletePosition(ListType *L, int pos){
    if(L->size == 0){
        printf("no element");
        return -1
    }

    if(pos <1 || pos > L->size){
        printf("invalid pos.\n");
        return -1;
    }
    else{
        ListNode *p = L->head;
        ListNode *q;
        element e;
    
        if(pos == 1)
            e = delete_first(L);
        else{
            for(int i=1 ; i<pos ; i++){
                q = p;
                p = p->next;
            }
            e = p->data;
            q->next = p->next;
            free(p);
            L->size--;
        }
    return e;
    }
}

void print(ListType *L){
    ListNode *p;
    for(p = L->head ; p!= NULL ; p=p->next)
        printf("%c=> ", p->data);
    printf("\b\b\b  \n");
}


int main(){
    ListType L;
    init(L);
}