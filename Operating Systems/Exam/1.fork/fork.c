#include <stdio.h>
#include <unistd.h>

int main(){
    int n = fork();
    if(n == 0){
        printf("CHILD\n");
        printf("%d\n", getpid());
        printf("%d\n", getppid());
    }
    else{
        sleep(1);
        printf("PARENT\n");
        printf("%d\n", getpid());
        printf("%d\n", getppid());
    }
    return 0;
}