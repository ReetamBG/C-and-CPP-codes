#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

int main(){
    char buffer1[100];
    char buffer2[100];
    char *file1 = "./file1";
    char *file2 = "./file2";

    int fifo1_status = mkfifo(file1, 0666);
    int fifo2_status = mkfifo(file2, 0666);

    int fifo1_fd = open(file1, O_RDWR);
    int fifo2_fd = open(file2, O_RDWR);

    while(1){
        printf("Enter message ('end' t exit') : ");
        fgets(buffer1, sizeof(buffer1), stdin);
        write(fifo1_fd, buffer1, strlen(buffer1) + 1);

        if(strcmp(buffer1, "end\n") == 0){
            break;
        }

        read(fifo2_fd, buffer2, sizeof(buffer2));
        printf("Message Recieved : %s", buffer2);
    }

    close(fifo1_fd);
    close(fifo2_fd);

    unlink(file1);
    unlink(file2);
}

