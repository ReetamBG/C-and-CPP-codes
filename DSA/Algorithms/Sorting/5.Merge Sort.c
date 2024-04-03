#include <stdio.h>

void merge(int arr[], int l, int mid, int r){
    int n1 = mid - l + 1;
    int n2 = r - mid;
    int a1[n1];
    int a2[n2];
    for(int i = 0; i < n1; i++){
        a1[i] = arr[l+i];
    }
    for(int i = 0; i < n2; i++){
        a2[i] = arr[mid + 1 +i];
    }

    int i = 0, j = 0;
    int k = l;
    while(i < n1 && j < n2){
        if(a1[i] < a2[j]){
            arr[k] = a1[i];
            i++;
        }
        else{
            arr[k] = a2[j];
            j++;
        }
        k++;
    }
    
    while(i < n1){
        arr[k] = a1[i];
        i++;
        k++;
    }
    while(j < n2){
        arr[k] = a2[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int l, int r){
    if(l < r){
        int mid = (l + r) / 2;
        mergeSort(arr, l, mid);
        mergeSort(arr, mid+1, r);
        merge(arr, l, mid, r);
    }
}

void display(int arr[], int length){
    printf("The array is : ");
    for(int i = 0; i < length; i++){
        printf("%d\t", arr[i]);
    }
    printf("\n");
}

int main(){
    int arr[10] = {3, 2, 1, 5, 8, 9, 1, 11, 3, 7};
    int length = sizeof(arr) / sizeof(arr[0]);
    display(arr, length);
    mergeSort(arr, 0, length-1);
    display(arr, length);
}

