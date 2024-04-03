#include <stdio.h>

void swap (int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void selectionSort (int arr[], int length) {
    for (int i = 0; i < length-1; i++) {
        for (int j = i; j < length; j++) {
            if (arr[j] < arr[i]) {
                swap (&arr[j], &arr[i]);
            }
        }
    }
}

void binarySearch (int arr[], int key, int l, int r) {
    if (l <= r) {           // check why this is necessary
        int mid = (l + r) / 2;
        if (arr[mid] == key) {
            printf("Found\n");
            return;
        }
        if (key < arr[mid]) {
            binarySearch (arr, key, l, mid-1);
        }
        else {
            binarySearch (arr, key, mid+1, r);      // check how the limits of the search part is set
        }
    }
    else {
        printf("Not Found\n");
    }
}

int main () {
    int arr[] = {3, 2, 5, 6, 2, 1, 10, 9, 7, 3, 4, 2};
    int length = sizeof(arr) / sizeof(arr[0]);
    selectionSort(arr, length);
    binarySearch(arr, 5, 0, length-1);
}

// Ref : https://www.geeksforgeeks.org/binary-search/
