// pipe
// write
// read

#include <stdio.h>
#include <unistd.h>

int main(){
    int arr[2];
    int n = pipe(arr);
    int k = fork();
    if(k==0){
        char buffer2[10];
        read(arr[0], buffer2, 10);
        printf("%s", buffer2);
    }
    else{
        char buffer1[10]="Hello\n";
        write(arr[1], buffer1, 7);          // 7 bytes (1 byte extra for the null character) 
        // Or we can do strlen(buffer)+1
    }
    return 0;
}