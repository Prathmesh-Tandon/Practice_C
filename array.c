#include <stdio.h>
#include <stdlib.h>

int num_element();
int* userarray(int n);

void decrement(int *array,int n);

void main (){
    int n1=num_element();
    int *arr1 = userarray(n1);
    printf("\nuser input array is:\n");
    for (int i = 0; i < n1; i++) {
        printf("%d ", arr1[i]);
    }
    printf("\n");
    decrement(arr1,n1);

    printf("\n");
    printf("size of user defined array is : %ld", sizeof(arr1));
    
    printf("\n");
    

    free(arr1);   // always free dynamic memory
}

void decrement(int *array,int n){
    printf("printing array elements after decrement it by 1: \n");
    for(int i = 0; i<n; i++){
        array[i]=array[i]-1;
        printf("%d ", array[i]);
    }
}

int num_element(){
    int n;
    printf("No of elements in array 1: ");
    scanf("%d", &n);
    return n;
}

int* userarray(int n) {
    // create array inside this function
    int *array = malloc(n * sizeof(int));

    if (array == NULL) {
        printf("Memory allocation failed!");
        return NULL;
    }

    for (int i = 0; i < n; i++) {
        printf("Enter number at index [%d]: ", i);
        scanf("%d", &array[i]);
    }

    // returning the final array pointer
    return array;
}