// read

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

int main(){
    const char *ch = "./myfifo7048";
    int n;
    char buf[10];
    n = open(ch, O_RDONLY);
    if(n == -1){
        printf("Could not open file\n");
    }
    else{
        read(n, buf, 10);
        printf("%s", buf);
    }
    return 0;
}
    