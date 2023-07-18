#include<stdio.h>

void swap(int *a, int *b){
    int temp;
    temp = *a ;
    *a = *b;
    *b = temp;
    printf("a=%d, b=%d", *a,*b);
}

void main(){
    int a, b;
    a=5;
    b=10;
    swap(&a, &b);
    printf("\n");
    printf("a=%d, b=%d", a,b);
}
