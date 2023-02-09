// typedef
// int는 32비트, 4바이트 형 자료형
#include <stdio.h>

// int main(){
//     typedef int Int32;
//     Int32 n = 20;

//     printf("%d\n", n);

//     printf("%d\n", sizeof(Int32));
// }



// int main(){
//     typedef int Pair[2];
//     Pair point = {3, 4}; // int point[2] = {3, 4};

//     printf("(%d, %d)\n", point[0], point[1]);
// }



int main(){
    typedef char *String;

    String name = "Doodle"; //char *name = "Doodle";
    
    printf("이름 : %s\n", name);
}