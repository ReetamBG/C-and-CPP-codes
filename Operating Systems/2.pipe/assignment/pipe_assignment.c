#include <stdio.h>
#include <unistd.h>
#define MAX 5

void display(int* arr,int size){
    for(int i=0; i<size; i++){
        printf("%d\t", arr[i]);
    }
    printf("\n");
}

int* sort(int* arr, int size){
    for(int i=0; i<size; i++){
        for(int j=0; j<size-1-i; j++){
            if(arr[j+1]<arr[j]){
                int temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
    return arr;
}

int main(){
    int pipe1[2], pipe2[2];
    pipe(pipe1);
    pipe(pipe2);
    int k = fork();
    if(k==0){
        int buffer2[MAX];
        read(pipe1[0], buffer2, MAX*sizeof(int));
        int* sorted_array = sort(buffer2, MAX);
        write(pipe2[1], sorted_array, MAX*sizeof(int));
    }
    else{
        int buffer1[MAX], sorted_array[MAX];
        printf("Enter the elements :\n");
        for(int i=0; i<MAX; i++){
            scanf("%d", &buffer1[i]);
        }
        write(pipe1[1], buffer1, MAX*sizeof(int));
        read(pipe2[0], sorted_array, MAX*sizeof(int));
        printf("In parent process\n");
        display(sorted_array, MAX);
    }
    return 0;
}