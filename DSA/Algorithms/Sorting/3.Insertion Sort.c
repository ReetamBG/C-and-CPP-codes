#include <stdio.h>
#include <string.h>

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void insertionSort(int arr[], int length){
    for(int i = 1; i < length-1; i++){
        int current = arr[i];
        int j = i - 1;
        while(arr[j] > current && j >= 0){      // Each element is inserted one by one into the sorted array in correct position 
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = current;
    }
}

void printArr(int arr[], int length){
    printf("The array is : ");
    for(int i = 0; i < length; i++){
        printf("%d\t", arr[i]);
    }
    printf("\n");
}

void main(){
    int arr[5] = {3, 1, 4, 2, 5};
    int length = sizeof(arr) / sizeof(arr[0]);
    printArr(arr, length);
    insertionSort(arr, length);
    printArr(arr, length);
}

// Ref : https://www.youtube.com/watch?v=xcPFUCh0jT0