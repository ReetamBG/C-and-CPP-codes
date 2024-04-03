#include <stdio.h>
#include <string.h>

void swap (int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void selectionSort (int arr[], int length) {
    for (int i = 0; i < length-1; i++) {
        for (int j = i; j < length; j++) {
            if (arr[j] < arr[i]) {
                swap (&arr[j], &arr[i]);         // Smallest element of the unsorted array is taken to the first index of the unsorted array and the unsorted array becomes smaller on each iteration
            }
        }
    }
}

void printArr (int arr[], int length) {
    printf("The array is : ");
    for (int i = 0; i < length; i++) {
        printf ("%d\t", arr[i]);
    }
    printf ("\n");
}

void main(){
    int arr[5] = {3, 1, 4, 2, 5};
    int length = sizeof(arr) / sizeof(arr[0]);
    printArr(arr, length);
    selectionSort(arr, length);
    printArr(arr, length);
}

// Ref : https://www.youtube.com/watch?v=dQa4A2Z0_Ro