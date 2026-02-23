#include <stdio.h>
#include <stdlib.h>
#include<stdbool.h>
#include "array_2.h"

int num_element();
int* userarray(int n);
void decrement(int *array,int n);
int search(int arr[], int n, int x);
bool sorted(int *arr, int n);
int distinct(int *arr, int n);

int main (){
    printf("\n");
    int n1=num_element();

    printf("\n");
    int *arr1 = userarray(n1);

    printf("\nTraversal through user input array :\n");
    for (int i = 0; i < n1; i++) {
        printf("%d ", arr1[i]);
    }

    printf("\n");
    printf("reverse Traversal through user input array :\n");
    for (int i = n1-1; i >=0; i--) {
        printf("%d ", arr1[i]);
    }

    printf("\n");
    int x;
    printf("enter a number to search in array: ");
    scanf("%d", &x);
    search(arr1,n1,x);
    
    printf("\n");
    sorted(arr1,n1);

    printf("\n");
    printf("\nNo of distinct element in array 1 is : %d\n", distinct(arr1,n1));

    printf("\n");
    printf("Largest element: %d\n", largest(arr1, n1));

    printf("\n");
    decrement(arr1,n1);

    printf("\n");
    printf("\nPrepare array 2\n");
    int n2=num_element();
    int *arr2 = userarray(n2);
    printf("before swap :\n");
    display_array(arr1,n1);
    display_array(arr2,n2);
    printf("after swap entire arrays :\n");
    swap_entire_arrays(&arr1, &arr2, &n1, &n2);
    display_array(arr1,n1);
    display_array(arr2,n2);
    swap_arrays(arr1, arr2, n1,n2);
    printf("Now swap only elements :\n");
    display_array(arr1,n1);
    display_array(arr2,n2);




    printf("\n");
    free(arr1);  // always free dynamic memory
    free(arr2);
    return 0;
}

int distinct(int *arr, int n){
    int count=1;
    int i,j;
    for(i=1;i<n;i++){
        for (j = 0 ; j<i ; j++){
            if (arr[j]==arr[i]){
                break;
            }
        }
        if (i==j){
            count++;
        }
    }
    return count;
}

bool sorted(int *arr, int n){
    for (int i = 1 ; i<n ; i++){
        if (arr[i-1]>arr[i]){
            printf("Array is not sorted\n");
            return false;
        }
    }
    printf("Array is sorted\n");
    return true;
}

int search(int *arr, int n, int x){
    for(int i = 0;i<n;i++){
        if (arr[i]==x){
            printf("\nnumber found at index %d", i);
            return i;
        }
    }
    printf("\nNumber not found");
    return -1;
}

void decrement(int *array,int n){
    printf("printing array elements before decrement: \n");
    for(int i = 0; i<n; i++){
        printf("%d ", array[i]);
    }

    printf("\nprinting array elements after decrement it by 1: \n");
    int *copy = malloc(n * sizeof(int));
    for (int a = 0 ; a<n; a++){
        copy[a]=array[a]-1;
        printf("%d ", copy[a]);
    }
    free(copy);
}

int num_element(){
    int n;
    printf("No of elements in array: ");
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
    printf("\nsize of user defined array is : 4bytes * %d = %ld\n",n, n*sizeof(int) );
    // returning the final array pointer
    return array;
}