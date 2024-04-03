#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

int main(){
    char *ch = "./fifo";
    int n = mkfifo(ch, 0666);
    char buf[10];
    if(n == -1){
        printf("Could not create fifo\n");
    }
    else{
        int m = open(ch, O_WRONLY);
        if(m == -1){
            printf("File could not be opened");
        }
        else{
            printf("Enter the data : ");
            fgets(buf, 10, stdin);
            write(m, buf, 10);
            printf("Data recieved\n");
        }
    }
    system("rm fifo");
}
