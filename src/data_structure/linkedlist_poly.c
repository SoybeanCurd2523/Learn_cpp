// 연결리스트의 응용 : 다항식
#include <stdio.h>
#include <stdlib.h>

typedef struct ListNode{
    int coef;
    int expon;
    struct ListNode *next;
}ListNode;

typedef struct ListType{
    ListNode *head; // 첫번째 노드를 가르키는 포인터
    ListNode *tail; // 마지막 노드를 가르키는 포인터
    int size; // 전체 연결리스트의 지금 현시점의 매달려있는 노드의 개수
}ListType;

void init(ListType *L){
    L->head = NULL;
    L->tail = NULL;
    L->size = 0;
}

// coef는 계수, expon은 지수
void insert_last(ListType *L, int coef, int expon){
    ListNode *node = (ListNode*)malloc(sizeof(ListNode));

    node->coef = coef;
    node->expon = expon;
    node->next = NULL; // insert_last이기 때문

    if(L->tail == NULL) // 리스트 안에 아무 노드도 없다면
        L->head = L->tail = node;
    else{
        L->tail->next = node;
        L->tail = node;
    }

    L->size++;
}

void poly_add(ListType *L1, ListType *L2, ListType *L3){
    ListNode *p = L1->head;
    ListNode *q = L2->head;
    ListNode *r = L3->head;
    
    int sum; // 계수의 합

    while(p != NULL && q != NULL){ // p와 q가 모두 null이 아닐 때까지
        if(p->expon == q->expon){
            sum = p->coef + q->coef;

            if(sum != 0) // 계수의 합이 0이 아니어야 다항식이 생겨나니까
                insert_last(L3, sum, p->expon);
            p=p->next;
            q=q->next;
        }
        else if(p->expon < q->expon){
            insert_last(L3, q->coef, q->expon);
            q=q->next;
        }
        else if(p->expon > q->expon){
            insert_last(L3, p->coef, p->expon);
            p=p->next;
        }
    }

    // p와 q중의 하나가 먼저 끝나게 되면, 남아있는 항들을 모두 결과 다항식으로 복사

    // p와 q가 여기서 head부터 시작하는게 아니라, while문에서 next로 많이 간 데에서 시작
    for(; p!= NULL ; p=p->next)
        insert_last(L3, p->coef, p->expon);
    
    for(; q!= NULL ; q=q->next) // q는 위의 while문에서 null로 끝났기에 이 for문 진입x
        insert_last(L3, q->coef, q->expon);

}

void print(ListType *L){
    ListNode *p;
    
    printf("poly : ");
    for(p=L->head ; p!= NULL ; p=p->next)
        printf("%dx^%d + ", p->coef, p->expon);
    printf("\b\b\b \n");
}   


int main(){
    ListType L1;
    ListType L2;
    ListType L3;

    init(&L1);
    init(&L2);
    init(&L3);

    insert_last(&L1, 3, 12);
    insert_last(&L1, 2, 8);
    insert_last(&L1, 1, 0);

    insert_last(&L2, 8, 12);
    insert_last(&L2, -3, 10);
    insert_last(&L2, 10, 6);

    print(&L1);
    print(&L2);
    
    poly_add(&L1, &L2, &L3);
    print(&L3);

    return 0;
}

// poly : 3x^12 + 2x^8 + 1x^0 + 
// poly : 8x^12 + -3x^10 + 10x^6 + 
// poly : 11x^12 + -3x^10 + 2x^8 + 10x^6 + 1x^0 + 