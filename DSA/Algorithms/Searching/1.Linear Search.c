#include <stdio.h>

void linearSearch (int arr[], int key, int length){
    for (int i = 0; i < length; i++) {
        if (arr[i] == key) {
            printf("Found\n");
            return;
        }
    }
    printf("Not Found\n");
}

int main(){
    int arr[] = {3, 2, 1, 5, 10, 9, 12, 3, 21, 17, 30, 23};
    int length = sizeof(arr) / sizeof(arr[0]);
    linearSearch(arr, 8, length);
}
