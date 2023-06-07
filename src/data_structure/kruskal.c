#include <stdio.h>
#include <stdlib.h> // qsort() 함수를 사용하기 위해 필요

int compare(const void * a, const void * b) { // 오름 차순으로 정렬하라고 qsort에 알려줌
    return ( *(int*)a - *(int*)b );
}

int main() {
    int numbers[] = {4, 2, 9, 6, 1, 3};
    int n = sizeof(numbers) / sizeof(numbers[0]);

    qsort(numbers, n, sizeof(int), compare);
// numbers : 배열의 이름은 첫 번째 원소의 주소이다.

    // 이제 numbers 배열은 {1, 2, 3, 4, 6, 9}로 정렬되어 있습니다.

    for(int i=0 ; i<n ; i++)
        printf("%d ", numbers[i]);

    printf("\n\n\n");
    return 0;
}
