// 구조체 포인터

#include <stdio.h>

struct ProductInfo{
  int num; 
  char name[100];
  int cost; 
}; 

/*
ProductInfo *p;
p = &myProduct;
*/
void productSale(ProductInfo *p, int percent){ 
    p->cost -= p->cost * percent / 100;
}

void productSwap(ProductInfo *a, ProductInfo *b){ //call-by-reference
    ProductInfo tmp = *a;
    *a = *b;
    *b = tmp;
}


int main(){
    ProductInfo myProduct = { 4797283, "제주 한라봉", 20000 };
    /*
    ProductInfo myProduct;
    myProduct.num = 4797283;
    myProduct.name = "제주 한라봉";
    myProduct.cost = 19900;
    */

    ProductInfo otherProduct = { 4797284, "성주 꿀참외", 10000 };

    productSwap(&myProduct, &otherProduct);



    ProductInfo *ptr_product = &myProduct;  // 구조체 포인터

    // productSale(&myProduct, 10);

    // printf("%d, %s, %d\n", (*ptr_product).num, (*ptr_product).name, (*ptr_product).cost);  // *ptr_product 는 myProduct 와 같다.

    printf("%d, %s, %d\n", ptr_product->num, ptr_product->name, ptr_product->cost);

    // (*a).b == a->b 이다.
    
}