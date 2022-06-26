// 1
// 짝수면 0, 홀수면 1 반환
#include <stdio.h>
// #include <string.h>

// int parity(int n){
//     if(n%2 == 0) return 0;
//     return 1;
// }
// int main(){
//     printf("%d\n", parity(5));
//     printf("%d\n", parity(-3));
//     printf("%d\n", parity(6));
// }



// 3
// 다음 프로그램의 실행 결과는?
// void rec(int n){
//     if(n==0) return;
//     printf("%d", n);
//     rec(n-1);
//     printf("%d",n);
// }
// int main(){
//     rec(5);
// }



// 4
// 문자열을 매개변수로 받아 그 문자열에서 
// 공백을 제거하여 출력하는 함수를 작성해보세요.

void print_noSpace(char *str){  // str[]

    for(int i=0 ; str[i] != '\0' ; i++){
        if(str[i] != ' ')
            printf("%c", str[i]);
    }
    
}

int main(){
    print_noSpace("Hello, World!\n");
    print_noSpace("My name is Doodle\n");

    // char arr[] = "abcd efg";
    // printf("%d\n", sizeof(arr));

}