#include <stdio.h>
#include <stdlib.h>

typedef char element;

typedef struct DListNode // 이중 연결 리스트
{
    element data;
    struct DListNode *prev;
    struct DListNode *next;
}DListNode;

typedef struct DListType
{
    int size;
    DListNode *H; // 헤드
    DListNode *T; // 테일
}DListType;

DListNode* getNode(){ // 깡통 노드를 만들어서 반환
    DListNode* node = (DListNode*)malloc(sizeof(DListNode));
    node->next = NULL;
    node->prev = NULL;
    // node->data = 0 을 하지 않는 이유 : 하면 헤드 노드에 데이터 값이 들어가므로(0도 데이터임)
    return node;
}

void init(DListType *DL){
    DL->H = getNode();
    DL->T = getNode();
    DL->H->next = DL->T; // * 중요
    DL->T->prev = DL->H; // * 중요

    DL->size = 0;
}

void inserFirst(DListType *DL, element e){
    DListNode *node = getNode();
    DListNode *p = DL->H;

    node->data = e;

    node->prev = p;
    node->next = p->next;

    // 순서 헷갈리지 말자
    p->next->prev = node;
    p->next = node;

    DL->size++;
}

// insert first는 insert last와 완벽한 대칭이다.

void inserLast(DListType *DL, element e){ 
    DListNode *node = getNode();
    DListNode *p = DL->T;

    node->data = e;

    node->prev = p->prev;
    node->next = p;

    // 순서 헷갈리지 말자
    p->prev->next = node;
    p->prev = node;

    DL->size++;
}

void insertPosition(DListType *DL, element e, int pos){
    if(pos < 1 || pos > DL->size+1){
        printf("invalid pos.\n");
        return;
    }
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

element deletePosition(DListType *DL, int pos){
    if(pos < 1 || pos > DL->size){
        printf("invalid pos.\n");
        return -1; // 함수 deletePosition 자체의 반환형이 있다.
    }    
    DListNode *p = DL->H;
    for(int i=0 ; i<pos ; i++)
        p=p->next;
    
    element e = p->data;
    p->prev->next = p->next;
    p->next->prev = p->prev;

    free(p);
    DL->size--;
    return e;
}


void print(DListType *DL){
    DListNode *p;
    printf("size :%d\n", DL->size);
    for(p = DL->H->next ; p!= DL->T ; p=p->next)
        printf("[%c] <=> ", p->data);
    
    printf("\b\b\b\b \n");
}


int main(){
    DListType DL;
    init(&DL);

    inserFirst(&DL, 'A'); print(&DL);
    
    inserLast(&DL, 'B'); print(&DL);

    inserLast(&DL, 'C'); print(&DL);

    getchar();

    insertPosition(&DL, 'D', 4); print(&DL);

    getchar();

    printf(" %c is deleted. \n", deletePosition(&DL, 4)); print(&DL);

    return 0;
}

// 필기 + 실기시험, a4용지 지참가능, 실기때 기존에 pc에있는 백업된코드들 사용 불가. 75분
// 소스코드는 다 됬으면 실행이 되든 안되는 한글이나 워드에 붙여넣기. 텍스트로 복사 붙여넣기.
// 실행이 된 화면은 소스코드 캡쳐해서 보고서에 첨부
// 실행이 안되면 소스코드만이라도
// 리눅스는 소스코드는 텍스트로 하고 실행은 아예 이미지로 하던가
// 리브레오피스를 쓰던가
// pdf변환x
// 리눅스에서 국민대 워드