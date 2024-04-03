#include <stdio.h>
#include <sys/msg.h>

struct msgbuf{
    long mtype;
    char mtext[20];
};

int main(){
    struct msgbuf msg;
    int n = msgget(123456, 0666|IPC_CREAT);
    if(n == -1){
        printf("Error\n");
    }
    else{
        msgrcv(n, &msg, 20, 1, 0);
    }
    printf("%s", msg.mtext);
}