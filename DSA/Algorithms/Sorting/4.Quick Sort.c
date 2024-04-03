#include <stdio.h>

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int l, int r){
    int pivot = arr[r];
    int i = l - 1;
    for(int j = l; j < r ; j++){
        if(arr[j] < pivot){
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[r]);
    return i+1;
}

void quickSort(int arr[], int l, int r){
    if(l < r){
        int pi = partition(arr, l, r);
        quickSort(arr, l, pi-1);
        quickSort(arr, pi+1, r);
    }
}

void printArr(int arr[], int length){
    printf("The array is : ");
    for(int i = 0; i < length; i++){
        printf("%d\t", arr[i]);
    }
    printf("\n");
}

int main(){
    int arr[5] = {3, 1, 4, 2, 5};
    int length = sizeof(arr) / sizeof(arr[0]);
    printArr(arr, length-1);
    quickSort(arr, 0, length-1 );
    printArr(arr, length-1);
}
