#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

int main(){
    char *ch = "./fifo";
    int m = open(ch, O_RDONLY);
    char buf[10];
    read(m, buf, 10);
    printf("%s", buf);
}
    