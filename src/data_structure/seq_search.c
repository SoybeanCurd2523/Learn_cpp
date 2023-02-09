#include <stdio.h>
// 순차탐색

int seq_search(int list[], int key){
    int i;

    int n = 10;

    for(i=0 ; i< n ; i++)
        if(list[i] == key)
            return i;
    
    return -1;
}

int main(){
    int list[10] = {5, 9, 10, 17, 21, 29, 33, 37, 38, 43};
    int key = 5;
    int result;

    result = seq_search(list, key);
    printf("i : %d\n", result);

    return 0;
}