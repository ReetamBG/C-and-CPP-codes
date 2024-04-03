#include <stdio.h>
#include <unistd.h>
#include <string.h>

int main(){
    int arr[2];
    pipe(arr);
    int k = fork();
    if(k == 0){
        char buffer[10];
        read(arr[0], buffer, 10);
        printf("%s", buffer);
    }
    else{
        char buffer[10] = "Hello\n";
        write(arr[1], buffer, strlen(buffer)+1);
    }
}