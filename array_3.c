#include "array_3.h"
#include<stdio.h>
void reverse(int *array, int low, int high){
    while (low<high) {
        int temp = array[high];
        array[high]=array[low];
        array[low]=temp;
        low++;
        high--;
    }
}

void Left_rotate_by_one(int * array, int n){
    int temp = array[0];
    for ( int i = 1 ; i<n ; i++ ){
        array[i-1]=array[i];
    }
    array[n-1]=temp;
}

void Left_rotate_by_d(int *arr, int n , int d){
    d = d%n;
    reverse(arr,0,d-1);
    reverse(arr,d,n-1);
    reverse(arr,0,n-1);
}