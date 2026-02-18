#include <stdio.h>
#include <stdlib.h>
#include<stdbool.h>

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
    decrement(arr1,n1);

    printf("\n");
    int x;
    printf("enter a number to search in array: ");
    scanf("%d", &x);
    search(arr1,n1,x);
    
    printf("\n");
    sorted(arr1,n1);

    printf("\n");
    int No_of_Distinct = distinct(arr1,n1);
    printf("No of distinct element in array 1 is : %d", No_of_Distinct);

    printf("\n");

    free(arr1);   // always free dynamic memory
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
            printf("number found at index %d", i);
            return i;
        }
    }
    printf("Number not found\n");
    return -1;
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
    printf("\nsize of user defined array is : %ld", n*sizeof(int) );
    // returning the final array pointer
    return array;
}