#include <stdio.h>
#include <unistd.h>

int main(){
    int pipe1[2], pipe2[2];
    pipe(pipe1);
    pipe(pipe2);

    int k = fork();

    if(k == 0){
        int arr[3];
        read(pipe1[0], arr, 3*sizeof(int));
        for(int i=0; i<3; i++){
            for(int j=i; j<3-i-1; j++){
                if(arr[j] > arr[j+1]){
                    int temp = arr[j];
                    arr[j] = arr[j+1];
                    arr[j+1] = temp;
                }
            }
        }
        write(pipe2[1], arr, 3*sizeof(int));
    }
    else{
        int arr[3];
        for(int i=0; i<3; i++){
            scanf("%d", arr+i);
        }
        write(pipe1[1], arr, 3*sizeof(int));
        read(pipe2[0], arr, 3*sizeof(int));
        for(int i=0; i<3; i++){
            printf("%d\n", *(arr+i));
        }
    }
}