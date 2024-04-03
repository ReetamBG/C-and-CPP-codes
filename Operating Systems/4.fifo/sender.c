// mkfifoat
// mkfifo
// open
// write

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

int main(){
    const char *ch = "./myfifo7048";
    char buf[10];
    int n, m;
    n = mkfifo(ch, 0666);   // IPC_CREAT | 0666
    if(n == -1){
        printf("mkfifo not initialised\n");
    }
    else{
        m = open(ch, O_WRONLY);
        if(m != -1){
            scanf("%s", buf);
            write(m, buf, 6);
        }
    }
    return 0;
}
    