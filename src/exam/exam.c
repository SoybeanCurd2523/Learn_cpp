#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_LIST_SIZE 10

typedef int element;

typedef struct ListNode
{
    element data;
    struct ListNode *next;
}ListNode;

typedef struct ListType{
    ListNode *H; // 헤드 포인터
}ListType;

void init(ListType *L){
    L->H = NULL;
}

void insert_first(ListType *L, element e){
    ListNode* node = (ListNode*)malloc(sizeof(ListNode));

    node->data = e;
    node->next = L->H;
    L->H = node;
}

void insert_position(ListType *L, int pos, element e){
    if(pos==1) 
        insert_first(L, e);
    else{
        ListNode* node = (ListNode*)malloc(sizeof(ListNode));
        ListNode *p = L->H;

        for(int i=1 ; i<pos ; i++)
            p=p->next;
        
        node->data = e;
        node->next = p->next;
        p->next  = node;
    }
}   

void insert(ListType *L, element e){
    int cnt = 0;
    ListNode* node = (ListNode*)malloc(sizeof(ListNode));
    ListNode *p;

    if(cnt > MAX_LIST_SIZE) return;
    
    for(p=L->H ; p!=NULL ; p=p->next){
        if(e >= p->data){
            node->data = e;
            node->next = p->next;
            p->next  = node;
            cnt++;
        }
        else{
            insert_position(L, cnt, e);
        }
    }
    
}   


void makeSet(ListType *L, element e){
    insert(L, e); // 앞으로 삽입
}

void print_list(ListType *L){
    ListNode *p;
    printf("{");
    for(p = L->H ; p != NULL    ; p=p->next)
        printf("%d, ", p->data);
    printf("\b\b }\n");
}
int main(){
    ListType L1, L2;
    init(&L1);
    init(&L2);

    srand(time(NULL));

    for(int i=0 ; i<10 ; i++){
        makeSet(&L1, rand() % 30 +1);
        makeSet(&L2, rand() % 30 +1);
    }

    // print_list(&L1);
    insert_first(&L1, 10);
    insert_first(&L1, 20);
    print_list(&L1);

    insert(&L1, 15);
    // insert(&L1, 13);

    print_list(&L1);
    return 0;
}