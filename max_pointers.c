#include <stdio.h>

int findMax(int *arr, int size) {
    // TODO: Write the logic to find the maximum value in the array using pointers
    // Initialize a pointer to the first element of the array
    // Traverse through the array using the pointer, compare each element with the current maximum
    // Update the maximum if a greater element is found
    // Return the maximum value
    int *temp = arr ;
    int i=0;
    for(i=1;i<size;i++){
        if(*temp < *(arr+i)){
            *temp = *(arr+i);
            
        }
            
    }
    
    return *temp;
}

int main() {
    int size;

    printf("Enter the size of the array: ");
    scanf("%d", &size);

    int arr[size];

    printf("Enter the elements of the array:\n");
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    int max = findMax(arr, size);
    printf("The maximum value in the array is: %d\n", max);

    return 0;
}
