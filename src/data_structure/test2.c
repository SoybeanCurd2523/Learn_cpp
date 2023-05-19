#include <stdio.h>
#include <string.h> //strlen, strcpy, strcat, strcmp

int main(){
    // char str[]="hello";
    // char str2[100];
    // // sizeof(str)/sizeof(char)-1 // 문자열 끝에 있는 null문자고려
    // int len;
    // len = strlen(str);

    // printf("%d\n", len);

    // strcpy(str2, str);
    // printf("str2 : %s\n", str2);

    // strcat(str, "world");
    // printf("str : %s\n", str);

///////////////////

    // char str1[]="sample";
    // char str2[]="simple";
    // int cmp = strcmp(str1, str2); // str1이 사전순으로 앞 : -1 반환, 뒤 : 1, 같다:0 반환 ?
    // printf("%d\n", cmp);

//////////////////////

    // int a=20;
    // char c='h';
    // int *ptr_a; //포인터 : 변수의 주소를 저장하는 변수
    // char *ptr_c;

    // ptr_a = &a;

    // printf("%d\n", a);
    // printf("%d\n", &a);
    // printf("%d\n", ptr_a);
    // printf("%d\n", *ptr_a);

////////////////

    // int a=10;
    // int arr[3]={1,2,3};
    // int (*ptr_arr)[3]; // 길이 3인 int형 배열을 가르키는 포인터를 선언. 배열 포인터
    // ptr_arr = &arr;

    // for(int i=0 ; i<3 ; i++){
    //     printf("(*ptr_arr)[%d] : %d\n", i, (*ptr_arr)[i]);
    // }
    // printf("a:%d\n",a);
    // int *ptr=&a;
    // printf("ptr:%d\n",ptr);

    // *ptr=20;
    // printf("a:%d\n", a);
    // printf("ptr:%d\n",ptr); // a의 주솟값은 바뀌지 않음.

/////////////////////

    // int arr[10]={1,2,3,4,5,6,7,8,9,10};

    // printf("arr:%d\n", arr);  // arr = &arr[0]이다.
    // printf("arr+3:%d\n", arr+3); //arr+1 = &arr[0]+1 = &arr[1]

    // for(int i=0 ; i<10 ; i++){
    //     printf("&arr[%d]=%d\n", i, &arr[i]);
    // }

/////////////

    // int arr[10]={1,2,3,4,5,6,7,8,9,10};
    // for(int i=0; i<10; i++){
    //     printf("%d ", arr[i]);
    // }
    // printf("\n");
    // for(int i=0; i<10; i++){
    //     printf("%d ", *(arr+i));// arr+i = &arr[i]이다. 즉, *(arr+i) = *(&arr[i]) = arr[i]
    // }
    // printf("\n");
    // for(int *ptr=arr; ptr<arr+10; ptr++){
    //     printf("%d ", *ptr);
    // }

///////////////////

    int arr[3] =  {1,2,3};
    printf("arr:%d\n", arr);
    printf("arr+1:%d\n", arr+1);

    printf("&arr:%d\n", &arr);
    printf("&arr+1:%d\n", &arr + 1);

////////////////

    // int arr[3]={1,2,3};
    // int (*ptr_arr)[3]; // 길이 3인 int형 배열을 가르키는 포인터를 선언. 배열 포인터
    // ptr_arr = &arr;

    // for(int i=0 ; i<3 ; i++){
    //     printf("%d\n", (*ptr_arr)[i]);
    // }

/////////////////

}