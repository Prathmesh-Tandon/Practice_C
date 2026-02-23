#include "array_2.h"
#include<stdio.h>

int largest(int *arr, int n){
    int largest = 0;
    for (int i = 0 ; i<n ; i++){
        if(arr[i]>largest){
            largest = arr[i];
        }
    }
    return largest;
}

void swap_arrays(int *arr1, int *arr2, int n1, int n2){
    int len = n1<n2?n1:n2;

    for(int i = 0 ; i<len ; i++){
        int temp = arr1[i];
        arr1[i]=arr2[i];
        arr2[i]=temp;
    }
}
void swap_entire_arrays(int **arr1, int **arr2, int *n1, int *n2) {
    int *temp_ptr = *arr1;
    *arr1 = *arr2;
    *arr2 = temp_ptr;

    int temp_size = *n1;
    *n1 = *n2;
    *n2 = temp_size;
}

void display_array( int *array, int n){
    for ( int i = 0 ; i<n ; i++){
        printf("%3d ", array[i]);
    }
    printf("\n");
}