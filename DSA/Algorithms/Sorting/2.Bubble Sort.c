#include <stdio.h>
#include <string.h>

void swap (int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void bubbleSort (int arr[], int length) {
    for (int i = 0; i < length-1; i++) {
        for (int j = i; j < length-1-i; j++) {
             // length - 1 - i cuz on every iteration the biggest element gets placed in the last in order so that can be excluded from comparing
            if (arr[j+1] < arr[j]) {
                swap (&arr[j], &arr[j+1]);      
                // Compares adjacent elements and swaps till all are sorted
            }
        }
    }
}

void printArr (int arr[], int length) {
    printf("The array is : ");
    for (int i = 0; i < length; i++) {
        printf("%d\t", arr[i]);
    }
    printf("\n");
}

void main(){
    int arr[5] = {3, 1, 4, 2, 5};
    int length = sizeof(arr) / sizeof(arr[0]);
    printArr(arr, length);
    bubbleSort(arr, length);
    printArr(arr, length);
}

// Ref : https://www.youtube.com/watch?v=xcPFUCh0jT0