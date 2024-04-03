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

    int fifo1_fd = open(file1, O_RDWR);
    int fifo2_fd = open(file2, O_RDWR);

    while(1){
        read(fifo1_fd, buffer1, sizeof(buffer1));
        printf("Message Recieved : %s", buffer1);

        if(strcmp(buffer1, "end\n") == 0){
            break;
        }

        printf("Enter message ('end' t exit') : ");
        fgets(buffer2, sizeof(buffer2), stdin);
        write(fifo2_fd, buffer2, strlen(buffer2) + 1);

    }

    close(fifo1_fd);
    close(fifo2_fd);
}

