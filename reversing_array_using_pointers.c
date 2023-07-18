#include<stdio.h>

void reverse(int *arr, int n){
    int *temp = arr+(n-1);
    int i=0;

    for(i=0;i<n;i++)
        printf("%d ", *(temp-i));

}

void main(){
    int arr[] = {1,2,3};
    int num = sizeof(arr)/sizeof(*arr);
    reverse(arr, num);

    
    printf("\n");
    
    int array[] = {1,2,3,4,5,6};
    num = sizeof(array)/sizeof(*array);
    reverse(array, num);

    
}

