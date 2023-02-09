// 구조체와 메모리

#include <stdio.h>

struct ProductInfo{
  int num; // 4바이트
  char name[100]; // 1바이트*100개 = 100바이트
  int cost;  // 4바이트
}; // 108바이트


int main(){
    ProductInfo myProduct = {4797283, "제주 한라봉", 19900};
    /*

    ProductInfo myProduct;
    myProduct.num = 4797283;
    myProduct.name = "제주 한라봉";
    myProduct.cost = 19900;

    */

    printf("%d, %s, %d\n", myProduct.num, myProduct.name, myProduct.cost);
    printf("%d\n", sizeof(myProduct));

    printf("%d, %d, %d, %d\n", &myProduct, &myProduct.num, &myProduct.name, &myProduct.cost); // -10240, -10240, -10236, -10136
}