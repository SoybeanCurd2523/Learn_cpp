// 단순 연결 리스트
#include <stdio.h>
#include <stdlib.h>

typedef char element;

typedef struct ListNode{
    element data;
    struct ListNode *next;
}ListNode;

typedef struct ListType{
    ListNode *head; // 헤드 포인터
    int size; // 전체 연결리스트의 지금 현시점의 매달려있는 노드의 개수
}ListType;

void init(ListType *L){
    L->head = NULL;
    L->size = 0;
}

void insertFirst(ListType *L, element e){ // head가 필요해서 ListType을 받아와서 뽑음.
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
        // 기존에 NULL이었던 마지막 노드의 next필드를 새로 만드는 node를 지목하게 만듬
        p->next = node;
    }
    
    L->size++;
}

void insert(ListType *L, int pos, element e){
    if(pos == 1) // 첫번째 위치에 넣을거면
        insertFirst(L, e);
    else if(pos == L->size +1) // 마지막 위치. 즉, 현재 사이즈 +1의 위치
        insertLast(L, e);
    else{
        ListNode *node = (ListNode*)malloc(sizeof(ListNode));
        ListNode *p = L->head;

        for(int i=1 ; i<pos-1 ; i++) // pre로 향하는 듯
            p = p->next;
        
        node->data = e;
        node->next = p->next;
        p->next = node;
    }
    L->size++;
}

element deleteFirst(ListType *L){ // 리턴값 있어야 함
    if(L->size == 0){ // 에러 체크
        printf("No element. \n");
        return -1;
    }
    ListNode *p = L->head;
    element e = p->data; // 삭제하기 전에 데이터 기억시킴
    L->head = p->next; // 노드가 하나밖에 없다면, head에 null이 들어감. 즉 init 함수 실행되는꼴
    free(p);
    L->size--;

    return e; // 데이터값 리턴 
}

element deletePosition(ListType *L, int pos){ // 함수 이름 delete로 하면 예약어?라 안되는듯?
    if(L->size == 0){ // 에러 체크
        printf("No element. \n");
        return -1;
    }

    if(pos < 1 || pos > L->size){
        printf("Invalid Pos. \n");
        return -1;
    }
    else{
        ListNode *p = L->head;
        ListNode *q;
        element e;

        if(pos == 1)
            e = deleteFirst(L);
        else{
            for(int i=1 ; i<pos ; i++){ // 그림 ㄱ
                q = p;
                p = p->next;
            }
            e = p->data;
            q->next = p->next; // p를 없앨꺼니까.
            free(p);
            L->size--;
        }
        return e;
    }
}

void print(ListType *L){
    ListNode *p;
    for(p=L->head ; p != NULL ; p=p->next) // 마지막 노드가 없을 때까지
        printf("%c=> ", p->data);

    printf("\b\b\b  \n"); // 마지막에 = > 공백 지우려고
}

// 두 리스트 합치기.
// 먼저 첫 번째 리스트의 끝으로 간 다음, 마지막 노드의 링크가 두번째 리스트의 첫 번째 노드를 가르키도록 변경.
// list1이나 list2가  NULL인경우를 처리해주어야함.
ListType* concat_list(ListType *L1, ListType *L2){  
    ListNode *p1 = L1->head;
    ListNode *p2 = L2->head;

    if(L1->head == NULL || L2->head == NULL) return NULL;

    while(p1->next != NULL)
        p1 = p1->next;    
    
    p1->next = p2;
    return L1;
}

int main(){
    ListType L1;
    init(&L1);

    insertFirst(&L1, 'A'); print(&L1);
    insertFirst(&L1, 'B'); print(&L1);

    ListType L2;
    init(&L2);

    insertFirst(&L2, 'C'); print(&L2);
    insertFirst(&L2, 'D'); print(&L2);

    print(concat_list(&L1, &L2));
    
    // insertLast(&L, 'E'); print(&L); 

    // insertFirst(&L, 'A'); print(&L);
    // insertFirst(&L, 'B'); print(&L); 
    // printf("size : %d\n", L.size);    
    // getchar();

    // insertLast(&L, 'C'); print(&L);
    // insertLast(&L, 'D'); print(&L); getchar();

    // insert(&L, 1, 'F'); print(&L);
    // insert(&L, 4, 'G'); print(&L);
    // insert(&L, 8, 'H'); print(&L);

    // printf("[%c] is deleted. \n", deleteFirst(&L)); print(&L);
    // printf("[%c] is deleted. \n", deletePosition(&L, 3)); print(&L);

    return 0;
}

// 다항식 해보기





